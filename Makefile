CC = g++ -O2 


CDEPMODE = depmode=gcc3
CFLAGS = -O2 -Wall -Wno-switch -pipe -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -I/usr/local/include/freetype2 -I/usr/local/include -include config.h
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
ECHO = echo
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /bin/grep -E

all:
	$(CC) main.cpp particle.cpp particles.cpp kulka.cpp klocek.cpp klocki.cpp paletka.cpp render.cpp globals.cpp `freetype-config --libs --cflags` -lSDL -lSDL_ttf -o main

clean:
	@echo Cleaning up...
	@rm ho
	@echo Done