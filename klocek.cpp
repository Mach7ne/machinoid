//*********************************************************************************************//
//                                      Plik klockek.cpp                                       //
//*********************************************************************************************//

#include "klocek.h"

//*********************************   Konstruktor z parametrami   *****************************//
Klocek :: Klocek(float _x, float _y, float _dl, float _sz)
{
	x = _x;
	y = _y;
	dl = _dl;
	sz = _sz;
}

Klocek :: Klocek(int ile)
{
	particles = new Particle[ile];
}

void Klocek :: DrawKlocek(unsigned int *ptr)
{
	int color;
	int kr = (int)(50);
	int kg = (int)(180);
	int kb = (int)(10);
	int c = 0;

	for(int i = (int)y; i < (int)y+sz; i++, c+=5)
		for(int j = (int)x; j < (int)x+dl; j++)
			{
				
				color = (kr + c << 16 ) + ( kg - c << 8 ) + ( kb + c );
					
				ptr[1024*i + j] = color;
			}
}

//*********************************************************************************************//
//                                   Koniec pliku klockek.cpp                                  //
//*********************************************************************************************//

