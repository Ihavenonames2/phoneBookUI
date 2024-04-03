#pragma once

#include <string>
#include <unordered_map>
#include <QString>
#include <QVariant>
#include <vector>

#include "BaseTableEntity.h"

enum Service  
{
    telegram  = 1,
    viber = 2,
    phone = 3
};

class Abonent : public BaseTableEntity
{
private:
    QString name;
    QString number;
    QString service;

public:
    void setName(const QString& name);
    void setNumber(const QString& number);
    void setService(const QString& service);
    void setId(const std::size_t id);
    QString getNumber() const;
    QString getName() const;
    QString getService() const;
    std::size_t getId() const;
    QString toString();
    bool operator < (const Abonent& str) const;
    std::unordered_map<QString, QVariant> fetchData() const override;

    inline static const char TableName[] = "phonebook";
    inline static const char FieldId[] = "id";
    inline static const char FieldName[] = "name";
    inline static const char FieldPhone[] = "phone_number";
    inline static const char FieldService[] = "service";
 
};


