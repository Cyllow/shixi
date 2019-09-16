#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>
#include <iostream>
#include <highgui.h>
#include <cv.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int picdiscern(string jpg_in,string jpg_out);

    QString makefilename();

    cv::CascadeClassifier faceCascade;
    cv::CascadeClassifier eyes_Cascade;

signals:
    void readyPic(QString name);
    void readyToSend();

public slots:
    void acceptClient();
    void readData();

    void openFile(QString name);
    void updatePic();

private:
    Ui::MainWindow *ui;

    QTcpServer *server;
    QTcpSocket *clientsocket;

    qint32 picBytes;

    qint32 totalBytes;
    qint32 bytesSize;
    qint32 loadSize;

    qint32 fileNameSize;
    QString fileName;

    QFile *localFile;
    QByteArray inBlock;

    int ex(string id,unsigned char *data);
    void DetectFace(Mat img,Mat imgGray,string jpg_out);
};

#endif // MAINWINDOW_H
