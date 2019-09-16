#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);

    setWindowTitle("client");

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(pushButtonClick()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(replay()));

    QTcpSocket *client=new QTcpSocket(this);
    client->connectToHost("192.168.46.94",6000);

    image = new QImage("/home/topeet/cyllow/1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(*image));

    threada = new mythread(this);
    connect(threada,SIGNAL(signal_showpic()),this,SLOT(slot_showpic()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete image;

}

void MainWindow::pushButtonClick()
{
    QString str = ui->pushButton->text();
    if(str == "start")
    {
        ui->pushButton_2->setEnabled(false);

        ui->pushButton->setText("stop");
        qDebug() << "start collect!\n";

        threada->start();
    }
    else
    {
         ui->pushButton->setText("start");
         ui->pushButton_2->setEnabled(true);

         qDebug() << "stop collect!\n";
         threada->terminate();
    }
}

void MainWindow::slot_showpic()
{
    image->load("/home/topeet/cyllow/1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(*image));
    qDebug() << "show new pic!\n";
    MainWindow::show();
}

void MainWindow::replay()
{
    qDebug() << "replay!\n";
}











