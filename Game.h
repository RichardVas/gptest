#pragma once
#include "Board.h"
#include "JSON.h"

class Game {/**
			 *Class that responsible to run the gameplay, ask and handle the flows of the inputs
			 */
	Board *palya;
	bool gameover = false;
public:
	Game() { start();}
	~Game() { delete palya; }
	void start() {
		int piece_x, piece_y,dest_x,dest_y;
		palya = new Board();
		palya->setup();
		palya->toString();
		while (!isgameover()) {
			std::cin >> piece_x >> piece_y >> dest_x >> dest_y;
			//ide a babuknak a parancsot �tad� f�ggv�ny

			

			palya->move_piece(piece_x, piece_y, dest_x, dest_y);
			/*ide a while loopal v�gig j�rni a json olvas�s eredm�ny�t*/
			if (dest_x == 0 && dest_y == 0)
				setgame();
		}

	}

	bool isgameover() { return this->gameover; }
	void setgame() { gameover = true; }
};

/*
A j�t�kmenet a k�vetkez� :
	1. Board.h setup f�ggv�ny megh�v�sa
	2. egy While(!gameover) ciklus inputokat bek�rni felhaszn�l�kt�l felv�ltva
	3. inputonk�nt gameovert ellen�rzni.


Mikor van v�ge a j�t�knak ? - ha az egyik kir�lyt le�tj�k.
*/