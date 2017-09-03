/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class HttpConnection: public QObject
{
    Q_OBJECT
public:
    HttpConnection();
    void init();
    void sendData();

public slots:
    void replyFinished(QNetworkReply* reply);

signals:
    void getObject(QString name);

private:
    QNetworkAccessManager *_manager;
};

#endif // HTTPCONNECTION_H
