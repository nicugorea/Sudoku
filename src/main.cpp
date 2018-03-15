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
	int n = 0;
	if(game.Solve(n))
	game.Show();
	else std::cout << "\n\tCan not resolve it";

	std::cout << "\n\tPress any key to exit";
	std::cout << "\n "<<n;
	getch();


	

	return 0;
}