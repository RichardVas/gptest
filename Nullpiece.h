#pragma once
#include "Piece.h"
class Nullpiece : public Piece {



//	int curr_x, curr_y;
public:
	Nullpiece(int x_pos, int y_pos) : Piece(x_pos,y_pos,"Null") {}
	~Nullpiece() {}
	void Abstract() { return; }
	virtual std::string toString() {
		std::string str = "\t";
		
		return str;
	}
	bool checkMove(int dest_x, int dest_y) { return false; }
};