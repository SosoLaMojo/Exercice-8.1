#pragma once

class Player
{
public:
	Player();
	~Player() {};

	void TakeDamage(int attack);
	void PickUpObject(char userChoice, int potionHealth, int& potionsLeft);
	void MovePosition(int playerPositionX, int playerPositionY, bool isObstacle, bool isEnemy, bool isPotion,
		bool isTrap, bool isMistery, bool isWinningObject, int potionHealth, int enemyAttack, int trapDamage,
		char userChoice, int& potionsLeft);

	void CheckMove(char userInput);
	void AskUserInput();
	int GetPlayerXposition();
	int GetPlayerYposition();
	void takeHealth(int potionHealth);
	char UserInputs;
	char UserChoice;
	int xPlayerPosition = 3;
	int yPlayerPosition = 18;
	int xNewPlayerPosition;
	int yNewPlayerPosition;
	int health_ = 100;
private:

};

