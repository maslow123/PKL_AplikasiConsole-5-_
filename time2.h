#ifndef TIME2_H
#define TIME2_H
#include <QObject>
#include <QTimer>

class time2 : public QObject
{
    Q_OBJECT
public:
    time2();
    QTimer *timer;


public slots:
    void MySlot2();
};

#endif // TIME_H
