#include "Sudoku.h"
#include <fstream>

#define RANK 9
#define RANKK 3


bool Sudoku::LoadFromFile( const char * _path )
{
	std::ifstream input( _path );

	if(!input.is_open()) return false;

	for(int i = 0; i < RANK*RANK; i++)
			input >> mGrid[i/RANK][i%RANK];

	input.close();

	return true;
}

void Sudoku::Show()
{
	for(int i = 0; i < RANK; i++)
	{
		for(int j = 0; j < RANK; j++)
		{
		std::cout << mGrid[i][j] << " ";
		if(j % 3==2) std::cout << " ";
		}
		std::cout << "\n";
		if(i % 3 == 2) std::cout << "\n";
	}
	
}

bool Sudoku::Solve(int& n)
{
	n++;
	unsigned short freeCellRow = -1, freeCellColumn = -1;
	if(!IsFreeCells( freeCellRow, freeCellColumn )) return true;

	for(int i = 1; i <= RANK; i++)
	{
		if(IsCellOk( freeCellRow, freeCellColumn, i ))
		{
			mGrid[freeCellRow][freeCellColumn] = i;

			if(Solve(n)) return true;

			mGrid[freeCellRow][freeCellColumn] = 0;

		}
	}
	return false;
}

bool Sudoku::IsFreeCells( unsigned short& _row, unsigned short& _column )
{
	for(int i = 0; i < RANK*RANK; i++)
			if(!mGrid[i / RANK][i%RANK])
			{
				_row = i/RANK;
				_column = i%RANK;
				return true;
			}

	return false;
}

bool Sudoku::IsCellOk( const unsigned short & _row, const unsigned short & _column, const unsigned short& _number )
{
	return !IsUsedInBox( _row - _row % 3, _column - _column % 3, _number )
		&& !IsUsedInColumn( _column, _number )
		&& !IsUsedInRow( _row, _number );
}

bool Sudoku::IsUsedInRow( const unsigned short & _row, const unsigned short& _number )
{
	for(int i = 0; i < RANK; i++)
		if(mGrid[_row][i] == _number) return true;

	return false;
}

bool Sudoku::IsUsedInColumn( const unsigned short & _column, const unsigned short& _number )
{
	for(int i = 0; i < RANK; i++)
		if(mGrid[i][_column] == _number) return true;

	return false;
}

bool Sudoku::IsUsedInBox( const unsigned short & _row, const unsigned short & _column, const unsigned short& _number )
{
	for(int i = 0; i < RANK; i++)
			if(mGrid[_row + i/RANKK][_column + i%RANKK] == _number) return true;

	return false;
}
