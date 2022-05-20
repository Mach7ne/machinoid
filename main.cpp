#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <string>
#include <sstream>
#include <ft2build.h>
#include <iostream>

using namespace std;

//*****************************************************************************************************//
//                                             Plik main.cpp                                           //
//*****************************************************************************************************//

#include "kulka.h"
#include "siatka.h"
#include "timer.h"
#include "init.h"

int main( int argc, char *argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	TTF_Init();
	TTF_Font *font;
	SDL_Color textColor = {0xFF, 0xFF, 0xFF};
	font = TTF_OpenFont("ALIEN5.TTF", 26);

	screen = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWACCEL | SDL_ASYNCBLIT);
	gscreen = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	temp = SDL_ConvertSurface(screen, screen->format, SDL_HWSURFACE);
	temp = SDL_LoadBMP("grid.bmp");
  	grid = SDL_ConvertSurface(temp, screen->format, SDL_HWSURFACE);
  	SDL_FreeSurface(temp);


	int size = 60;
	Particles tabp[size];
	
	
		for(int i = 0; i < size; i++)
		{
		 	tabp[i] = Particles(1000);
		}
	
	Klocki kl;
	Klocki kk(&kl, 60);
	kk.UstawKlocki(&kl);

	Kulka::Kulka kula(1024/2, 768 - 51, 15, 0xffffff, false);

	offset.x = 20;
	offset.y = 700;	
	
	update.start();
	fps.start();

	int frame = 0;

	atexit(SDL_Quit);

//*********************************************************************************************//
//                                     GLOWNA PETLA GRY                                        //
//*********************************************************************************************//    
	while (1)
    {
		
		stringstream time;
		
		framerate++;

		time << "FPS: " << framerate / ( fps.get_ticks() / 1000.f );
		czas = TTF_RenderText_Solid( font, time.str().c_str(), textColor );
		
			//SDL_FillRect(screen,NULL,0);
			//SDL_BlitSurface(texture, 0, screen, 0);
			//SDL_BlitSurface(siatka, 0,  screen, 0);
			SDL_BlitSurface(grid, 0,  screen, 0);
			SDL_BlitSurface(czas, 0,  screen, &offset);

			//SDL_FreeSurface(czas);
			
			kula.handle_collision(paletka, tabp, kl);
			kula.MoveKulka();
		
			render();

			kula.DrawKulka();
			kk.DrawKlocki(&kl, (unsigned int*)screen->pixels);

			SDL_Flip(screen);		
			
			//SDL_UpdateRect(screen, 0, 0, 1024, 768);
			
//*********************************************************************************************//
//                             ZDARZENIA PRZY NACISNIECI KLAWISZY                              //
//*********************************************************************************************//

    	while (SDL_PollEvent(&event)) 
    	{
      		kula.handle_input();
			paletka.handle_input();

//*********************************************************************************************//
//                       JESLI NACISNIEMY ESCAPE NASTEPUJE KONIEC PROGRAMU                     //
//*********************************************************************************************//				
      			if(event.type == SDL_QUIT)
				{
					
					//case SDL_QUIT:
					SDL_FreeSurface(czas);
					SDL_FreeSurface(grid);
					SDL_FreeSurface(screen);
					return(0);
				}
		}
			
//*********************************************************************************************//
//                                      MIERZYMY FPS                                           //
//*********************************************************************************************//
		
		frame++;
        
        if( update.get_ticks() > 1000 )
        {
            
            stringstream caption;
            
            caption << "Average Frames Per Second: " << frame / ( fps.get_ticks() / 1000.f );
            
            SDL_WM_SetCaption( caption.str().c_str(), NULL );
            
            update.start();    
        }

	}
	return 0;
}

//*********************************************************************************************//
//                              Koniec pliku main.cpp                                          //
//*********************************************************************************************//

