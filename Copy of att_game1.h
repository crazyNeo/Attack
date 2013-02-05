///////////////////////
///att_game1.h/////////
///////////////////////


#pragma once
#include <stdio.h>
#include <process.h>//temporary
#include "prototyp.h"
#include <math.h>


#define MOV_X_SPEED 4
#define JUMP_X_SPEED 3
//  ladnu ani khasda ko velocity
#define FELLDOWN_V 3
/*
#ifdef WINDOWSCODING
#include <winalleg.h>
#endif
#include <pthread.h>
*/

inline int inside(int x,int y,int left,int top, int right,int bottom)
{
       if (left<x && x<right && top<y && y<bottom) 
          return 1;
       else
           return 0;
}

inline int collision_gr(Player *player)
{
/*       if (getpixel(back2,player->x-player->get_width(player->get_curframe())/2,  player->y -player->get_height(player->get_curframe())/2 )== PINK  
       &&  getpixel(back2,player->x-player->get_width(player->get_curframe())/2,  player->y +player->get_height(player->get_curframe())/2 )== PINK
       &&  getpixel(back2,player->x+player->get_width(player->get_curframe())/2,  player->y +player->get_height(player->get_curframe())/2 )== PINK      
       &&  getpixel(back2,player->x+player->get_width(player->get_curframe())/2,  player->y -player->get_height(player->get_curframe())/2 )== PINK)
*/
       if (getpixel(back2,player->x,  player->y -player->get_height(player->get_curframe())/2 )== PINK  
       &&  getpixel(back2,player->x,  player->y +player->get_height(player->get_curframe())/2 )== PINK)
       return 0;//collision with ground false
}       

void setup(Player *player)
{
/*
player[0].load("player1.bmp");
    player[1].load("player2.bmp");
    player[0].bullet.load("bullet.bmp");
    player[1].bullet.load("bullet.bmp");
    player[0].crosshair.load("crosshair.bmp");
    player[1].crosshair.load("crosshair.bmp");
    {
       player[0].x=static_cast<float>(20*SCREEN_W/800);
       player[0].y=static_cast<float>(520*SCREEN_H/600);
       player[1].x=static_cast<float>(780*SCREEN_W/800);
       player[1].y=static_cast<float>(520*SCREEN_H/600);
              
       player[0].num=0;
       player[1].num=1;
       player[0].bullet.alive=0;
       player[1].bullet.alive=0;
       
//       player[0].set(45,32);
    }
*/

    for(int num=0;num<pl_no;num++)
    {
            char pl_bmp[12];
//            sprintf(pl_bmp,"player1\\player%d.bmp\0",num+1);
//            sprintf(pl_bmp,"player%d.bmp\0",num+1);
            sprintf(pl_bmp,"player%d\0",1);

//            player[num].load(pl_bmp,10);
            player[num].load(pl_bmp);
//              textprintf_ex(screen,font,200,200,2,5646464,"%s",player);
//    player[num].load("player2.bmp");
//    player[1].load("player2.bmp");
            player[num].weapon1.load("weapon1");
            player[num].weapon2.load("weapon2");
            player[num].weapon3.load("weapon3");
            //    player[1].bullet.load("bullet.bmp");
            player[num].crosshair.load("crosshair");
//            player[num].crosshair.set(60,32);
            player[num].status=0;
            player[num].key_pres_delay=0;


            
            //    player[1].crosshair.load("crosshair.bmp");
            if(num==0)
            {
               player[0].x=static_cast<float>(50*SCREEN_W/1280.0);
//               player[0].crosshair.set(60,32);
//               player[0].fac_angl=0;
            }
            else
            {
               player[1].x=static_cast<float>(buffer2->w-50*SCREEN_W/1280.0);
//               player[1].crosshair.set(60,96);               
//               player[1].fac_angl=1;
            }
//       player[num].y=static_cast<float>(695*SCREEN_H/960.0);
//       player[num].y=static_cast<float>(690*buffer2->h/960.0);       

//       player[num].y=static_cast<float>(785*buffer2->h/960.0);       
       player[num].y=static_cast<float>(500*buffer2->h/960.0);       
       player[num].fac_angl=num;//right 0 left 1;
       player[num].crosshair.set(60,0+128*player[num].fac_angl);
                                                            
       /*                                                     
                                                                        if(num==0)
            player[0].x=static_cast<float>(200*SCREEN_W/1280.0);
            else
            player[1].x=static_cast<float>(1000*SCREEN_W/1280.0);
       player[num].y=static_cast<float>(400*SCREEN_H/960.0);
       */
       
       
       
       
       
 //      textprintf_ex(screen,font,200,200,1,46444,"x=%d   y=%d ",player[num].x,player[num].y  );       rest(1000);       textprintf_ex(screen,font,200,200,1,46444,"                   x=%d   y=%d ",player[num].x,player[num].y  );
//       player[1].y=static_cast<float>(520*SCREEN_H/600);
              
       player[num].num=num;
//       player[1].num=1;
       player[num].weapon1.status=-1;
       player[num].weapon2.status=-1;
       player[num].weapon3.status=-1;
//       player[1].bullet.alive=0;

//SOMETHING ZZ TO BE DONE
         void above_ground(Player *player);
       above_ground(&player[num]);
//       player[0].set(45,32);


//exit(0);                     //TEMPORARY
    }         


}

void above_ground(Player *player)
{
     //lower is positive in height
     int found =0;
     int height=player->y;
     do
     {
         if (getpixel(back2,player->x,  height  +player->get_height(player->get_curframe())/2 )== PINK  && 
             getpixel(back2,player->x,  height +1+player->get_height(player->get_curframe())/2 )== PINK)
         {
             height++;
             if (height >=back2->h)
             {
                 player->y=(back2->h);//might not necessary though
                 return;
             }
         }    
         else if(getpixel(back2,player->x,  height  +player->get_height(player->get_curframe())/2 )!= PINK  && 
                 getpixel(back2,player->x,  height +1+player->get_height(player->get_curframe())/2 )!= PINK)
             height--;
         else
         { 
             player->y=height;
             return;
             found=1;//not necessary though
         }
     }while (found==0);
}

/*
int ht_above_ground(Player *player)
{
     //lower is positive in height
     int found =0;
     int height=player->y;
     do
     {
         if (getpixel(back2,player->x,  height  +player->get_height(player->get_curframe())/2 )== PINK  && 
             getpixel(back2,player->x,  height +1+player->get_height(player->get_curframe())/2 )== PINK)
         {
             height++;
             if (height >=back2->h)
             {
//                 player->y=(back2->h);//might not necessary though
                 return height;
             }
         }    
         else if(getpixel(back2,player->x,  height  +player->get_height(player->get_curframe())/2 )!= PINK  && 
                 getpixel(back2,player->x,  height +1+player->get_height(player->get_curframe())/2 )!= PINK)
             height--;
         else
         { 
//             player->y=height;
             return height;
             found=1;//not necessary though
         }
     }while (found==0);
}
*/

void move_up(Player *player)
{
//     player->crosshair.rel_pos.fac_angl++;
     player->crosshair.rel_pos.fac_angl=     player->crosshair.rel_pos.fac_angl+  4*pow(-1,player->fac_angl);
     player->crosshair.set();
}

void move_down(Player *player)
{
//     player->crosshair.rel_pos.fac_angl--;
     player->crosshair.rel_pos.fac_angl=     player->crosshair.rel_pos.fac_angl-  4*pow(-1,player->fac_angl);
     player->crosshair.set();
}

void move_left(Player *player)
{
//  if (player->x>20) player->x-=5;
  if (player->status==0) player->status=1;
  if (player->fac_angl!=1)
  {
     player->fac_angl=1;
     player->crosshair.rel_pos.fac_angl=128-     player->crosshair.rel_pos.fac_angl;
     player->crosshair.set();     
  }
  if (player->status==1)
  {
      int gr_color_flag=0;
      int x;
      int y;
  
      for(int angl= 128+43;angl>=128-43;angl-=2)//42.6666=60`
      {
         x=player->x+MOV_X_SPEED*cos(angl/128.0*M_PI);
         y=player->y+MOV_X_SPEED*sin(angl/128.0*M_PI);
         if ( gr_color_flag==0 
    //       &&  getpixel(back2,player->x,  player->y -player->get_height(player->get_curframe())/2 )== PINK  
    //       &&  getpixel(back2,player->x,  player->y +player->get_height(player->get_curframe())/2 )== PINK)
           &&  getpixel(back2,x,  y -player->get_height(player->get_curframe())/2 )== PINK  
           &&  getpixel(back2,x,  y +player->get_height(player->get_curframe())/2 )== PINK)
           
           gr_color_flag++;
           
           
         else if( gr_color_flag==1 
           &&  getpixel(back2,x,  y -player->get_height(player->get_curframe())/2 )== PINK  
           &&  getpixel(back2,x,  y +player->get_height(player->get_curframe())/2 )!= PINK)
           
           {
               gr_color_flag++;
               break;
           }
    //              textprintf_ex(screen,font,500,500,2,5646464,"x=%f --  %d",player->x,x);
    //              textprintf_ex(screen,font,500,520,2,5646464,"y=%f --  %d",player->y,y);
    //              textprintf_ex(screen,font,500,540,2,5646464,"flag= --  %d",gr_color_flag);
    //              rest(1000);
                  
           
           
      }
      switch (gr_color_flag)
      {
             case 2:
                    player->x=x;
                    player->y=y;              
                    above_ground(player);
                  break;
             case 1:
                    player->x-=MOV_X_SPEED;
                    player->jump_ht=0;
                    player->jump_vel=FELLDOWN_V;
                    player->jump_phase=1;  
                    player->status=2;
                  break;
      }
//      textprintf_ex(screen,font,500,540,2,5646464,"flag= --  %d   %d",gr_color_flag,player->status);
  }
  else  player->x-=JUMP_X_SPEED;
  // collision detection with the ground

//  if (player->status==1) above_ground(player);

}//end move_left


void move_right(Player *player)
{
//  if (player->x>20) player->x-=5;
  if (player->status==0) player->status=1;
  if (player->fac_angl!=0)
  {
     player->fac_angl=0;
     player->crosshair.rel_pos.fac_angl=128-     player->crosshair.rel_pos.fac_angl;
     player->crosshair.set();     
  }
  if (player->status==1)
  {
      int gr_color_flag=0;
      int x;
      int y;
  
      for(int angl= 256-43;angl<=256+43;angl+=2)//42.6666=60`
      {
         x=player->x+MOV_X_SPEED*cos(angl/128.0*M_PI);
         y=player->y+MOV_X_SPEED*sin(angl/128.0*M_PI);
         if ( gr_color_flag==0 
    //       &&  getpixel(back2,player->x,  player->y -player->get_height(player->get_curframe())/2 )== PINK  
    //       &&  getpixel(back2,player->x,  player->y +player->get_height(player->get_curframe())/2 )== PINK)
           &&  getpixel(back2,x,  y -player->get_height(player->get_curframe())/2 )== PINK  
           &&  getpixel(back2,x,  y +player->get_height(player->get_curframe())/2 )== PINK)
           
           gr_color_flag++;
           
           
         else if( gr_color_flag==1 
           &&  getpixel(back2,x,  y -player->get_height(player->get_curframe())/2 )== PINK  
           &&  getpixel(back2,x,  y +player->get_height(player->get_curframe())/2 )!= PINK)
           
           {
               gr_color_flag++;
               break;
           }
    //              textprintf_ex(screen,font,500,500,2,5646464,"x=%f --  %d",player->x,x);
    //              textprintf_ex(screen,font,500,520,2,5646464,"y=%f --  %d",player->y,y);
    //              textprintf_ex(screen,font,500,540,2,5646464,"flag= --  %d",gr_color_flag);
    //              rest(1000);
                  
           
           
      }
      switch (gr_color_flag)
      {
             case 2:
                    player->x=x;
                    player->y=y;              
                    above_ground(player);
                  break;
             case 1:
                    player->x+=MOV_X_SPEED;
                    player->jump_ht=0;
                    player->jump_vel=FELLDOWN_V;
                    player->jump_phase=1;  
                    player->status=2;
                  break;
      }
//      textprintf_ex(screen,font,500,540,2,5646464,"flag= --  %d   %d",gr_color_flag,player->status);
  }
  else  player->x+=JUMP_X_SPEED;
  textprintf_ex(screen,font,500,560,2,5646464,"status= --  %d   ",player->status);
  // collision detection with the ground

//  if (player->status==1) above_ground(player);

}//end move_right

/*
void move_right(Player *player)
{
  if (player->x<buffer2->w-20 ) player->x+=5;
  if (player->status==0) player->status=1;
  if (player->fac_angl!=0)
  {
     player->fac_angl=0;
     player->crosshair.rel_pos.fac_angl=128-     player->crosshair.rel_pos.fac_angl;
     player->crosshair.set();
  }
//  textprintf_ex(screen,font,45,45,46213124,-1,"move_right x=%f ",player->x);
//  rest(1000);

  // collision detection with the ground
  if (player->status==1) above_ground(player);
//  if (player->status==1) player->y=ht_above_ground(player);
}//end move_right
*/


void change_b_status(Player *player)
{
     switch (player->binaculor.status)
     {
            case 2:
            case 1:
                 
                 player->binaculor.status=0;
                 break;
            default:
                 player->binaculor.status=1;
                 player->binaculor.x=player->x;
                 player->binaculor.y=player->y;
     }
     player->key_pres_delay=5;     
}

void jump(Player *player)
{
     if (player->status!=2) player->status=2;     
     player->jump_ht=0;
     player->jump_vel=3;
     player->jump_phase=0;
}//end jump


void fireweapon1(Player *player)
{
//     BITMAP *bullet=load_bitmap("bullet.bmp",NULL);
       player->key_pres_delay=5;
       if (player->weapon1.status!=0)
       {
          player->weapon1.status=0;
                    
          {
//            player->bullet.x=player->crosshair.x;
//            player->bullet.y=player->crosshair.y;
            player->weapon1.x=player->x;
            player->weapon1.y=player->y;
            player->weapon1.fac_angl=player->crosshair.rel_pos.fac_angl;

            player->weapon1.x1=player->weapon1.x;
            player->weapon1.y1=player->weapon1.y;
            
            player->weapon1.counter=0;//i am using it to make a delay after use of every weapon
          }
          
    textprintf_ex(screen,font,23,30,1444,0,"weapon%f , %f ,",player->weapon1.x,player->weapon1.y);
    textprintf_ex(screen,font,23,40,1231444,0,"weapon%f , %f ,",player->x,player->y);
    textprintf_ex(screen,font,23,50,1231444,0,"weapon%f , %f ,",player->crosshair.rel_pos.x,player->crosshair.rel_pos.y);
    textprintf_ex(screen,font,23,60,1231444,0,"num %d",player->num);
//    rest(3000);
            
       }
}//end fireweapon1

void fireweapon2(Player *player,int v)
{
//     BITMAP *bullet=load_bitmap("bullet.bmp",NULL);
//set vel according to the key pressed
       player->key_pres_delay=5;
       {
          player->weapon2.status=0;
                    
          {
//            player->bullet.x=player->crosshair.x;
//            player->bullet.y=player->crosshair.y;
            player->weapon2.x=player->x;
            player->weapon2.y=player->y;
            player->weapon2.fac_angl=player->crosshair.rel_pos.fac_angl;

            player->weapon2.x1=player->weapon2.x;
            player->weapon2.y1=player->weapon2.y;
            
            player->weapon2.counter=0;
            player->weapon2.bounce=0;
            player->weapon2.vel=v;
          }
          
    textprintf_ex(screen,font,23,30,1444,0,"weapon%f , %f ,",player->weapon2.x,player->weapon2.y);
//    textprintf_ex(screen,font,23,40,1231444,0,"weapon%f , %f ,",player->x,player->y);
//    textprintf_ex(screen,font,23,50,1231444,0,"weapon%f , %f ,",player->crosshair.rel_pos.x,player->crosshair.rel_pos.y);
//    textprintf_ex(screen,font,23,60,1231444,0,"num %d",player->num);
//    rest(3000);
            
       }
}//end fireweapon2



void fireweapon3(Player *player,int v)
{
//     BITMAP *bullet=load_bitmap("bullet.bmp",NULL);
//set vel according to the key pressed
      player[0].binaculor.status=0;
       {
          player->weapon3.status=0;
                    
          {
//            player->bullet.x=player->crosshair.x;
//            player->bullet.y=player->crosshair.y;
            player->weapon3.x=player->x;
            player->weapon3.y=player->y;
            player->weapon3.fac_angl=player->crosshair.rel_pos.fac_angl;

            player->weapon3.x1=player->weapon3.x;
            player->weapon3.y1=player->weapon3.y;
            
            player->weapon3.counter=0;
            player->weapon3.bounce=0;
            player->weapon3.vel=v;
          }
          
    textprintf_ex(screen,font,23,30,1444,0,"weapon  333%f , %f ,",player->weapon3.x,player->weapon3.y);
//    textprintf_ex(screen,font,23,40,1231444,0,"weapon%f , %f ,",player->x,player->y);
//    textprintf_ex(screen,font,23,50,1231444,0,"weapon%f , %f ,",player->crosshair.rel_pos.x,player->crosshair.rel_pos.y);
//    textprintf_ex(screen,font,23,60,1231444,0,"num %d",player->num);
//    rest(3000);
            
       }
}//end fireweapon3



void getinput(Player *player)
{
     switch (player[0].binaculor.status)
     {
       case 3:
                         
//               textprintf_ex(screen,font,23,100,1444,0,"------------------");               

       if (key[KEY_W])           move_up(&player[0]);
       if (key[KEY_S])           move_down(&player[0]);
              if (player->key_pres_delay<1)
              {
                 static int vel3=0;
                   if (key[KEY_3])
                   {
                      if (player[0].weapon3.status!=0 && vel3<100) vel3+=5;
//                      textprintf_ex(screen,font,23,100,1444,0,"|||||||||||||||||||||||");
                   }
                   else if (vel3 && player[0].weapon3.status!=0)
                   {
                      fireweapon3(&player[0],vel3);//granite
                      vel3=0;
                   }
               }
               else        player->key_pres_delay--;     
            break;
       case 2:
              if (player->key_pres_delay<1)
              {
                  if (key[KEY_3])
                  {
                        player->key_pres_delay=5;
                        player[0].binaculor.status=3;
                        player[0].weapon3.tar_x=player[0].binaculor.x;
                        player[0].weapon3.tar_y=player[0].binaculor.y;
                        textprintf_ex(buffer2,font,player[0].weapon3.tar_x,player[0].weapon3.tar_y,1444,0," ");
                  }                  
              }
              else        player->key_pres_delay--;
         
       case 1:
            if (key[KEY_W])           player->binaculor.move_up(buffer2);
            if (key[KEY_S])           player->binaculor.move_down(buffer2);
            if (key[KEY_A])           player->binaculor.move_left(buffer2);
            if (key[KEY_D])           player->binaculor.move_right(buffer2);
            if (player[0].key_pres_delay<1)
            {
               if (key[KEY_V] && player[0].status==0)           change_b_status(&player[0]);
            }                   
            else player[0].key_pres_delay--;
                 break;
            default:
      for (int num=0;num<2;num++)
       if(player[num].status ==1) player[num].status=0;
       if (key[KEY_W])           move_up(&player[0]);
       if (key[KEY_S])           move_down(&player[0]);
       if (key[KEY_A])           move_left(&player[0]);
       if (key[KEY_D])           move_right(&player[0]);
       if (key[KEY_SPACE] && player[0].status!=2)       jump(&player[0]);
       
       //the fireing keys
       if (player[0].key_pres_delay<1)
       {
           if (key[KEY_V] && player[0].status==0)           change_b_status(&player[0]);//player[0].status ==8;
           if (key[KEY_1])           fireweapon1(&player[0]);//simple missile
           /*
           //the first idea
           if (key[KEY_2]  && player[0].weapon2.status!=0)
           {
              int vel=0;
              while(key[KEY_2]) if(vel<100) { vel+=5; rest(2);};//this one needs to be threaded as well
              fireweapon2(&player[0],vel);//granite
           }
           */
           //second method
           /*
           static int vel1=0;
           if (key[KEY_2]  && player[0].weapon2.status!=0 && vel1<100) vel1+=5;
           else if (vel1 && player[0].weapon2.status!=0)
           {
              fireweapon2(&player[0],vel1);//granite
              vel1=0;
           }
           */
           static int vel2=0;
           if (key[KEY_2])
           {
              if (player[0].weapon2.status!=0 && vel2<100) vel2+=5;
           }
           else if (vel2 && player[0].weapon2.status!=0)
           {
              fireweapon2(&player[0],vel2);//granite
              vel2=0;
           }
           if (key[KEY_3]  && player[0].status==0)
           {
                                      player->binaculor.status=2;//homing missile
                                      player->binaculor.x=player->x;
                                      player->binaculor.y=player->y;
                                      player->key_pres_delay=5;
           }
       }
       else player[0].key_pres_delay--; 
     }
     
       if(Real_Time==1)
       {
           if (key[KEY_UP])    move_up(&player[1]);
           if (key[KEY_DOWN])  move_down(&player[1]); 
           if (key[KEY_LEFT])  move_left(&player[1]);
           if (key[KEY_RIGHT]) move_right(&player[1]);
           if (key[KEY_7])     fireweapon1(&player[1]);
           if (key[KEY_8]  &&  player[1].weapon2.status!=0)
           {
              int vel=0;
              while(key[KEY_8]) if(vel<100) { vel+=5; rest(2);};//this one needs to be threaded as well
              fireweapon2(&player[1],vel);//granite
           }
       }
     
}//end getinput

void update_fall(Player *player)
{
             if (!collision_gr(player))//if !->gr collision false
             {
           player->jump_ht++;
           player->jump_vel+=9.8*player->jump_ht/5000.0;
           player->y+=player->jump_vel;
                if (player->y >=back2->h)
                {
                   player->y=back2->h;
                }
             }
             else
             {
                            player->status=0;
                            above_ground(player);
             }          

}
void update_jump(Player *player)
{
//    textprintf_ex(screen,font,100,100,4654651,-1,"jump_phase  %d     jump_ht  %d",player->jump_phase,player->jump_ht);
//    rest(1000);
     if (player->jump_phase==0)
     { 
       if (player->jump_vel>0  && !collision_gr(player))//if !->gr collision false) 
       {
           player->jump_ht++;
           player->jump_vel-=9.8*player->jump_ht/5000.0;
           player->y-=player->jump_vel;
       }
       else
       {
          player->jump_phase++;//to stop momentarily on the top of the height
          player->jump_ht=0;
          player->jump_vel=0;
       }
     }
     else if(player->jump_phase==1)
     {
//             --player->jump_ht;
               
               update_fall(player);
       //no need to check jump< or =2 0 because we will check for ground.
     }
//     else player->jump_phase++;//to stop momentarily on the top of the height
     //then check collision
     //now just with the ground.
//     above(ground);//no not this one
     
}//end update jump

void gameover(int i)
{
     textprintf_ex(screen,font,300,300,4564564,-1,"Game over");
     rest(3000);
}

void updateexplosion(BITMAP *bmp,Player *player)
{    
     Exp_position *p;
     p=explosions.exp_pos;
     while (p!=NULL){
        for (int n=0;n<2;n++){
          if (p->count==EXPLOSION_COUNT)
          {
               int x,y;
               x=player[n].x;
               y=player[n].y;
               p->dist[n]=pow(  (x-p->pos.x)*(x-p->pos.x)
                          +(y-p->pos.y)*(y-p->pos.y),.5);
//             p->count--;
//             explosion(bmp,p->pos.x,p->pos.y,GREEN);
//                     textprintf_ex(buffer2,font,200,200,0,46544454,"%d ",p->count);
          }
          else if (p->count==1 && p->dist[n]<32+1)
          {
               player[n].life-=(32-p->dist[n])/2;
               player[n].x-=MOV_X_SPEED;
               player[n].jump_ht=0;
               player[n].jump_vel=FELLDOWN_V;
               player[n].jump_phase=1;  
               player[n].status=2;
//                      rest(200);
          }
        }
        
          p=p->next;
     }
     explosions.update_explosion(buffer2);
}

void update_player(Player *player,BITMAP *dest)
{
//update player
  for(int n=0;n<pl_no;n++)   
  {                    
          //collision detection with the explosion
          
          /*
          for(int num=0;num<2;num++)
          {
                  if (explosions.create_col_flag[num].check_flag==1){
                    int x,y;
                    int dist;
                    x=player[n].x;
                    y=player[n].y;
                    //dist2=pow(x-explosions.create_col_flag[n].x,2)+pow(y-explosions.create_col_flag[n].y,2);
                    //dist=pow(  (x-explosions.create_col_flag[n].x)*(x-explosions.create_col_flag[n].x)
                    //      +(y-explosions.create_col_flag[n].y)*(y-explosions.create_col_flag[n].y),.5);
                    
//                    if( dist2<32+1){
//                      player[n].life-=(32-dist)/2;
//                      rest(200);
                    }
                  }
          }
          */
          
//       draw_sprite(dest,player[n].get_image(),player[n].x-player[n].get_image()->w/2,player[n].y-player[n].get_image()->h/2);
         if (player[n].status==2)
         {
            update_jump(&player[n]);
         }
     player[n].update_sprite();//frame updated only for player
     player[n].draw(dest);  
     textprintf_ex(dest,font,player[n].x-player[n].get_width()/2,player[n].y-player[n].get_height()/2-5,4554554,-1,"%d",player[n].life);
     player[n].update_cros();

     player[n].crosshair.draw(dest);
     }
     explosions.create_col_flag[0].check_flag=0;
     explosions.create_col_flag[1].check_flag=0;
}//end update player

//for 1 hit explode
int weapon_collision(Player *player,int num)//is a friend
{
    int flag=0;
     if (player[num].weapon1.x<0 || player[num].weapon1.x>buffer2->w  || player[num].weapon1.y>buffer2->h)//out of screen
        flag=1;
     else if (getpixel(back2,player[num].weapon1.x,player[num].weapon1.y)!=PINK)//hit the ground
          flag=1;
     else
     {
         for (int n=0;n<pl_no;n++)
         {
             if (n==num) continue;             else  //this one should be removed but is not because the bullet passes through the boudy of the player in the beginning
              if (inside(player[num].weapon1.x,player[num].weapon1.y,
                  player[n].x-player[n].get_width()/2,player[n].y-player[n].get_height()/2,
                  player[n].x+player[n].get_width()/2,player[n].y+player[n].get_height()/2))
             flag=1;
         }
     }     
     if (flag==1) return 1;
     else return 0;
}
     
//for bounce and time explode
int weapon_collision2(Player *player,int num)//is a friend// this one should be merged with the above using pointer for weapon
{
     int flag=0;
     if (player[num].weapon2.x<0 || player[num].weapon2.x>buffer2->w  || player[num].weapon2.y>buffer2->h)//out of screen
        flag=1;
     else if (getpixel(back2,player[num].weapon2.x,player[num].weapon2.y)!=PINK)//hit the ground
          flag=1;
     else
     {
         for (int n=0;n<pl_no;n++)
         {
             if (n==num) continue;             else  //this one should be removed but is not because the bullet passes through the boudy of the player in the beginning
              if (inside(player[num].weapon2.x,player[num].weapon2.y,
                  player[n].x-player[n].get_width()/2,player[n].y-player[n].get_height()/2,
                  player[n].x+player[n].get_width()/2,player[n].y+player[n].get_height()/2))
             flag=1;
         }
     }     
     if (flag==1) return 1;
     else return 0;
}
     // i guess this wont be needed we can manage using the class
     
//for bounce and time explode
int weapon_collision3(Player *player,int num)//is a friend// this one should be merged with the above using pointer for weapon
{
     int flag=0;
     if (player[num].weapon3.x<0 || player[num].weapon3.x>buffer2->w  || player[num].weapon3.y>buffer2->h)//out of screen
        flag=1;
     else if (getpixel(back2,player[num].weapon3.x,player[num].weapon3.y)!=PINK)//hit the ground
          flag=1;
     else
     {
         for (int n=0;n<pl_no;n++)
         {
             if (n==num) continue;             else  //this one should be removed but is not because the bullet passes through the boudy of the player in the beginning
              if (inside(player[num].weapon3.x,player[num].weapon3.y,
                  player[n].x-player[n].get_width()/2,player[n].y-player[n].get_height()/2,
                  player[n].x+player[n].get_width()/2,player[n].y+player[n].get_height()/2))
             flag=1;
         }
     }     
     if (flag==1) return 1;
     else return 0;
}
     // i guess this wont be needed we can manage using the class     
     
     
/*
void update_weapon(Player *player,BITMAP *dest)
{
  for (int num=0;num<pl_no;num++)
//int num=1;
  if (player[num].weapon.status==0)
  {     
    int v=60;
//    float th=player[num].crosshair.rel_pos.fac_angl/128.0*M_PI;
    float th=player[num].weapon.fac_angl/128.0*M_PI;
    {
          player[num].weapon.x2=(v*cos(th)*player[num].weapon.counter );//d*pow(-1,num);
          player[num].weapon.y2=(-v*sin(th)*player[num].weapon.counter ) +.5*9.8*player[num].weapon.counter*player[num].weapon.counter;

          player[num].weapon.x=player[num].weapon.x2+player[num].weapon.x1-player[num].weapon.get_width()/2;
          player[num].weapon.y=player[num].weapon.y2+player[num].weapon.y1-player[num].weapon.get_height()/2;
//          int y=player[num].weapon.y1-player[num].weapon.get_image()->h/2;

          textprintf_ex(dest,font,23,20,4554554,2,"angl%f , %f ,%f",th,cos(th),sin(th));
          textprintf_ex(dest,font,23,30,4554554,0,"weapon%f , %f ,%f",player[num].weapon.x2,player[num].weapon.y2);
          textprintf_ex(dest,font,23,40,4554554,1,"weapon %d ,%d",player[num].weapon.x,player[num].weapon.y);
          draw_sprite(dest,player[num].weapon.get_image(),player[num].weapon.x,player[num].weapon.y);
          
//          textprintf_ex(dest,font,23,70,4554554,0,"weapon%f , %f ,%f",player[num].crosshair.pos.x,player[num].crosshair.pos.y);
          textprintf_ex(dest,font,23,80,4554554,0,"weapon%f , %f ,%f",player[num].x,player[num].y);          
//          draw_sprite(screen,player[num].bullet.get_image(),200,player[num].bullet.y1);
//          draw_sprite(screen,player[num].bullet.get_image(),10,12);

          player[num].weapon.counter+=.15; 
          //rest(30);
//rest(1000);
          
    }
    if (weapon_collision(player,num)) player[num].weapon.status=-1;
  }
}
*/
//this could be threaded
//this is defined as class now


/*
void explosion(BITMAP *bmp, int x,int y,int finalcolor)
{
int color,size=30;
circlefill(bmp, x, y, 33, finalcolor);
for (int n=0; n<30 ||size>0; n++)
{
//generate a random color
color = makecol(200+rand()%55,200+rand()%55,rand()%50);
//random explosion size

//draw the random filled circle
//circlefill(bmp, x, y, size, color);
//short pause
//rest(2);
circlefill(bmp, x, y, size, color);
size -= (1+rand()%5);
}

//missile tracker looks for this explosion color
//circlefill(bmp, x, y, 30, finalcolor);
circlefill(back2, x, y, 30, PINK);
}//end explosion
*/

void update_box(Player *player,BITMAP *dest)
{
    clear_to_color(dest,PINK);
    rect(dest,0,0,dest->w-1,dest->h-1,0);
    for(int num=0;num<pl_no;num++)
    {
       circle(dest,player[num].x*dest->w/buffer2->w,player[num].y*dest->h/buffer2->h,3,4546544);
       circlefill(dest,player[num].x*dest->w/buffer2->w,player[num].y*dest->h/buffer2->h,2,6544);
       if (player[num].weapon1.status==0)
//          putpixel(dest,player[num].bullet.x,player[num].bullet.y,0);
          circlefill(dest,player[num].weapon1.x*dest->w/buffer2->w,player[num].weapon1.y*dest->h/buffer2->h,1,4546544);
    }
//    rectfill(dest,0,0,dest->w,dest->h);
}

void create_ground(BITMAP* buffer6)
{
//    float a[2*size];
    int size=buffer6->w/2/5;
    float *a=new float[2*size];
    //initialize the random number seed
    srand(time(NULL));

    //for (int k=1;k<100;k++)
    {
    }
    

    
    
    
    BITMAP *buffer5=create_bitmap(buffer6->w,buffer6->h);
    clear_to_color(buffer5,PINK);
    
    BITMAP *tile=load_bitmap("tile.bmp",NULL);
    a[0]=500;    
         //textprintf_ex(buffer5,font,10,a[0],0,4564,"%d",a[0]);
         putpixel(buffer5,0,a[0],GREEN);  
//         putpixel(screen,0,a[0],GREEN);
         
    a[1]=a[0];    
         //textprintf_ex(buffer5,font,25,a[1],0,4564,"%d",a[1]);
         putpixel(buffer5,1,a[1],GREEN);  
         
         line(buffer5,(0)*5,a[0],1*5,a[1],GREEN);
//         putpixel(screen,1,a[1],GREEN);
   for (int i=0;i<buffer5->w;i+=tile->w)
   {
       for(int j=0;j<buffer5->h;j+=tile->h)
       {
           draw_sprite(buffer6,tile,i,j);
       }
   }
   for (int k=2;k<size;k++)
    {
//            textprintf_ex(screen,font,800,600,0,0,"1");
              int tr=0;
    do
        {
              float d=a[k-1]-a[k-2];
              if (d>8) d=8;
              else if (d<-8) d=-8;
              
//              if (k%10!=0) a[k]=a[k-1]+d;
//              else 
                     a[k]=a[k-1]+d+(rand()%3-1)*1.5;
              if (tr++>3) 
                 if (a[k]<80) a[k]=80;//upper limit
                 else if (a[k]>(buffer5->h-100)) a[k]=(buffer5->h-100);//lower limit
              
        }
        while (a[k]>(buffer5->h-100) || a[k]<80);
        putpixel(buffer5,k*5,a[k],GREEN);  
        line(buffer5,(k-1)*5,a[k-1],k*5,a[k],GREEN);
//        putpixel(screen,(k*5)%SCREEN_W,a[k],GREEN);  
//     textprintf_ex(buffer5,font,10+k*15,a[k],0,4564,"%d",a[k]);
    }
    

    ///*
    for(int k=size;k<2*size;k++)
    {
            a[k]=a[2*size-k-1];
        putpixel(buffer5,k*5,a[k],GREEN);  
        line(buffer5,(k-1)*5,a[k-1],k*5,a[k],GREEN);
//        putpixel(screen,(k*5)%SCREEN_W,a[k],GREEN);  
    }
    
    //*/
   // floodfill(buffer5,2,598,456456);
    line(buffer5,(2*size-1)*5,a[2*size-1],buffer5->w,a[2*size-1],GREEN);


//    int k=0;
//    textprintf_ex(screen,font,300,300,0,4564,"gsdaasdf");
//    rest(1000);
    
/*    while (!key[KEY_ESC]) 
    {
          
          blit(buffer5,screen,k,0,0,0,SCREEN_W,SCREEN_H);
          if( k++>2000-SCREEN_W)
          {   k=0; rest(4000);}
          rest(5);
    }
*/  
        floodfill(buffer5,0,0,GREEN);
        
//    k=0;
//    textprintf_ex(screen,font,300,300,0,4564,"gsdaasdf");
//    rest(1000);
/*    while (!key[KEY_ESC]) 
    {
          
          blit(buffer5,screen,k,0,0,0,SCREEN_W,SCREEN_H);
          if( k++>2000-SCREEN_W) k=0;
          rest(10);
    }
*/
    masked_blit(buffer5,buffer6,0,0,0,0,buffer6->w,buffer6->h);
 
    floodfill(buffer6,0,0,PINK);    
//    textprintf_ex(screen,font,300,300,0,4564,"gsdaasdf");
//    rest(1000);

    destroy_bitmap(buffer5);
    destroy_bitmap(tile);
    delete[] a;
    
}
