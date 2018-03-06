#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "foo.h"

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
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbnCreateThread_clicked();
    void on_pbnTerminateLast_clicked();
};

#endif // MAINWINDOW_H
