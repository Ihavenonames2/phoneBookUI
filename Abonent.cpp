#include <iostream>
#include "Abonent.h"

void Abonent::setName(const QString& name)
{
    this->name = name;
}

void Abonent::setNumber(const QString& number)
{
    this->number = number;
}

void Abonent::setService(const QString& service)
{
    this->service = service;
}

void Abonent::setId(const std::size_t id)
{
    this->id = id;
}

QString Abonent::getNumber() const
{
    return number;
}

QString Abonent::getName() const
{
    return name;
}

std::size_t Abonent::getId() const
{
    return id;
}

QString Abonent::toString()
{
    return QString(name + " " + number + " " + service);
}

QString Abonent::getService() const
{
    return service;
}

bool Abonent::operator < (const Abonent& str) const
{
    return (number < str.number);
}

std::unordered_map<QString, QVariant> Abonent::fetchData() const
{
    std::unordered_map<QString, QVariant> data;
    data.insert(std::make_pair(FieldName, QVariant::fromValue(name)));
    data.insert(std::make_pair(FieldPhone, QVariant::fromValue(number)));
    data.insert(std::make_pair(FieldService, QVariant::fromValue(service)));
    return data;
}
