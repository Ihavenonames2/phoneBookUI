#pragma once

#include "BaseSqlTableModel.h"
#include "Abonent.h"


class AbonentSqlTableModel : public QBaseSqlTableModel <Abonent> 
{
public:
    AbonentSqlTableModel()
        : QBaseSqlTableModel(Abonent::TableName, {Abonent::FieldName, Abonent::FieldPhone, Abonent::FieldService })
    {
        static bool a = false;
        if (a)
        {
            throw std::runtime_error("dont create me again");
        }
        a = true;
    }
    bool deleteByNumber(const QString& number);
    Abonent selectById(int id) override;
    bool isUnique(const Abonent& abonent) const;
private:
    Abonent SqlQueryToObject(const QSqlQuery& query) const override;

};

extern AbonentSqlTableModel gAbonentSqlTableModel;

