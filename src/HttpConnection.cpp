/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#include "HttpConnection.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#define MY_URL ""
#define API_KEY ""

HttpConnection::HttpConnection():
    _manager(new QNetworkAccessManager(this))
{}

void HttpConnection::init()
{
    connect(_manager, QNetworkAccessManager::finished,
            this, HttpConnection::replyFinished);
}

void HttpConnection::sendData()
{
    QNetworkRequest request(QUrl("MY_URL/core/api/jeeApi.php"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json-rpc");
    request.setRawHeader("Accept-Encoding", "application/json-rpc");
    QJsonObject jsonObject;
    jsonObject.insert("jsonrpc", "2.0");
    jsonObject.insert("method", "datetime");
    jsonObject.insert("id", "null");
    QJsonObject apiKey;
    apiKey.insert("apikey", API_KEY);
    QJsonArray jsonArray;
    jsonArray.append(apiKey);
    jsonObject.insert("params", jsonArray);
    QJsonDocument jsonDocument(jsonObject);
    request.setHeader(QNetworkRequest::ContentLengthHeader, jsonDocument.toJson().length());
    //request.setHeader(QNetworkRequest::ContentLengthHeader, jsonDocument.toJson().size());
    qDebug(jsonDocument.toJson());

    _manager->post(request, jsonDocument.toJson());
}

void HttpConnection::replyFinished(QNetworkReply* reply)
{
    qDebug(reply->errorString().toUtf8());
    qDebug("replyFinished");
    qDebug(reply->readAll());
    qDebug("replyFinished");
    reply->deleteLater();
    emit getObject("appartement");
    emit getObject("salonN");
}
