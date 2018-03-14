#pragma once
#include <iostream>

class Sudoku
{
public:
	
	Sudoku();
	~Sudoku();

	bool LoadFromFile		( const char*			_path );

	void Show();
	
	bool Solve();
	
	bool IsFreeCells		( unsigned short&		_row,		unsigned short&			_column);

	bool IsCellOk			( const unsigned short&	_row,		const unsigned short&	_column,	const unsigned short& _number );
	bool IsUsedInRow		( const unsigned short& _row,		const unsigned short&	_number );
	bool IsUsedInColumn		( const unsigned short& _column,	const unsigned short&	_number );
	bool IsUsedInBox		( const unsigned short& _row,		const unsigned short&	_column,	const unsigned short& _number );

private:

	unsigned short mGrid[9][9];

};

