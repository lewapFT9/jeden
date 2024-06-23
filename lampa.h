#ifndef LAMPA_H
#define LAMPA_H

#include <QMainWindow>
#include <QStyle>
#include <QHostAddress>
#include "kontroler.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Lampa;
}
QT_END_NAMESPACE

class Lampa : public QMainWindow
{
    Q_OBJECT

public:
    Lampa(QWidget *parent = nullptr);
    ~Lampa();

private slots:

    void lampaConnected();
    void lampaDisconnected();
    void lampaStateChanged(QAbstractSocket::SocketState);
    void lampaErrorOccurred(QAbstractSocket::SocketError);
    void lampaDataReady(QByteArray data);
    void action(QByteArray data);

private:
    Ui::Lampa *ui;
    Kontroler kontroler;
    QString lightStatus;
    QString lightColor;
    int intense;
    int r;
    int g;
    int b;

    void setKontroler();
};
#endif // LAMPA_H
