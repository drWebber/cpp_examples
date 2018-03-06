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
