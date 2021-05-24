
#include "Game.h"
#include <iostream>
#include "JSON.h"
/*
JSON BEOLVAS
Exception kezelés
Game osztály- játékmenet vezérlése
További Piecek implementálása

FULL OOP -
cout csak mainben
ami const lehet az legyen
ami private lehet az legyen - mindenhova getter setter ami private
külön könyvtár - külön cpp 



sáncolás, döntetlen, ha marad idõ
*/

/*FEJLESZTÉSI ÖTLET: argumentumként adjak egy input.txt-t ha nem üres akkor olvassa be a lépéseket
ellenkezõ esetben kérjen inputokat és akkor az inputok lehetnének json formátumban, ezzel is okot adva az
olvasó könyvtár megírásának
*/
int main(int argc, char* argv[])
{
	//for (int i = 0; i < argc; ++i)
	//{
	//	std::cout << argv[i] << std::endl;
	//}



//	auto steps_from_file = JSON::parseJson(argv[1]);
	Game *ujgame = new Game();

	/*algortimus: minden paros sorban, minden paros elem feher*/
	int i, j;
	int k;

	bool color = true;

	for (i = 0; i < 8; ++i) {

		bool color = true;
		if (i % 2 == 0) {
			for (k = 0; k < 8; ++k)
				if (color) {
					std::cout << "    ";
					color = !color;
				}
				else {
					std::cout << "####";
					color = !color;
				}
		}
		else
			for (k = 0; k < 8; ++k)
				if (color) {
					std::cout << "####";
					color = !color;
				}
				else {
					std::cout << "    ";
					color = !color;
				}
		std::cout << std::endl;
			

		for (j = 0; j < 8; ++j) {



			if (i % 2 == 0) // ha a sor paros, akkor minden paros elem Feher
			{
				if (j % 2 == 0)
				{
					std::cout << "  W ";
				}
				else
					std::cout << "# B#";
			}
			else //ha a sor paratlan, akkor minden paratlanodik feher
			{
				if (j % 2 == 0)
					std::cout << "# B#";
				else
					std::cout << "  W ";

			}
			
		}
		std::cout << std::endl;
		color = true;
		if (i % 2 == 0) {
			for (k = 0; k < 8; ++k)
				if (color) {
					std::cout << "    ";
					color = !color;
				}
				else {
					std::cout << "####";
					color = !color;
				}
		}
		else
			for (k = 0; k < 8; ++k)
				if (color) {
					std::cout << "####";
					color = !color;
				}
				else {
					std::cout << "    ";
					color = !color;
				}
		std::cout << std::endl;


	std::cout << std::endl;
	}

	delete ujgame;
	return 0;
}