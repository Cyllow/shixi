#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setEnabled(false);

    if (!faceCascade.load("/home/cyllow/server1.0/haarcascade_frontalface_alt2.xml") ) {
          cout << "xmlface open error ！！" << endl;

    }
     if (!eyes_Cascade.load("/home/cyllow/server1.0/haarcascade_eye_tree_eyeglasses.xml")) {
          cout << "xmleye open error ！！" << endl;

     }

    loadSize=4*1024;
    totalBytes=0;
    bytesSize=0;
    fileNameSize=0;
    picBytes=0;

    setWindowTitle("server");

    server=new QTcpServer(this);
    server->listen(QHostAddress::Any,6000);
    qDebug()<<"start listen";

    connect(server,SIGNAL(newConnection()),this,SLOT(acceptClient()));

}

MainWindow::~MainWindow()
{
    delete ui;

    if(NULL==clientsocket)
    {
        return ;
    }

    clientsocket->disconnectFromHost();
    clientsocket->close();
    clientsocket=NULL;
}


void MainWindow::acceptClient()
{
    clientsocket=server->nextPendingConnection();

    QString ip=clientsocket->peerAddress().toString();
    qint16 port=clientsocket->peerPort();

    connect(clientsocket,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(clientsocket,SIGNAL(disconnected()),clientsocket,SLOT(deleteLater()));
    connect(this,SIGNAL(readyToSend()),this,SLOT(updatePic()));

    QString temp=QString(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"\n"+"[%1:%2]:is connected").arg(ip).arg(port);
    ui->textEdit->append(temp);

}

void MainWindow::readData()
{
    picBytes=640*480*2;
    qDebug()<<"start read";
    QByteArray array=clientsocket->readAll();
    ui->textEdit->append(QString(array));


    /*if(clientsocket->bytesAvailable()<picBytes*sizeof(unsigned char))
    {
        return;
    }

    while(1)
    {
        if(picBytes==array.size())
        {
            break;
        }
        array.append(clientsocket->readAll());
        qDebug()<<array.size();
    }

    if(!ex("/home/cyllow/server1.0/1.jpg",(unsigned char*)array.data()))
    {
        emit readyPic("/home/cyllow/server1.0/1.jpg");
    }

    picdiscern("/home/cyllow/server1.0/1.jpg","/home/cyllow/server1.0/2.jpg");

    openFile("/home/cyllow/server1.0/2.jpg");*/

    return;
}

void MainWindow::openFile(QString name)
{
    localFile=new QFile(name);
    fileName=localFile->fileName();
    if(localFile->open(QFile::ReadOnly))
    {
        emit readyToSend();
    }
    else
    {
        qDebug()<<"cannot openfile";
        return;
    }
}


void MainWindow::updatePic()
{
    qDebug()<<"start send";

    QString set_char="qidalaoNB";
    qDebug()<<set_char;

    bytesSize=totalBytes=localFile->size();
    QString filecount=QString(bytesSize);

    clientsocket->write(filecount.toUtf8().data());

    while(1)
    {
        if(bytesSize<=0)
        {
            break;
        }
        inBlock=localFile->read(qMin(bytesSize,loadSize));

        bytesSize=totalBytes-clientsocket->write(inBlock);

    }

    totalBytes=0;
    bytesSize=0;
    localFile->close();
    qDebug()<<"send file success";

}

int MainWindow::ex(string id,unsigned char *data){

    Mat image = Mat(480, 640,CV_8UC2,data);
    Mat yuvSource;
    Mat dst = Mat::zeros(272, 363, CV_8UC3);
    cvtColor(image,yuvSource,CV_YUV2RGB_YUYV);

    cv::resize(yuvSource,dst,dst.size());


    imwrite(id,dst);
    waitKey(0);
    return 0;

}

int MainWindow::picdiscern(string jpg_in,string jpg_out)
{


    Mat img, imgGray;

    img=imread(jpg_in,1);

    cvtColor(img, imgGray, CV_BGR2GRAY);
    equalizeHist(imgGray, imgGray);//

    DetectFace(img, imgGray,jpg_out);

    return 0;
}


void MainWindow::DetectFace(Mat img,Mat imgGray,string jpg_out)
{

    vector<Rect> faces, eyes;

    faceCascade.detectMultiScale(imgGray, faces, 1.2, 5, 0, Size(30, 30));

    if (faces.size()>0) {

        for (size_t i = 0; i<faces.size(); i++) {
            //putText(img, "", cvPoint(faces[i].x, faces[i].y - 10),FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));

            rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 5, 8);
           //cout << faces[i] << endl;


            Mat face_ = imgGray(faces[i]);
            eyes_Cascade.detectMultiScale(face_, eyes, 1.2, 2, 0, Size(30, 30));
            for (size_t j = 0; j < eyes.size(); j++) {
                Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
                int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
                circle(img, eye_center, radius, Scalar(65, 105, 255), 4, 8, 0);
            }
        }
    }
    QString temp=QString(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"\n"+"find "+faces.size()+" face!");
    ui->textEdit->append(temp);

    imwrite(jpg_out,img);

}

