/////////////////////
//////header1.h//////
/////////////////////

#pragma once
#include "allegro.h"
#include "header1.h"
#include "prototyp.h"
#include "att_clas.h"
#include "att_game1.h"
#include "att_timer.h"

void RealTime_Game()       
{
    Real_Time=1;
    pl_no=2;
     
    set_color_depth(32);
//    set_gfx_mode(1,800,600,0,0);
    set_gfx_mode(2,800,600,0,0);
//    set_gfx_mode(2,1024,768,0,0);
//    set_gfx_mode(1,1280,960,0,0);

    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    buffer2=create_bitmap(BUFFER2_W*SCREEN_W/1280,BUFFER2_H*SCREEN_H/960);
//    buffer2=create_bitmap(BUFFER2_W*SCREEN_W/1280,SCREEN_H);
    BITMAP *buffer3=create_bitmap(300,113);
    BITMAP *backgrd=load_bitmap("backgrd.bmp",NULL);
    BITMAP *back=load_bitmap("background.bmp",NULL);
//    BITMAP *back2=load_bitmap("back.bmp",NULL);
    back2=create_bitmap(buffer2->w,buffer2->h);// as global
//    BITMAP *back2=create_bitmap(SCREEN_W,SCREEN_H);
    create_ground(back2);
    
    
    Player player[2];
//    Player *player;
//    player=new Player[pl_no];
    
    setup(player);
//        rest(3000);
//    exit(0);                     //TEMPORARY

    stretch_blit(backgrd,buffer,0,0,backgrd->w,backgrd->h,0,0,buffer->w,buffer->h);
    stretch_blit(back,buffer2,0,0,back->w,back->h,0,0,buffer2->w,buffer2->h);
    masked_blit(back2,buffer2,0,0,0,0,back2->w,back2->h);
//    stretch_blit(back,buffer,0,0,back->w,back->h,0,0,SCREEN_W-1,SCREEN_H-1);
//    stretch_blit(back,buffer,0,0,SCREEN_W,SCREEN_H,0,0,SCREEN_W,SCREEN_H);

//    masked_stretch_blit(back2,buffer,0,0,back2->w,back2->h,0,buffer->h-(buffer->w*back2->h)/back2->w,buffer->w,(buffer->w*back2->h)/back2->w);

//      masked_stretch_blit(back2,buffer2,0,0,back2->w,back2->h,0,buffer2->h-(buffer2->w*back2->h)/back2->w,buffer2->w,(buffer2->w*back2->h)/back2->w);

//      masked_blit(back2,screen,0,0,0,0,SCREEN_W,SCREEN_H);
//    masked_stretch_blit(back2,screen,0,0,back2->w,back2->w,0,0,SCREEN_W,SCREEN_H);
//clear_bitmap(buffer2);

//      masked_blit(buffer2,screen,0,0,0,0,SCREEN_W,SCREEN_H);

//displaying the ground
    masked_stretch_blit(buffer2,screen,0,0,buffer2->w,buffer2->h,0,0,SCREEN_W,SCREEN_H);

    for(int num=0;num<pl_no;num++)
    {
//        player[num].draw(buffer2);
//    blit(buffer2,buffer,0,0,50,50,SCREEN_W-50,SCREEN_H-50);    
//    blit(buffer2,buffer,0,0,0,0,SCREEN_W,SCREEN_H);    
    blit(buffer2,buffer,0,0,3+2+(SCREEN_W)/pl_no*num,48+2,(SCREEN_W-(3+2))/pl_no-3-2,(SCREEN_H-48-(48+2))-2);  
//    blit(buffer2,buffer,0,0,50,50,5,5);      

    }  
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    //    blit(buffer,screen,0,0,50,50,SCREEN_W-50,SCREEN_H-50);    
//    blit(buffer,screen,0,0,50,50,50,50);    
    while(!keypressed());
    
    //threaded auto_framerate
    auto_framerate(60);
    while (!key[KEY_ESC])
    {
//       stretch_blit(back,buffer,0,0,back->w,back->h,0,0,SCREEN_W-1,SCREEN_H-1);
//       masked_stretch_blit(back2,buffer,0,0,back2->w,back2->h,0,SCREEN_H-(SCREEN_W*back2->h)/back2->w,SCREEN_W,(SCREEN_W*back2->h)/back2->w);
       stretch_blit(backgrd,buffer,0,0,backgrd->w,backgrd->h,0,0,buffer->w,buffer->h);
       stretch_blit(back,buffer2,0,0,back->w,back->h,0,0,buffer2->w,buffer2->h);
       masked_blit(back2,buffer2,0,0,0,0,back2->w,back2->h);//latestupdate

//       masked_stretch_blit(back2,buffer2,0,0,back2->w,back2->h,0,buffer2->h-(buffer2->w*back2->h)/back2->w,buffer2->w,(buffer2->w*back2->h)/back2->w);
//       masked_blit(back2,buffer2,0,0,0,0,back2->w,back2->h);

//       masked_stretch_blit(back2,buffer2,0,0,back2->w,back2->h,0,0,buffer2->w,buffer2->h);
       getinput(player);
       explosions.update_explosion(buffer2);
       update_player(player,buffer2);
//       update_weapon(player,buffer2);
         for(int num=0;num<2;num++)
         {
                 player[num].weapon1.update_weapon(player,num,buffer2);
                 player[num].weapon2.update_weapon(player,num,buffer2);
                 player[num].weapon3.update_weapon(player,num,buffer2);
         }         
         
       ticks++;
       resting=0;
//       rest_callback(8,rest1);
       rest_callback(cor_rest,rest1);
//       auto_framerate(60);

       

       for (int num=0;num<2;num++)
       {
           int x1,y1,w1,h1,x2,y2,w2,h2;
           x2=3+2+(SCREEN_W)/pl_no*num;
           y2=48+2;
           w1=(SCREEN_W-(3+2))/pl_no-3-2;
           h1=(SCREEN_H-48-(48+2))-2;
           
           switch (player[num].binaculor.status)
           {
              case 3:
              case 0:
                   x1=player[num].x-SCREEN_W/4;
                   y1=player[num].y-SCREEN_H/2;
                   blit(buffer2,buffer,x1,y1,x2,y2,w1,h1); 
                   break;
              case 1:
                   x1=player[num].binaculor.x-SCREEN_W/4;
                   y1=player[num].binaculor.y-SCREEN_H/2;
                   player[num].binaculor.s_m_blit(buffer2,buffer,x1,y1,x2,y2,w1,h1);
                   break;
              case 2:
                   x1=player[num].binaculor.x-SCREEN_W/4;
                   y1=player[num].binaculor.y-SCREEN_H/2;
                   player[num].binaculor.draw_img2(buffer2,player[num].binaculor.x,player[num].binaculor.y);
                   masked_blit(buffer2,buffer,x1,y1,x2,y2,w1,h1);
                   break;
           }
       }

       update_box(player,buffer3);

//       stretch_blit(buffer3,buffer,0,0,buffer3->w,buffer3->h,250,450,550-250,buffer->h*(550-250)/buffer3->w);
       masked_blit(buffer3,buffer,0,0,300,600-buffer3->h,buffer3->w,buffer3->h);


              //displaying the framerate
       blit(back, buffer, 320-70, 330, 320-70, 330, 140, 30);
       textprintf_centre_ex(buffer,font,320,330,798987,-1,"COUNTER %d", counter);
       textprintf_centre_ex(buffer,font,320,340,987997,-1,"FRAMERATE %d", framerate);
       textprintf_centre_ex(buffer,font,320,350,256477,-1,"RESTING %d", rested);
       textprintf_ex(buffer,font,300,360,1231444,0,"%d",cor_rest);
           
       blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);           
    }
    
    delete[] player;
    
    destroy_bitmap(back);
    destroy_bitmap(back2);
    
    destroy_bitmap(backgrd);
    
    destroy_bitmap (buffer2);
//    destroy_bitmap (buffer3);
}


void Turn_Game()       
{
    Real_Time=0;
    pl_no=2;

    int weapon_alive=0;
    
     
    set_color_depth(32);
//    set_gfx_mode(1,800,600,0,0);
    set_gfx_mode(2,800,600,0,0);
//    set_gfx_mode(2,1024,768,0,0);
//    set_gfx_mode(1,1280,960,0,0);

    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    buffer2=create_bitmap(BUFFER2_W*SCREEN_W/1280,BUFFER2_H*SCREEN_H/960);
//    buffer2=create_bitmap(BUFFER2_W*SCREEN_W/1280,SCREEN_H);
    BITMAP *buffer3=create_bitmap(300,113);
    BITMAP *backgrd=load_bitmap("backgrd.bmp",NULL);
    BITMAP *back=load_bitmap("background.bmp",NULL);
//    BITMAP *back2=load_bitmap("back.bmp",NULL);
    back2=create_bitmap(buffer2->w,buffer2->h);// as global
//    BITMAP *back2=create_bitmap(SCREEN_W,SCREEN_H);
    create_ground(back2);
    
    
    Player player[2];
//    Player *player;
//    player=new Player[pl_no];
    
    setup(player);
//        rest(3000);
//    exit(0);                     //TEMPORARY

    stretch_blit(backgrd,buffer,0,0,backgrd->w,backgrd->h,0,0,buffer->w,buffer->h);
    stretch_blit(back,buffer2,0,0,back->w,back->h,0,0,buffer2->w,buffer2->h);
    masked_blit(back2,buffer2,0,0,0,0,back2->w,back2->h);
//    stretch_blit(back,buffer,0,0,back->w,back->h,0,0,SCREEN_W-1,SCREEN_H-1);
//    stretch_blit(back,buffer,0,0,SCREEN_W,SCREEN_H,0,0,SCREEN_W,SCREEN_H);

//    masked_stretch_blit(back2,buffer,0,0,back2->w,back2->h,0,buffer->h-(buffer->w*back2->h)/back2->w,buffer->w,(buffer->w*back2->h)/back2->w);

//      masked_stretch_blit(back2,buffer2,0,0,back2->w,back2->h,0,buffer2->h-(buffer2->w*back2->h)/back2->w,buffer2->w,(buffer2->w*back2->h)/back2->w);

//      masked_blit(back2,screen,0,0,0,0,SCREEN_W,SCREEN_H);
//    masked_stretch_blit(back2,screen,0,0,back2->w,back2->w,0,0,SCREEN_W,SCREEN_H);
//clear_bitmap(buffer2);

//      masked_blit(buffer2,screen,0,0,0,0,SCREEN_W,SCREEN_H);

//displaying the ground
    masked_stretch_blit(buffer2,screen,0,0,buffer2->w,buffer2->h,0,0,SCREEN_W,SCREEN_H);


//real time
/*
    for(int num=0;num<pl_no;num++)
    {
//        player[num].draw(buffer2);
//    blit(buffer2,buffer,0,0,50,50,SCREEN_W-50,SCREEN_H-50);    
//    blit(buffer2,buffer,0,0,0,0,SCREEN_W,SCREEN_H);    
    blit(buffer2,buffer,0,0,3+2+(SCREEN_W)/pl_no*num,48+2,(SCREEN_W-(3+2))/pl_no-3-2,(SCREEN_H-48-(48+2))-2);  
//    blit(buffer2,buffer,0,0,50,50,5,5);      

    }  
*/

    blit(buffer2,buffer,0,0,3+2,48+2,SCREEN_W-(3+2)-3-2,(SCREEN_H-48-(48+2))-2);  

    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    //    blit(buffer,screen,0,0,50,50,SCREEN_W-50,SCREEN_H-50);    
//    blit(buffer,screen,0,0,50,50,50,50);    
    while(!keypressed());
    
    //threaded auto_framerate
    auto_framerate(60);
    int num=0;
    while (!key[KEY_ESC])
    {
//       stretch_blit(back,buffer,0,0,back->w,back->h,0,0,SCREEN_W-1,SCREEN_H-1);
//       masked_stretch_blit(back2,buffer,0,0,back2->w,back2->h,0,SCREEN_H-(SCREEN_W*back2->h)/back2->w,SCREEN_W,(SCREEN_W*back2->h)/back2->w);
       stretch_blit(backgrd,buffer,0,0,backgrd->w,backgrd->h,0,0,buffer->w,buffer->h);
       stretch_blit(back,buffer2,0,0,back->w,back->h,0,0,buffer2->w,buffer2->h);
       masked_blit(back2,buffer2,0,0,0,0,back2->w,back2->h);//latestupdate

//       masked_stretch_blit(back2,buffer2,0,0,back2->w,back2->h,0,buffer2->h-(buffer2->w*back2->h)/back2->w,buffer2->w,(buffer2->w*back2->h)/back2->w);
//       masked_blit(back2,buffer2,0,0,0,0,back2->w,back2->h);

//       masked_stretch_blit(back2,buffer2,0,0,back2->w,back2->h,0,0,buffer2->w,buffer2->h);
       update_player(player,buffer2);
       {
             if (player[num].weapon1.status!=-1){
                     player[num].weapon1.update_weapon(player,num,buffer2);
                     if (weapon_alive==0)
                     {
                        weapon_alive=1;
                        //num=(++num)%2;
                     }
             }
             else if (player[num].weapon2.status!=-1){
                     player[num].weapon2.update_weapon(player,num,buffer2);
                     if (weapon_alive==0)
                     {
                        weapon_alive=2;
                        //num=(++num)%2;
                     }
             }
             else if (player[num].weapon3.status!=-1){
                     player[num].weapon3.update_weapon(player,num,buffer2);
                     if (weapon_alive==0)
                     {
                        weapon_alive=3;
                        //num=(++num)%2;
                     }
             }
             else if (weapon_alive!=0){
                      weapon_alive=0;
                      num=(++num)%2;                  
             }
       }
       {
           int x1,y1,w1,h1,x2,y2,w2,h2;
           x2=3+2;
           y2=48+2;
           w1=SCREEN_W-(3+2)-3-2;
           h1=(SCREEN_H-48-(48+2))-2;
           if (!weapon_alive && explosions.exp_pos!=NULL && explosions.exp_pos->count){
              explosions.update_explosion(buffer2);
              x1=explosions.exp_pos->pos.x-SCREEN_W/2;
              y1=explosions.exp_pos->pos.y-SCREEN_H/2;
              blit(buffer2,buffer,x1,y1,x2,y2,w1,h1);
           }
           else if (weapon_alive==0){
              getinput(player+num);
              
              //for (int num=0;num<1;num++)
              {
                   /*
                   int x1,y1,w1,h1,x2,y2,w2,h2;
                   x2=3+2;
                   y2=48+2;
                   w1=SCREEN_W-(3+2)-3-2;
                   h1=(SCREEN_H-48-(48+2))-2;*/
                   
                   switch (player[num].binaculor.status)
                   {
                      case 3:
                      case 0:
                           x1=player[num].x-SCREEN_W/2;
                           y1=player[num].y-SCREEN_H/2;
                           blit(buffer2,buffer,x1,y1,x2,y2,w1,h1); 
                           break;
                      case 1:
                           x1=player[num].binaculor.x-SCREEN_W/2;
                           y1=player[num].binaculor.y-SCREEN_H/2;
                           player[num].binaculor.s_m_blit(buffer2,buffer,x1,y1,x2,y2,w1,h1);
                           break;
                      case 2:
                           x1=player[num].binaculor.x-SCREEN_W/2;
                           y1=player[num].binaculor.y-SCREEN_H/2;
                           player[num].binaculor.draw_img2(buffer2,player[num].binaculor.x,player[num].binaculor.y);
                           masked_blit(buffer2,buffer,x1,y1,x2,y2,w1,h1);
                           break;
                   }
              }
              
              
           }
           else
           {
               /*
               int x1,y1,w1,h1,x2,y2,w2,h2;
               x2=3+2;
               y2=48+2;
               w1=SCREEN_W-(3+2)-3-2;
               h1=(SCREEN_H-48-(48+2))-2;*/
               switch (weapon_alive)
               {
                   case 1:
                        x1=player[num].weapon1.x-SCREEN_W/2;
                        y1=player[num].weapon1.y-SCREEN_H/2;
                        blit(buffer2,buffer,x1,y1,x2,y2,w1,h1);
                        break;
                   case 2:
                        x1=player[num].weapon2.x-SCREEN_W/2;
                        y1=player[num].weapon2.y-SCREEN_H/2;
                        blit(buffer2,buffer,x1,y1,x2,y2,w1,h1);
                        break;
                   case 3:
                        x1=player[num].weapon3.x-SCREEN_W/2;
                        y1=player[num].weapon3.y-SCREEN_H/2;
                        blit(buffer2,buffer,x1,y1,x2,y2,w1,h1);
                        break; 
               }
               
           }
       }
       
//       update_weapon(player,buffer2);
         //for(int num=0;num<2;num++)
         
       ticks++;
       resting=0;
//       rest_callback(8,rest1);
       rest_callback(cor_rest,rest1);
//       auto_framerate(60);

       

       update_box(player,buffer3);

//       stretch_blit(buffer3,buffer,0,0,buffer3->w,buffer3->h,250,450,550-250,buffer->h*(550-250)/buffer3->w);
       masked_blit(buffer3,buffer,0,0,300,600-buffer3->h,buffer3->w,buffer3->h);

              //displaying the framerate
       blit(back, buffer, 320-70, 330, 320-70, 330, 140, 30);
       textprintf_centre_ex(buffer,font,320,330,798987,-1,"COUNTER %d", counter);
       textprintf_centre_ex(buffer,font,320,340,987997,-1,"FRAMERATE %d", framerate);
       textprintf_centre_ex(buffer,font,320,350,256477,-1,"RESTING %d", rested);
       textprintf_ex(buffer,font,300,360,1231444,0,"%d",cor_rest);
           
       blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);           

    }
    
    delete[] player;
    
    destroy_bitmap(back);
    destroy_bitmap(back2);
    
    destroy_bitmap(backgrd);
    
    destroy_bitmap (buffer2);
//    destroy_bitmap (buffer3);
}
