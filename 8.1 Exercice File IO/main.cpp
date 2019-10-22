#include <iostream>
#include "player.h"
#include "enemy.h"
#include "map.h"
#include "potion.h"
#include "trap.h"
#include "GlobalRessources.h"
#include <Windows.h>
#include <time.h>


/* EXERCICE 8.1
Rendu git
De manière individuelle, il faut reprendre l’exercice 7.0 (Roguelike).
Pour ceux qui ne sont pas propriétaire du git, il faut forker le projet.
Il faut enregistrer dans un fichier externe des niveaux.
Le format de fichier est à choix.
*/

int main() {

	Player player = Player();
	Enemy enemy = Enemy();
	Potion potion = Potion();
	Trap trap = Trap();
	//Map map = Map(player.xPlayerPosition, player.yPlayerPosition);
	Map map = Map::CreateMap("Map1.txt");

	//system("pause");

	bool isRunning = true;
	while (isRunning)
	{

		map.isObstacle = false;
		map.isEnemy = false;
		map.isPotion = false;
		map.isTrap = false;
		map.isMistery = false;

		system("cls");
		map.Print();
		map.ShowMenu(player.health_);
		map.GiveKey(potion.potionsLeft, Ressource::mystery, map.keyXPosition, map.keyYPosition);
		player.AskUserInput();
		player.CheckMove(player.UserInputs);
		map.MoveSecurity(player.xNewPlayerPosition, player.yNewPlayerPosition);
		map.UpdateMap(player.GetPlayerXposition(), player.GetPlayerYposition());

		player.MovePosition(player.xNewPlayerPosition, player.yNewPlayerPosition, map.isObstacle, map.isEnemy,
			map.isPotion, map.isTrap, map.isMistery, map.isWinningObject, potion.potionVie,
			enemy.attack_, trap.attackTrap, player.UserChoice, potion.potionsLeft);

		map.Add(Ressource::player, player.xPlayerPosition, player.yPlayerPosition);
		map.CheckWinOrDeath(player.health_, isRunning, map.isWinningObject);

	}
	system("cls");
	map.ShowEnding();
	system("pause");
	return EXIT_SUCCESS;
}