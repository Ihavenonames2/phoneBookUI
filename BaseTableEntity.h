#pragma once

#include <iostream>
#include <QString>
#include <vector>


class BaseTableEntity {

public:
	std::size_t id = 0;
	virtual std::unordered_map<QString, QVariant> fetchData() const = 0;
};