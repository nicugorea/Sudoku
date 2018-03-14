#include "Sudoku.h"
#include <fstream>


Sudoku::Sudoku()
{
}

Sudoku::~Sudoku()
{
}

bool Sudoku::LoadFromFile( const char * _path )
{
	std::ifstream input( _path );

	if(!input.is_open()) return false;

	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			input >> mGrid[i][j];

	input.close();

	return true;
}

void Sudoku::Show()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
		std::cout << mGrid[i][j] << " ";
		if(j % 3==2) std::cout << " ";
		}
		std::cout << "\n";
		if(i % 3 == 2) std::cout << "\n";
	}

}

bool Sudoku::Solve()
{
	unsigned short numRow = 0, numCol = 0;
	if(!IsFreeCells( numRow, numCol )) return true;

	for(int i = 1; i <= 9; i++)
	{
		if(IsCellOk( numRow, numCol, i ))
		{
			mGrid[numRow][numCol] = i;

			if(Solve()) return true;

			mGrid[numRow][numCol] = 0;

		}
	}
	return false;
}

bool Sudoku::IsFreeCells( unsigned short& _row, unsigned short& _column )
{
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(!mGrid[i][j])
			{
				_row = i;
				_column = j;
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
	for(int i = 0; i < 9; i++)
		if(mGrid[_row][i] == _number) return true;

	return false;
}

bool Sudoku::IsUsedInColumn( const unsigned short & _column, const unsigned short& _number )
{
	for(int i = 0; i < 9; i++)
		if(mGrid[i][_column] == _number) return true;

	return false;
}

bool Sudoku::IsUsedInBox( const unsigned short & _row, const unsigned short & _column, const unsigned short& _number )
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(mGrid[_row + i][_column + j] == _number) return true;

	return false;
}
