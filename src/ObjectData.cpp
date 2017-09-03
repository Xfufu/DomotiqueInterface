/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#include "ObjectData.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>

ObjectData::ObjectData(QString name):
    _name(name)
{

}

QString ObjectData::name()
{
    return _name;
}

bool ObjectData::insertRows(int row, int count, QString object, const QModelIndex &parent)
{
    Q_UNUSED(count);
    beginInsertRows(parent, row, row);

    _equipement.append(object);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(object, _equipement.last());
    endInsertRows();
    return true;
}

int ObjectData::rowCount(const QModelIndex &parent) const
{    Q_UNUSED(parent);
     return _equipement.size();
}

QVariant ObjectData::data(const QModelIndex &index, int role) const
{
    switch(role) {
    case idRole:
        return _equipement[index.row()];
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> ObjectData::roleNames() const
{
    QHash<int, QByteArray> names;
    names[idRole] = "diid";
    return names;
}

void ObjectData::addEquipement(QString equipement)
{
    insertRows(_equipement.size(), 1, equipement);
}
