#ifndef LIBRARY_H
#define LIBRARY_H

#include <map>
#include <string>
#include <memory>
#include "MonsterFactory.h"
#include "PlayerFactory.h"
class Library
{
public:
	Library()
	{
		inventory["Player"] = std::make_unique<PlayerFactory>();
		inventory["Monster"] = std::make_unique<MonsterFactory>();
	}

	std::map<std::string, std::unique_ptr<ObjectFactory>> inventory;
};

#endif LIBRARY_H
