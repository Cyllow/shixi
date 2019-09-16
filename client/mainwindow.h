#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QtNetwork>
#include <QTcpSocket>
#include <unistd.h>
#include "camera.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void picready(QString path);
    void startread();
    void send(unsigned char* buf);
    void startthread(QTcpSocket* clent,QString str);
public slots:
    void readMsg();
    //void connectcrash();

    void sendMsg(unsigned char* buf);
    //void closeConnect();

private:
    Ui::MainWindow *ui;
    QImage *image;
    unsigned char *pic_buffer;
    Camera *camera;
    QTcpSocket *tcpsocket;
    QFile *localfile;
    volatile bool flag;

private slots:
    void start();
    void showpic(QString path);
    void getpicbuff();

};

#endif // MAINWINDOW_H

