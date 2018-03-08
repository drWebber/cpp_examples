#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbnStartRegular_clicked()
{
    rc = new RegularClass();
    thread = new QThread(this);
    rc->moveToThread(thread);

    /* НЕВЕРНЫЙ ПУТЬ:
       connect(thread, SIGNAL(finished()),
            this, SLOT(on_regularClass_finished());
       НЕ СРАБОТАЕТ, т.к.:
       https://stackoverflow.com/questions/13460096/why-is-qthreadfinished-
                signal-not-being-emitted
       By the time finished() is emitted, _thread's event loop already
       finished executing, so signal will not be delivered to the slot */

    /* ВЕРНЫЙ ПУТЬ: */
    /* сначала сигнал потока thread started() должен вызвать нужный слот
       подопытного класса rc */
    connect(thread, SIGNAL(started()), rc, SLOT(goooo()));
    /* в вызванном слоте подопытного класса после выполнения кода должен
       испуститься сигнал finished (можно назвать иначе), далее связываем этот
       сигнал со слотом quit потока */
    connect(rc, SIGNAL(finished()), thread, SLOT(quit()));
    /* и только потом можно связать сигнал потока finished с нужным слотом */
    connect(thread, SIGNAL(finished()), this, SLOT(on_regularClass_finished()));

    thread->start();
}

void MainWindow::on_regularClass_finished()
{
    qDebug() << "regulars class thread finished";
}

void MainWindow::createThread()
{
    QThread *th = new QThread(this);
    Bar *bar = new Bar(jobs);

    threads.insert(jobs, th);

    bar->moveToThread(th);

    connect(th, SIGNAL(started()), bar, SLOT(process()));
    connect(bar, SIGNAL(finished(int)),
            this, SLOT(on_barProcess_finished(int)));

    th->start();
}

void MainWindow::on_pbnCreateThread_clicked()
{
    Foo *foo = new Foo(fooList.count(), this);
    fooList.append(foo);

    foo->start();
}

void MainWindow::on_pbnTerminateLast_clicked()
{
    int count = fooList.count() - 1;
    if (count >= 0) {
        Foo *foo = fooList[count];

        foo->terminate();

        fooList.removeLast();

        delete foo;
    }
}

void MainWindow::on_barProcess_finished(int num)
{
    --jobs;

    qDebug() << "bar #" << num << "is processed";

    threads.value(num)->quit();
    threads.remove(num);

    if (jobs > 0) {
        createThread();
    }
}

void MainWindow::on_pbnGroup_clicked()
{
    jobs = 100;
    /* ОБРАБОТКА ПАЧКИ ЗАДАЧ по THREADS_COUNT одновременно */
    const int THREADS_COUNT = 3;
    for (int i = 0; i < THREADS_COUNT; ++i) {
        createThread();
        --jobs;
    }
}

void MainWindow::on_pbnTerminateGroup_clicked()
{
    jobs = 0;
    foreach (QThread *th, threads) {
        th->quit();
    }
}
