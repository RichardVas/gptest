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
			//ide a babuknak a parancsot átadó függvény

			

			palya->move_piece(piece_x, piece_y, dest_x, dest_y);
			/*ide a while loopal végig járni a json olvasás eredményét*/
			if (dest_x == 0 && dest_y == 0)
				setgame();
		}

	}

	bool isgameover() { return this->gameover; }
	void setgame() { gameover = true; }
};

/*
A játékmenet a következõ :
	1. Board.h setup függvény meghívása
	2. egy While(!gameover) ciklus inputokat bekérni felhasználóktól felváltva
	3. inputonként gameovert ellenõrzni.


Mikor van vége a játéknak ? - ha az egyik királyt leütjük.
*/