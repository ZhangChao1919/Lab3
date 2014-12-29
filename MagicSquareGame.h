//Summary: The MagicSquareGame.h declares private members and public members. The public members functions contain constructures, destructures, some virtual functions.

#ifndef MAGICSQUAREGAME_H
#define MAGICSQUAREGAME_H
#include "stdafx.h"
#include "GameBase.h"

class MagicSquareGame: public GameBase
{
	friend ostream &operator<<(ostream &out, const MagicSquareGame & object);
private:
	int startMin;
	vector<int> availablePieces;

public:
	MagicSquareGame();
	MagicSquareGame(int size);
	MagicSquareGame(int size, int min);
	~MagicSquareGame(){}
	virtual void print();
	virtual bool done();
	virtual bool stalemate(); 
	virtual int prompt(unsigned int &fir, unsigned int &sec);
	virtual int prompt(int &inputInt);
	virtual int turn();
	bool boardisFull();
};

#endif

