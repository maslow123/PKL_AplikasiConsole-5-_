#ifndef TIME_H
#define TIME_H
#include <QObject>
#include <QTimer>

class time : public QObject
{
    Q_OBJECT
public:
    time();
    QTimer *timer;
    //untuk mengeset redis
    int nomer2 = 2;
    int nomer5 = 5;
    int nomer10 = 10;
    int nomer15 = 15;



public slots:
    void MySlot();
};

#endif // TIME_H
