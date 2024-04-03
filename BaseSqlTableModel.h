#pragma once

#include <QtSql>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

template<class T>
class QBaseSqlTableModel
{
public:
    QBaseSqlTableModel(const char* tableName_, std::vector<QString> fields_)
    {
        tableName = tableName_;
        fields.insert(fields_.begin(), fields_.end());
        for (auto& field : fields)
        {
            keys += field;
            keys += ",";
        }
        keys.erase(keys.end() - 1);
    }
    virtual bool insertElement(const T& element) 
    {
        
        QString values;
        std::unordered_map<QString, QVariant> data = element.fetchData();
        for (auto& e : data)
        {
            if (e.second.metaType() == QMetaType(QMetaType::QString))
                values += "'";
            values += e.second.toString();
            if (e.second.metaType() == QMetaType(QMetaType::QString))
                values += "'";

            values += ",";
        }
     
        return execQuery(QString("INSERT INTO %1 (%2) VALUES (%3)").arg(tableName).arg(keys).arg(values));
    }
    virtual bool insertEmptyRow()
    {
        QSqlQuery query0;
        return query0.exec(QString("INSERT INTO %1 DEFAULT VALUES;").arg(tableName));
    }
    virtual bool UpdateById(int id, const T& element)
    {
        QString values;
        std::unordered_map<QString, QVariant> data = element.fetchData();
        for (auto& e : data)
        {
            if (e.second.metaType() == QMetaType(QMetaType::QString))
                values += "'";
            values += e.second.toString();
            if (e.second.metaType() == QMetaType(QMetaType::QString))
                values += "'";

            values += ",";
        }
        QStringList keyList = keys.split(",");
        QStringList valueList = values.split(",");

        QStringList keyValuePairs;

        for (int i = 0; i < keyList.size(); ++i) {
            keyValuePairs << QString("%1=%2").arg(keyList[i].trimmed()).arg(valueList[i].trimmed());
        }

        QString updateQuery = QString("UPDATE %1 SET %2 WHERE id = %3")
            .arg(tableName)
            .arg(keyValuePairs.join(", ")) 
            .arg(id); 

        QSqlQuery query;
        if (!query.exec(updateQuery)) {
            qDebug() << "Query execution failed:" << query.lastError().text();
            return false;
        }

    }
    virtual bool deleteById(int id)
    {
        return execQuery(QString("DELETE FROM %1 WHERE id = %2").arg(tableName).arg(id));
    }
    virtual int getNumberOfRows()
    {  
        QSqlQuery selectQuery;
        QString select = "SELECT * FROM " + QString(tableName);
        if (selectQuery.exec(select)) {
            return selectQuery.size();
        }
        else {
            QString str = selectQuery.lastError().text();
            qDebug() << "Failed to get row count:" << str;
            return 0;
        }
    }
    virtual std::vector<T> SelectAll()
    {
        query.exec(QString("SELECT* FROM %1").arg(tableName));
        std::vector<T> selectedObjects;
        while (query.next())
        {
            selectedObjects.push_back(SqlQueryToObject(query));
        }
        return selectedObjects;
    }
    virtual T selectById(int id)
    {
        QSqlQuery selectQuery;
        selectQuery.exec(QString("SELECT %1 FROM %2 ORDER by id").arg(keys).arg(tableName));
        selectQuery.seek(id);
        return SqlQueryToObject(selectQuery);
    }
    virtual bool deleteByFilter(const QString& fieldName, const QVariant& parameter)
    {
        QSqlQuery query2;
        if (parameter.metaType() == QMetaType(QMetaType::QString))
            query2.exec(QString("DELETE FROM %1 WHERE %2 = '%3'").arg(tableName).arg(fieldName).arg(parameter.toString()));
        else
            query2.exec(QString("DELETE FROM %1 WHERE %2 = %3").arg(tableName).arg(fieldName).arg(parameter.toString()));
        return UpdateId();
                
    }
    inline bool UpdateId()
    {
        QSqlQuery Uquery;
        Uquery.exec(QString("ALTER SEQUENCE %1_id_seq RESTART WITH 1;").arg(tableName));
        return Uquery.exec(QString("UPDATE %1 SET id = DEFAULT;").arg(tableName));
    }
    bool execQuery(const QString& q)
    {
        return query.exec(q);
    }
    virtual T SqlQueryToObject(const QSqlQuery& query) const = 0;
    
private:
    QSqlQuery query;
    QString tableName;
    QString keys;
    std::unordered_set<QString> fields;
};