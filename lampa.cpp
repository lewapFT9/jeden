#include "lampa.h"
#include "ui_lampa.h"

#include <QMetaEnum>
#include <QMessageBox>


Lampa::Lampa(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lampa)
{
    ui->setupUi(this);
    if(kontroler.currentState()==QAbstractSocket::ConnectedState)
        kontroler.disconnectFromServer();
    else{
        auto ip="127.0.0.1";
        auto port=12345;
        kontroler.connectWithServer(ip,port);
    }
    auto message = "Lampa";
    kontroler.send(message);

    setKontroler();
    lightStatus = "Off";
    lightColor = "Yellow";
    intense = 255;
    r=255;
    g=255;
    b=255;
}

Lampa::~Lampa()
{
    delete ui;
}






void Lampa::lampaConnected()
{

}

void Lampa::lampaDisconnected()
{

}

void Lampa::lampaStateChanged(QAbstractSocket::SocketState state)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();


}

void Lampa::lampaErrorOccurred(QAbstractSocket::SocketError error)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();


}

void Lampa::lampaDataReady(QByteArray data)
{

}

void Lampa::action(QByteArray data)
{
    QString command= QString(data);
    QString style;

    if(command=="Light on" && lightStatus !="On"){
        r=255;
        g=255;
        b=255;
        style =QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
                        " fy:0.5, stop:0 rgba(%1, %2, %3, %4), stop:1 rgba(255, 255, 255, 0))").arg(r).arg(b).arg(b).arg(intense);
        ui->light->setStyleSheet(style);
        lightStatus = "On";
        lightColor="White";
    }
    else if(command=="Light off" && lightStatus !="Off"){
        style="";
        ui->light->setStyleSheet(style);
        lightStatus="Off";
    }
    else if(command=="Yellow" && lightStatus =="On" && lightColor!="Yellow"){
        r=255;g=255;b=0;
        style =QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
                        " fy:0.5, stop:0 rgba(%1, %2, %3, %4), stop:1 rgba(255, 255, 255, 0))").arg(r).arg(g).arg(b).arg(intense);
        ui->light->setStyleSheet(style);
        lightColor="Yellow";
    }
    else if(command=="Green" && lightStatus =="On" && lightColor!="Green"){
        r=0;g=255;b=0;
        style =QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
                        " fy:0.5, stop:0 rgba(%1, %2, %3, %4), stop:1 rgba(255, 255, 255, 0))").arg(r).arg(g).arg(b).arg(intense);
        ui->light->setStyleSheet(style);
        lightColor="Green";
    }
    else if(command=="Red" && lightStatus =="On" && lightColor!="Red"){
        r=255;g=0;b=0;
        style =QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
                        " fy:0.5, stop:0 rgba(%1, %2, %3, %4), stop:1 rgba(255, 255, 255, 0))").arg(r).arg(g).arg(b).arg(intense);
        ui->light->setStyleSheet(style);
        lightColor="Red";
    }
    else if(command=="Blue" && lightStatus =="On" && lightColor!="Blue"){
        r=0;g=0;b=255;
        style =QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
                        " fy:0.5, stop:0 rgba(%1, %2, %3, %4), stop:1 rgba(255, 255, 255, 0))").arg(r).arg(g).arg(b).arg(intense);
        ui->light->setStyleSheet(style);
        lightColor="Blue";
    }
    else if(command=="White" && lightStatus =="On" && lightColor!="White"){
        r=155;g=255;b=255;
        style =QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
                        " fy:0.5, stop:0 rgba(%1, %2, %3, %4), stop:1 rgba(255, 255, 255, 0))").arg(r).arg(g).arg(b).arg(intense);
        ui->light->setStyleSheet(style);
        lightColor="White";
    }
    else if(command=="25" && lightStatus =="On" && intense!= 64){
        intense=64;
        style =QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
                        " fy:0.5, stop:0 rgba(%1, %2, %3, %4), stop:1 rgba(255, 255, 255, 0))").arg(r).arg(g).arg(b).arg(intense);
        ui->light->setStyleSheet(style);
    }
    else if(command=="50" && lightStatus =="On" && intense!= 128){
        intense=128;
        style =QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
                        " fy:0.5, stop:0 rgba(%1, %2, %3, %4), stop:1 rgba(255, 255, 255, 0))").arg(r).arg(g).arg(b).arg(intense);
        ui->light->setStyleSheet(style);
    }
    else if(command=="75" && lightStatus =="On" && intense!= 192){
        intense=192;
        style =QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
                        " fy:0.5, stop:0 rgba(%1, %2, %3, %4), stop:1 rgba(255, 255, 255, 0))").arg(r).arg(g).arg(b).arg(intense);
        ui->light->setStyleSheet(style);
    }
    else if(command=="100" && lightStatus =="On" && intense!= 255){
        intense=255;
        style =QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5,"
                        " fy:0.5, stop:0 rgba(%1, %2, %3, %4), stop:1 rgba(255, 255, 255, 0))").arg(r).arg(g).arg(b).arg(intense);
        ui->light->setStyleSheet(style);
    }
}

void Lampa::setKontroler()
{
    connect(&kontroler,&Kontroler::connected,this, &Lampa::lampaConnected);
    connect(&kontroler,&Kontroler::disconnected,this, &Lampa::lampaDisconnected);
    connect(&kontroler,&Kontroler::stateChanged,this, &Lampa::lampaStateChanged);
    connect(&kontroler,&Kontroler::errorOccurred,this, &Lampa::lampaErrorOccurred);
    connect(&kontroler,&Kontroler::dataReady,this, &Lampa::lampaDataReady);
    connect(&kontroler,&Kontroler::dataReady,this, &Lampa::action);


}

