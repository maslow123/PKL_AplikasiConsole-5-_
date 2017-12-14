#include <QCoreApplication>
#include "redis.h"
#include "time.h"
#include "time2.h"
int main(int argc, char *argv[])
{
      QCoreApplication a(argc,argv);

      time mTime;
      time2 mTime2;

    return a.exec();
}
