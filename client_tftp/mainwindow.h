#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QTcpSocket>
#include "mythread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage *image;
    mythread *threada;

signals:
    void startcollect();

public slots:
    void pushButtonClick();
    void slot_showpic();
    void replay();
};

#endif // MAINWINDOW_H
