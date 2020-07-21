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

			objects.push_back(library.inventory.find("Player")->second->create(objects));
			objects.push_back(library.inventory.find("Monster")->second->create(objects));
			objects.push_back(library.inventory.find("Monster")->second->create(objects));
			objects.push_back(library.inventory.find("Monster")->second->create(objects));

			Player player2;
			while (player2.getLevel() < 5) {
				player2.levelUp();
			}
			Assert::IsTrue(player2.abilities.size() == 5);
			int level = player2.getLevel();
			int strength = player2.getStrength();
			int SP = player2.getSP();
			int health = player2.getHealth();

			player2.abilities.at(0)->execute(objects);
			Assert::IsTrue(SP = player2.getSP() - 2 || player2.getSP() == 0 || player2.getSP() == 1);
			Assert::IsTrue(SP >= 0);
			Assert::IsTrue(player2.getHealth() > health);
			SP = player2.getSP();

			player2.abilities.at(1)->execute(objects);
			Assert::IsTrue(player2.getStrength() == strength - 1);

			player2.abilities.at(2)->execute(objects);
			Assert::IsTrue(SP = player2.getSP() - 5 || player2.getSP() == 0 || player2.getSP() == 1);
			Assert::IsTrue(SP >= 0);
		}
	};
}