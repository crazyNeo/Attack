/////////////////
//prototype.h////
/////////////////

#ifndef PROTOTYP_H
#define PROTOTYP_H

#include "att_clas.h"

//in att_game.h
//void main_game();

//int att_game1.h

void setup(Player *player);
void getinput(Player *player);
void move_up(Player *player);
void move_down(Player *player);
void move_left(Player *player);
void move_right(Player *player);
void fireweapon1(Player *player);
void fireweapon2(Player *player,int v);

//void explosion(BITMAP *bmp, int x,int y,int finalcolor);

void update_player(Player *player,BITMAP *dest);
//int weapon_collision(Player *player,int num);
//void update_bullet(Player *player,BITMAP *dest);
void update_box(Player *player,BITMAP *dest);
void create_ground(BITMAP* buffer6);

//in timer.h
void timer1(void);
void rest1(void);

#endif
