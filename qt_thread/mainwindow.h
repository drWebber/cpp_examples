#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "foo.h"
#include "bar.h"
#include "regularclass.h"

#include <QMainWindow>
#include <qdebug.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT        
private:
    Ui::MainWindow *ui;
    QList<Foo *> fooList;
    RegularClass *rc;
    QThread *thread;
    QMap<int, QThread *> threads;
    int jobs;
private:
    void createThread();
private slots:
    void on_pbnCreateThread_clicked();
    void on_pbnTerminateLast_clicked();
    void on_regularClass_finished();
    void on_pbnStartRegular_clicked();
    void on_barProcess_finished(int num);
    void on_pbnGroup_clicked();

    void on_pbnTerminateGroup_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
