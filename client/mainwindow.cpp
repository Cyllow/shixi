#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);

    tcpsocket=NULL;
    tcpsocket=new QTcpSocket(this);
    tcpsocket->connectToHost(QHostAddress("192.168.46.94"),6000);

    setWindowTitle("client");

    connect(tcpsocket,SIGNAL(connected()),this,SLOT(connectSuccess()));
    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(readMsg()));
    connect(tcpsocket,SIGNAL(disconnected()),this,SLOT(connectcrash()));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(start()));

    connect(this,SIGNAL(startread()),this,SLOT(getpicbuff()));
    connect(this,SIGNAL(send(unsigned char*)),this,SLOT(sendMsg(unsigned char*)));
    connect(this,SIGNAL(picready(QString)),this,SLOT(showpic(QString)));

    image = new QImage("/home/topeet/cyllow/1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(*image));

    pic_buffer = new unsigned char[640*480*2];

    camera = new Camera("/dev/video4", 640, 480, 1);
    if(!camera->OpenDevice())
    {
        printf("打开摄像头失败！\n");
        return ;
    }

    flag = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete image;
    delete[] pic_buffer;
    delete camera;
}


void MainWindow::start()
{
    QString str = ui->pushButton->text();

    if(str == "start")
    {
        ui->pushButton->setText("stop");
        flag = 1;
        qDebug() << "start collect!\n";
    }
    else
    {
         ui->pushButton->setText("start");
         ui->pushButton_2->setEnabled(true);
         flag = 0;
         qDebug() << "stop collect!\n";
    }

    emit startread();



}

void MainWindow::showpic(QString path)
{
    //image->load("/home/topeet/cyllow/3.jpg");
    image->load(path);
    ui->label->setPixmap(QPixmap::fromImage(*image));
    qDebug() << "show new pic!\n";
}

void MainWindow::sendMsg(unsigned char *buf)
{
    char *temp = (char *)buf;
    //QString str = QString(QLatin1String(temp));
    //qDebug()<<"pic size is "<<str.size();
    qint32 writesize=tcpsocket->write(temp,640*480*2);
    //tcpsocket->writeData(temp,640*480*2);
    //qDebug()<<writesize;

     qDebug()<<writesize;
     qDebug()<<"send finish";
}

void MainWindow::readMsg()
{
    localfile=new QFile("/home/topeet/cyllow/3.jpg");

    if(!localfile->open(QFile::WriteOnly))
    {
        qDebug()<<"open file failed";
        return;
    }

    QByteArray headarr=tcpsocket->read(4);
    qDebug()<<headarr;

    qint64 filesize=headarr.toInt();
    QByteArray array;
    while(1)
    {
        if(filesize==0)
        {
            break;
        }
        array=tcpsocket->readAll();
        localfile->write(array);
        filesize=filesize-array.size();
    }

    localfile->close();

    emit picready("/home/topeet/cyllow/3.jpg");
}

void MainWindow::getpicbuff()
{
    while(flag)
    {
        qDebug() << "get pic_buffer!\n";
        camera->GetBuffer(pic_buffer);

        emit send(pic_buffer);

        qDebug() << "sleep 50ms!\n";
        //usleep(50*1000);
        sleep(15);
       // sleep(1000);

    }
}






