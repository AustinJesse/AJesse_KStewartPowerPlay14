#include "pch.h"
#include "CppUnitTest.h"
#include "../Player.h"
#include "../Library.h"
#include "../Object.h"
#include "../AttackStrategy.h"
#include "../HealStrategy.h"
#include "../FuryStrategy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(LevelUpTest)
		{
			Player player;
			Assert::AreEqual(1, player.getLevel());
			Assert::IsTrue(player.getHealth() > 0 && player.getStrength() > 0);

			int level = player.getLevel();
			int health = player.getHealth();
			int strength = player.getStrength();
			player.levelUp();
			Assert::IsTrue(level < player.getLevel());
			Assert::IsTrue(health < player.getHealth());
			Assert::IsTrue(strength < player.getStrength());
		}

		TEST_METHOD(AbilityTest)
		{
			Library library;
			std::vector<std::unique_ptr<Object>> objects;

			library.inventory["Player"] = std::make_unique<PlayerFactory>();
			library.inventory["Monster1"] = std::make_unique<MonsterFactory>();
			library.inventory["Monster2"] = std::make_unique<MonsterFactory>();
			library.inventory["Monster3"] = std::make_unique<MonsterFactory>();

			for (const auto& object : library.inventory) {
				objects.emplace_back(object.second);
			}

			Player player2;
			while (player2.getLevel() < 5) {
				player2.levelUp();
			}
			Assert::IsTrue(player2.abilities.size() == 5);
			int level = player2.getLevel();
			int strength = player2.getStrength();
			int SP = player2.getSP();

			for (const auto& ability : player2.abilities)
			{
				ability->execute(objects);
			}			
		}
	};
}
