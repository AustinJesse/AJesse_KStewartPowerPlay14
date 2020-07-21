#ifndef MONSTER_FACTORY_H
#define MONSTER_FACTORY_H
#include "ObectFactory.h"
#include "Monster.h"
class MonsterFactory :public ObjectFactory
{
public:
	std::unique_ptr<Object> create(std::vector<std::unique_ptr<Object>>& objects)
	{
		return std::make_unique<Monster>(objects.front());
	}

};
#endif // !MONSTER_FACTORY_H