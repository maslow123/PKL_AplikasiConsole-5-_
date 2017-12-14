#include "time.h"
#include <QtCore>
#include <QDebug>
#include "redis.h"
#include "time2.h"

//untuk mendapatkan redis
int jumlah1,jumlah2,jumlah3,jumlah4 = 0;
int angka1,angka2,angka3,angka4 = 0;




time::time()
{

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));

    timer -> start(1000);
}

time2::time2()
{

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot2()));

    timer -> start(1000);
}

void time :: MySlot()
{
    //untuk mendapatkan data dari redis
    int nomer3 = nomer2++;
    int nomer55 = nomer5+=5;
    int nomer100 = nomer10+=10;
    int nomer105 = nomer15+=15;

    QString hasilnya1 = QString :: number(nomer3);
    QString hasilnya5 = QString :: number(nomer55);
    QString hasilnya10 = QString :: number(nomer100);
    QString hasilnya15 = QString :: number(nomer105);

    redis rds;
    QStringList result1 = rds.reqRedis("HSET otomatis penjumlahan;1 '"+hasilnya1+"'","127.0.0.1", 6379);
    QStringList result2 = rds.reqRedis("HSET otomatis penjumlahan;5 '"+hasilnya5+"'","127.0.0.1", 6379);
    QStringList result3 = rds.reqRedis("HSET otomatis penjumlahan;10 '"+hasilnya10+"'","127.0.0.1", 6379);
    QStringList result4 = rds.reqRedis("HSET otomatis penjumlahan;15 '"+hasilnya15+"'","127.0.0.1", 6379);

   }
void time2 :: MySlot2()
{


    redis rds;
    QStringList result1 = rds.reqRedis("HGET otomatis penjumlahan;1","127.0.0.1", 6379);
    QStringList result2 = rds.reqRedis("HGET otomatis penjumlahan;5","127.0.0.1", 6379);
    QStringList result3 = rds.reqRedis("HGET otomatis penjumlahan;10","127.0.0.1", 6379);
    QStringList result4 = rds.reqRedis("HGET otomatis penjumlahan;15","127.0.0.1", 6379);

    qDebug() << result1 <<"Hasil dari"<<(angka1+=1) <<"*1 = "<<(jumlah1+=1)<<"                      ||||||"<< endl;
    qDebug() << result2 <<"Hasil dari"<<(angka2+=1) <<"*5 = "<<(jumlah2+=5)<<"                      ||||||"<< endl;
    qDebug() << result3 <<"Hasil dari"<<(angka3+=1) <<"*10 = "<<(jumlah3+=10)<<"                    ||||||"<<endl;
    qDebug() << result4 <<"Hasil dari"<<(angka4+=1) <<"*15 = "<< (jumlah4+=15)<<"                   ||||||"<<endl;
    qDebug() << "=============================================================================";

}


