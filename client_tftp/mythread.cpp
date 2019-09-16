#include "mythread.h"

mythread::mythread(QObject *parent) :
    QThread(parent)
{
    pic_buffer = new unsigned char[640*480*2];

    camera = new Camera("/dev/video4", 640, 480, 1);
    if(!camera->OpenDevice())
    {
        qDebug() << "打开摄像头失败！\n";
        return;
    }
}

mythread::~mythread()
{
    delete[] pic_buffer;
    delete camera;
}


void mythread::run()
{
    while(1)
    {
        camera->GetBuffer(pic_buffer);
        camera->GetBuffer(pic_buffer);
        camera->GetBuffer(pic_buffer);
        camera->GetBuffer(pic_buffer);
        camera->GetBuffer(pic_buffer);
        qDebug() << "get new camera picture!\n";

        QFile *file = new QFile("out.yuv");
        if(!file->open(QFile::WriteOnly))
        {
            qDebug()<<"open file failed!\n";
            return;
        }
        QByteArray buffer = QByteArray::QByteArray((char*)pic_buffer);
        qint32 writenum = file->write(buffer);
        qDebug() << "writenum:" << writenum << endl;
        file->flush();
        file->close();
        delete file;

        system("tftp -p -r out.yuv -l out.yuv 192.168.46.94");
        qDebug() << "push new out.yuv to server!\n";
        system("tftp -p -r a.txt -l a.txt 192.168.46.94");
        qDebug() << "push a.txt to server!\n";

        qDebug() << "The client sleeps for a while!\n";
        //usleep(1000 * 1000);
        msleep(650);
        //sleep(1);

        system("tftp -g -l 1.jpg -r 1.jpg 192.168.46.94");
        qDebug() << "get new JPG from server!\n";

        emit signal_showpic();
    }
}
