#include "AbonentSqlTableModel.h"

AbonentSqlTableModel gAbonentSqlTableModel;

Abonent AbonentSqlTableModel::SqlQueryToObject(const QSqlQuery& query) const
{
    Abonent abonent;
    abonent.setName(query.value(0).toString());
    abonent.setNumber(query.value(1).toString());
    abonent.setService(query.value(2).toString());
    return abonent;
}

bool AbonentSqlTableModel::deleteByNumber(const QString& number)
{
    return deleteByFilter(Abonent::FieldPhone, QVariant::fromValue(number)); 
}

Abonent AbonentSqlTableModel::selectById(int id)
{
    QSqlQuery selectQuery;
    selectQuery.exec(QString("SELECT phonebook.name, phonebook.phone_number, services.service FROM phonebook JOIN services ON phonebook.service = services.id;"));
    selectQuery.seek(id);
    return SqlQueryToObject(selectQuery);
}

bool AbonentSqlTableModel::isUnique(const Abonent& abonent) const
{
    QSqlQuery query;
    query.prepare(R"(
            SELECT name
            FROM phonebook
            WHERE phone_number=:phone_number
        )");
    query.bindValue(":phone_number", abonent.getNumber());

    if (!query.exec()) {
        qFatal() << "Failed to execute query:" << query.lastError().text();
        return false;
    }

    return query.size() == 0;

}
