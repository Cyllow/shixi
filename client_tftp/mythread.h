#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>
#include <QFile>
#include <stdlib.h>
#include <unistd.h>
#include "camera.h"

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = 0);
    virtual ~mythread();
protected:
    void run();
    
signals:
    void signal_showpic();
public slots:

private:
    Camera *camera;
    unsigned char *pic_buffer;
};

#endif // MYTHREAD_H
