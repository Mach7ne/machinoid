#ifndef SIATKA_H
#define SIATKA_H

//*********************************************************************************************//
//                                      Plik siatka.h                                          //
//*********************************************************************************************//

#include <SDL/SDL.h>
#include "globals.h"

//*******************************   Definicja klasy Siatka   **********************************//
class Siatka
{
	
	public:
	float x, y;
	

	Siatka(){x = 0; y = 0;};
	unsigned int blend_add(unsigned int source, unsigned int target);
	void DrawSiatka(unsigned int* siatka, unsigned int* texture);

	~Siatka(){};

};

unsigned int Siatka :: blend_add(unsigned int source, unsigned int target)
{
    unsigned int sourcer = (source >>  0) & 0xff;
    unsigned int sourceg = (source >>  8) & 0xff;
    unsigned int sourceb = (source >> 16) & 0xff;
    unsigned int targetr = (target >>  0) & 0xff;
    unsigned int targetg = (target >>  8) & 0xff;
    unsigned int targetb = (target >> 16) & 0xff;

    targetr += sourcer;
    targetg += sourceg;
    targetb += sourceb;

    if (targetr > 0xff) targetr = 0xff;
    if (targetg > 0xff) targetg = 0xff;
    if (targetb > 0xff) targetb = 0xff;

    return (targetr <<  0) |
           (targetg <<  8) |
           (targetb << 16);
}

void Siatka :: DrawSiatka(unsigned int* siatka, unsigned int* texture)
{
	int tick = SDL_GetTicks();


	for(int i = 0; i < 768; i++)
	{	
		
		for(int j = 0; j < 1024; j++)
		{
			
			int u = j;
      		int v = i;
			
      		
			if(i%11 == 0)
			{
				siatka[(int)(1024 * i + j)] = 0x7f7fff;
				if( tick < 1000 / 10 )
        		{
            		SDL_Delay( ( 1000 / 10 ) - tick );
        		}
			}
			
			if(j%11 == 0)
			{
				siatka[(int)(1024 * i + j)] = 0x7f7fff;

			}
			
			if(i < 256 && j < 256)
			{
				u = j;
				v = i;
			siatka[(int)(1024 * i + j)] = 
          	blend_add((siatka[(unsigned int)(1024 * i + j)]),(texture[(unsigned int)(256 * v + u)]));
			}
			
			
		}

	}

}

//*********************************************************************************************//
//                              Koniec pliku siatka.h                                          //
//*********************************************************************************************//
#endif
