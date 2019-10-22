#include <iostream>
#include "player.h"


void Player::TakeDamage(const int attack)
{
	health_ -= attack;
}

void Player::PickUpObject(char userChoice, int potionHealth, int& potionsLeft)
{
	std::cout << "Do you want to eat the magical healing apple ? If you don't, it will be wasted .  Type Y or N\n";
	std::cin >> userChoice;

	switch (userChoice)
	{
	case('y'):
	{
		potionsLeft++;
		takeHealth(potionHealth);
		std::cout << "\nThe apple power gave you 20 health point\n\n";
		system("pause");
		break;
	}
	case('n'):
	{
		std::cout << "\nYou didn't eat the magical healing apple\nIt transformed into dust\n\n";
		system("pause");
		break;
	}
	default:
		std::cout << "\nYou don't pick up the potion\n\n";
		break;
	}
}

void Player::MovePosition(int newplayerPositionX, int newplayerPositionY, bool isObstacle, bool isEnemy, bool isPotion, bool isTrap, bool isMistery, bool isWinningObject, int potionHealth, int enemyAttack, int trapDamage, char userChoice, int& potionsLeft)
{
	if (isObstacle == true)
	{
		xPlayerPosition = xPlayerPosition;
		yPlayerPosition = yPlayerPosition;
		return;
	}
	if (isEnemy == true)
	{
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		TakeDamage(enemyAttack);
		std::cout << "\nThe fake apple exploded when you touched it, you died..\n\n";
		system("pause");
		return;
	}
	if (isPotion == true)
	{
		PickUpObject(userChoice, potionHealth, potionsLeft);
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;

		return;
	}
	if (isTrap == true)
	{
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		TakeDamage(trapDamage);
		std::cout << "\nYou fell into a trap, hurting yourself and loosing 40 health points\n\n";
		system("pause");
		return;
	}
	if (isMistery == true)
	{
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;

	}
	if (isWinningObject == true)
	{
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		std::cout << "Congratulation you found the magic staff, you teleport out of the dungeon\n";
		system("pause");
	}
	else
	{
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		return;
	}
}

void Player::CheckMove(char userInput)
{
	switch (userInput)
	{
	case('w'):
		yNewPlayerPosition = yPlayerPosition;
		xNewPlayerPosition = xPlayerPosition - 1;
		break;
		
	case('a'):
		yNewPlayerPosition = yPlayerPosition - 1;
		xNewPlayerPosition = xPlayerPosition;
		break;
		
	case('s'):
		yNewPlayerPosition = yPlayerPosition;
		xNewPlayerPosition = xPlayerPosition + 1;
		break;
		
	case('d'):
		yNewPlayerPosition = yPlayerPosition + 1;
		xNewPlayerPosition = xPlayerPosition;
	}
}


void Player::AskUserInput()
{
	std::cin >> UserInputs;
}

int Player::GetPlayerXposition()
{
	return xPlayerPosition;
}

int Player::GetPlayerYposition()
{
	return yPlayerPosition;
}

void Player::takeHealth(int potionHealth)
{

	health_ += potionHealth;

}

Player::Player()
{
}

