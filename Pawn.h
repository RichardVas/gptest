#pragma once
#include "Piece.h"
#include "Board.h"

class Pawn : public Piece {

public:
	Pawn(int x, int y) : Piece(x, y, "Pawn") {}
	~Pawn() {}
	void Abstract() { return; }

	/*pawn can move vertically and attack in right and left strife */
	bool checkMove(int dest_x, int dest_y/*, std::vector<std::vector<Piece*>>board)*/) {
		bool res = true;
		/*tengelyeket megcserelni*/
		if (std::abs(dest_y - this->getY()) != 0 || std::abs(dest_x - this->getX()) != 1) {
			res = false;
			std::cout << "rossz lepes\n";
		}
		/*strifos megoldast implementalni*/
		return res; }
};