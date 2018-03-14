#include <iostream>
#include <conio.h>
#include "Sudoku.h"


int main() {	

	Sudoku game;
	
	if(!game.LoadFromFile( "res/level.txt" ))
		std::cout << "\n\tError loading file";
	
	game.Show();
	std::cout << "\n\tPress any key to resolve it";
	getch();
	system( "cls" );
	if(game.Solve())
	game.Show();
	else std::cout << "\n\tCan not resolve it";

	std::cout << "\n\tPress any key to exit";
	getch();


	

	return 0;
}