#ifndef particles_h
#define particles_h

//*********************************************************************************************//
//                                      Plik particles.h                                       //
//*********************************************************************************************//

#include "particle.h"

//********************************* definicja klasy Particles *********************************//
class Particles : public Particle
{
	public:
		int ile;
		Particle *particles;
		

	public:
		Particles(){};
		Particles(const Particles&);
		Particles& operator=(const Particles&);
		Particles(Particles *p, int ile);
		Particles(int il);
		
		void DeleteParticles();
		
		~Particles()
		{
			//cout << "destruktor Particles" << "  " << sizeof(Particles) << "  " << this << endl;
		};
	
};

//*********************************************************************************************//
//                               Koniec pliku particles.h                                      //
//*********************************************************************************************//
#endif

