#pragma once
#include <iostream>

class Sudoku
{
public:

	//Load sudoku table from file and put in object's private array
	bool LoadFromFile		( const char*			_path );
	
	//Print to console sudoku table from private array
	void Show();
	
	//Solve sudoku from private array of this object
	bool Solve(int& n);
	
	//Check if in array is at least one free cell. And if it found one it set _row and _column to its possition
	bool IsFreeCells		( unsigned short&		_row,		unsigned short&			_column);

	//Check if given number can be found on it's row , column, or square
	bool IsCellOk			( const unsigned short&	_row,		const unsigned short&	_column,	const unsigned short& _number );
	bool IsUsedInRow		( const unsigned short& _row,		const unsigned short&	_number );
	bool IsUsedInColumn		( const unsigned short& _column,	const unsigned short&	_number );
	bool IsUsedInBox		( const unsigned short& _row,		const unsigned short&	_column,	const unsigned short& _number );

private:
	//private level array
	unsigned short mGrid[9][9];

};

