#ifndef ABONENTSMODEL_H
#define ABONENTSMODEL_H

#include <QAbstractListModel>
#include "Abonent.h"
#include "connection.h"
#include "AbonentSqlTableModel.h"

#include <vector>

class AbonentsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AbonentsModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    void addAbonent(const Abonent &abonent);
    void deleteAbonent(const QString& number);
   

    //QVector<Abonent> dbcache TODO
};

#endif // ABONENTSMODEL_H
