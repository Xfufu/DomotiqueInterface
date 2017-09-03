/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#include "ObjectList.h"

ObjectList::ObjectList(QQmlContext *context, HttpConnection &interface):
    _context(context),
    _interface(interface)
{

}

void ObjectList::init()
{
    QObject::connect(&_interface, HttpConnection::getObject,
                        this, ObjectList::onGetObject);
    _interface.sendData();
}

bool ObjectList::insertRows(int row, int count, QString object,const QModelIndex &parent)
{
    Q_UNUSED(count);
    beginInsertRows(parent, row, row);
    _objectList.append(new ObjectData(object));
    _context->setContextProperty(object, _objectList.last());
    endInsertRows();
    return true;
}

int ObjectList::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _objectList.size();
}

QVariant ObjectList::data(const QModelIndex &index, int role) const
{
    switch(role) {
    case NameRole:
        return _objectList[index.row()]->name();
    case ModelListRole:
        return QVariant(_objectList[index.row()]->name());
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> ObjectList::roleNames() const
{
    QHash<int, QByteArray> names;
    names[NameRole] = "diName";
    names[ModelListRole] = "dimodelList";
    return names;
}

void ObjectList::onGetObject(QString object)
{
    qDebug("adding : ");
    insertRows(_objectList.size(), 1, object);
    _objectList.last()->addEquipement(object+"1");
    _objectList.last()->addEquipement(object+"2");
    _objectList.last()->addEquipement(object+"3");
    _objectList.last()->addEquipement(object+"4");
    _objectList.last()->addEquipement(object+"5");
    _objectList.last()->addEquipement(object+"6");
    _objectList.last()->addEquipement(object+"7");
    _objectList.last()->addEquipement(object+"8");
    _objectList.last()->addEquipement(object+"9");
}
