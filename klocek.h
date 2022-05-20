#ifndef KLOCEK_H
#define KLOCEK_H

//*********************************************************************************************//
//                                      Plik klockek.h                                         //
//*********************************************************************************************//

//*********************************   Definicja klasy Klocek   ********************************//

#include "particle.h"

class Klocek
{
	public:
			float x, y;
			float dl, sz;
			Particle *particles;

			Klocek(int ile);
			Klocek(){ x = 15; y = 25; dl = 40; sz = 25;};
			Klocek(float _x, float _y, float _dl, float _sz); 
			//void DeleteKlocek(Klocek *k);
			void DrawKlocek(unsigned int *ptr);
			void UstawKlocki(Klocek &k);
			
			virtual ~Klocek(){};

};

//*********************************************************************************************//
//                                  Koniec pliku klockek.h                                     //
//*********************************************************************************************//
#endif






