#include "AbonentsModel.h"
AbonentsModel::AbonentsModel(QObject* parent) : QAbstractListModel{parent}
{

}

int AbonentsModel::rowCount(const QModelIndex &parent) const
{
    return gAbonentSqlTableModel.getNumberOfRows();
}

int AbonentsModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant AbonentsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || (index.row() >= rowCount()))
    {
        return {};
    }
    if (role == Qt::DisplayRole)
    {
        auto elem = gAbonentSqlTableModel.selectById(index.row());
        return QVariant::fromValue(elem.toString());
    }

    return {};
}

bool AbonentsModel::setData(const QModelIndex &i, const QVariant &value, int role)
{
    if (i.row() >= rowCount() || !i.isValid())
    {
        return false;
    }
    Abonent abonent;
    abonent = value.value<Abonent>();
    gAbonentSqlTableModel.UpdateById(i.row(), abonent);

    emit dataChanged(i, i, QList<int>(role));

    return true;
}

bool AbonentsModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row , row + count);
    QSqlQuery query;
    for (int i = 0; i < count; ++i)
    {
        gAbonentSqlTableModel.insertEmptyRow();
    }
    endInsertRows();

    return true;
}

void AbonentsModel::addAbonent(const Abonent &abonent)
{
    if (gAbonentSqlTableModel.isUnique(abonent))
    {
        const int oldLastRow = AbonentsModel::rowCount();
        AbonentsModel::insertRows(oldLastRow, 1);

        QVariant variant = QVariant::fromValue(abonent);
        setData(index(oldLastRow, 0), variant);

    }

}

void AbonentsModel::deleteAbonent(const QString& number)
{
    gAbonentSqlTableModel.deleteByNumber(number);
    emit dataChanged(index(0, 0), index(rowCount(), 0));
}

