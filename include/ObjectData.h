/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#ifndef OBJECTDATA_H
#define OBJECTDATA_H

#include <QAbstractListModel>
#include <QObject>

class ObjectData: public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        idRole = Qt::UserRole+1
      };
    ObjectData(QString name);
    QString name();
    bool insertRows(int row, int count, QString object, const QModelIndex &parent = QModelIndex());
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    void addEquipement(QString equipement);
private:
    QString _name;
    QStringList _equipement;
};

#endif // OBJECTDATA_H
