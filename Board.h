#pragma once
#include<vector>
#include "Piece.h"
#include "King.h"
#include "Nullpiece.h"
#include "Pawn.h"
#include<iostream>
class Board {
	/**
	*This class contains the necesarry pieces of the game
	*/

	/*ötlet: legyen egy Empty nevû piece spot osztaly helyett*/
	std::vector<std::vector<Piece*>>board;
	/*8x8 as mátrix legyen*/
	
public:
	Board() {}
	~Board() {/*A LEGFOGLALT BOARD VEKTORT FELSZABADÍTANI MUSZAJ KEZZEL*/
		//std::vector<std::vector<Piece*>>().swap(board);
		/*swap the vector with an empty vector to deallocate the taken memory*/
		int i, j;
		for (i = 0; i < board.size(); ++i)
		{
			for (j = 0; j < board[i].size(); ++j)
				delete board[i][j];
		}
		std::cout << "memory freed\n";
	}
	
	void setup() {
		/*ez a függvény inicializálja a táblát*/
		int i, j;
		/*minden PÁROS sorban, minden párosadik elem fehér*/
		for (i = 0; i < 8; ++i)
		{
			std::vector<Piece*>tmp;
			
			for (j = 0; j < 8; ++j)
			{
				if (i == 0) {
					//Piece *haha = new King(i, j);
					Piece *paraszt = new King(i, j);
					paraszt->setWhite();
					tmp.push_back(paraszt);
				}
				else if (i == 1)
				{
					Piece *lulul = new Pawn(i, j);
					lulul->setWhite();
					tmp.push_back(lulul);
				}
				else if (i == 6)
				{
					Piece *lulul = new Pawn(i, j);
					tmp.push_back(lulul);
				}
				else if (i == 7)
				{
					Piece *lulul = new King(i, j);

					tmp.push_back(lulul);
				}
				else {
					Piece *semmi = new Nullpiece(i, j);
					tmp.push_back(semmi);

				}
			}
			board.push_back(tmp);

		}

	}
	void resetBoard() {}
	/*babukat mozgato függvén*/
	void move_piece(int px, int py, int dx, int dy) {
		/* ha a target destination nem uresbabu, akkor azt "leuti"*/
		if (dynamic_cast<Nullpiece*>(board[dx][dy]))
			std::cout << "target_dest is empty";
		if (board[px][py] ->checkMove(dx, dy)) {
			board[px][py] -> move(*board[px][py],dx, dy);
	/*		std::cout << board[px][py]->getX()<<board[px][py]->getY() << std::endl;*/
			board[dx][dy] = board[px][py];
			//std::cout << board[dx][dy]->getX() << board[px][py]->getY() << std::endl;
			board[px][py] = new Nullpiece(px, py);
			std::cout << "dx, dy:" << dx << " " << dy << " mozgatva\n";
		}



		this->toString();
	}

	void toString() {
		int i, j;

		for (i=0; i<8;++i)
		{
			for (j=0; j<8;++j){

				std::cout<<board[i][j]->toString();
			}
			std::cout << std::endl;
		}
		
	}
	void felszabadit() {}
};