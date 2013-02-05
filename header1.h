#ifndef HEADER1_H
#define HEADER1_H

#include "allegro.h"


#define PINK makecol(255,0,255)
#define GREEN makecol(0,255,0)

//attgame1.h att_game.h
//#define BUFFER2_W the value should be greater than 1280 for smooth ground
//#define BUFFER2_H the value should be greater than 960 for smooth ground
//#define BUFFER2_W 3000
//#define BUFFER2_H 1440
#define BUFFER2_W 1500
#define BUFFER2_H 960


#define WINDOWSCODING// to include winalleg.h to avoid colflict with pthread.h

//global variables
BITMAP *buffer,*buffer2;
BITMAP *back2;
int Real_Time;
int pl_no;
//class Explosion;
//Explosion explosions;



#endif
