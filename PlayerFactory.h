#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H
#include "ObectFactory.h"
#include "Player.h"
class PlayerFactory :public ObjectFactory
{
public:
	std::unique_ptr<Object> create(std::vector<std::unique_ptr<Object>>& objects)
	{
		return std::make_unique<Player>();
	}

};
#endif // !PLAYER_FACTORY_H