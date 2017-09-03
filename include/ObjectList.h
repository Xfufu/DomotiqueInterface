/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include <QObject>
#include <QStringList>
#include <QQmlContext>

#include <QAbstractListModel>

#include "HttpConnection.h"
#include "ObjectData.h"

class ObjectList: public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        NameRole = Qt::UserRole+1,
        ModelListRole = Qt::UserRole+2
      };
    ObjectList(QQmlContext *context, HttpConnection &interface);
    void init();
    bool insertRows(int row, int count, QString object, const QModelIndex &parent = QModelIndex());
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
public slots:
    void onGetObject(QString object);
//signals:
//    void createObject(QString name);
private:
    QQmlContext *_context;
    HttpConnection &_interface;
    QList<ObjectData *> _objectList;
};

#endif // OBJECTLIST_H
