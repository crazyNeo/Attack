////////////////////////////
//att_clas.h///////////////
//////////////////////////

#ifndef ATT_CLAS_H
#define ATT_CLAS_H

#define EXPLOSION_COUNT 5

#include "allegro.h"
#include "math.h"
#include "stdio.h"
#include <fstream>
#include <process.h>
#include "prototyp.h"
using namespace std;

struct images
{
       int flip;
       int size;
};
class Position
{
//   protected:
   public:
      float x,y;      
      int fac_angl;
};

class Motion
{
//   protected:
   public:
      float vel;      
      int mov_angl;
      int x_speed,y_speed;
      
};

//base class can be called as abstract but not called  this is wrong
//i am very very confused
//yo base class ho tara you root class haina logically yelai abstract base class banauna millinu parne ho kinaki no object has been instantiate

struct Exp_position{
               Position pos;
               int count;
               Exp_position *next;
        };
        
        
class Explosion{
   private:      

        
        
        
      void explosion(BITMAP *bmp, int x,int y,int finalcolor){
            int color,size=30;
//            circlefill(buffer2, x, y, 33, finalcolor);
            
            //there is some error
            /*
            for (int n=30; n>0 ||size>0; n--)
            {
            //generate a random color
//            color = makecol(200+rand()%55,200+rand()%55,rand()%50);
            color = makecol(rand()%255,rand()%255,rand()%255);

            //random explosion size
            
            //draw the random filled circle
            //circlefill(bmp, x, y, size, color);
            //short pause
            //rest(2);
            circlefill(buffer2, x, y, size, color);
            size -= (1+rand()%5);
            }
            */
            color = makecol(200+rand()%80,200+rand()%80,rand()%50);
            size=rand()%22+12;
            circlefill(buffer2, x, y, size, color);
            
//                        rest(200);
            //missile tracker looks for this explosion color
            //circlefill(bmp, x, y, 30, finalcolor);
      }
        
   public:
       
       Exp_position *exp_pos;
       //Exp_position *create_col_flag;
       struct Flag_coll{
              int x,y,check_flag;//(x,y) collision checking done or not=>check_flag 1->to be detected 0->already detected
       }create_col_flag[2];
       
       
       Explosion(){
          exp_pos=NULL;
//          exp_pos->count=0;
//          exp_pos->next=NULL;
//          create_col_flag=NULL;
          create_col_flag[0].check_flag=0;
          create_col_flag[1].check_flag=0;
            
       }
       void create_explosion(int x,int y){
            Exp_position **p,**q;
            p=&exp_pos;
            while (*p!=NULL){
                  if ((*p)->count==0) goto Reuse_exp_pos;
                  (*p)=(*p)->next;
            }
            (*p)=new Exp_position;
            (*p)->next=NULL;

            Reuse_exp_pos:
            (*p)->count=EXPLOSION_COUNT;
            
            
            (*p)->pos.x=x;
            (*p)->pos.y=y;
            circlefill(back2, x, y, 30, PINK);   
            
            //marking flag
            for (int n=0;n<2;n++)//at max two possible explosions
            {
                if (create_col_flag[n].check_flag==0){
                    create_col_flag[n].check_flag =1;
                    create_col_flag[n].x=x;
                    create_col_flag[n].y=y;
                }
            }
                       
            
            //errorsome
            /*
            q=&create_col_flag;
            while(1){
                if ((*q)==NULL){
                    (*q)=*p;
                    (*q)->next=NULL;
                    break;
                }
                *q=(*q)->next;
            }*/
            
            
                     
//            textprintf_ex(screen,font,200,200,0,1233112,"%d  %d  %d   %d ",(*p),exp_pos,exp_pos->count,exp_pos->next);
//            rest(1000);
       }
       void update_explosion(BITMAP *bmp){
            Exp_position *p;
            p=exp_pos;
            while (p!=NULL){
                  if (p->count>0){
                     p->count--;
                     explosion(bmp,p->pos.x,p->pos.y,GREEN);
//                     textprintf_ex(buffer2,font,200,200,0,46544454,"%d ",p->count);
                  }
                  p=p->next;
            }
            
       }
}explosions;


class Binaculors:public Position//for crosshair of homming missile also
{
   public:
       
       int x,y;
       int status;
       BITMAP *image;
       BITMAP *image2;
       int get_width()      
       {
//           textprintf_ex(screen,font,111,111,0,21344,"status%d",status);
//           while (!keypressed());
           return (image->w);
       }
       int get_height()      
       {
           return (image->h);
       }
       BITMAP *get_image()
       {
           return (image);       
       }
       void s_m_blit(BITMAP *source,BITMAP *dest,int s_x,int s_y,int d_x,int d_y,int d_w,int d_h)
       {
          masked_blit(source,dest,s_x,s_y,d_x,d_y,d_w,d_h);
          masked_stretch_blit(image,dest,0,0,image->w,image->h,d_x,d_y,d_w,d_h);
       }
       void draw(BITMAP *dest,BITMAP *source)
       {
            masked_blit(source,dest,x-SCREEN_W/2,y-SCREEN_H/2,0,0,x+SCREEN_W/2,y+SCREEN_H/2);
//            draw_sprite (dest,image,x-image->w/2,y-image->h/2);
            draw_sprite (dest,image,0,0);
       }
       
       void move_left(BITMAP *source)
       {
                if (x>0) x-=10;
       }
       void move_right(BITMAP *source)
       {
            if ( x<source->w-SCREEN_W/4) x+=10;
       }
       void move_up(BITMAP *source)
       {
            if ( y>0) y-=10;
       }
       void move_down(BITMAP *source)
       {
            if (y<source->h-SCREEN_H/4) y+=10;
       }
       void draw_img2(BITMAP *dest,int xx,int yy)
       {
            draw_sprite (dest,image2,xx-image2->w/2,yy-image2->h/2);
       }
       //for now i will define it outside
       /*
       void chang_status()
       {
            if ()
       }
       */
       //constructor
       Binaculors()
       {
                 image=load_bitmap("binaculor.bmp",NULL);
                 image2=load_bitmap("crosshair2.bmp",NULL);
                 status=0;
       }             
};

class Sprite:public Position,public Motion
{
   protected:
//   private:
          
//       BITMAP **image;
       BITMAP ***image;

//       int num_img;
       //new arrivals for animation
       int xspeed,xdelay,xcount;//to be used in future
       int *curframe;
       int *maxframe;
       int framecount,framedelay;
       
   public:
//       int alive;
       int status;
       images img;       
       
       Sprite()
       {
//               curframe=0;
               framecount=0;
               framedelay=5;
//               maxframe=0;
               status=0;
               fac_angl=0;
       }
       
       int get_curframe()
       {
           return (curframe[status]);
       }
       int get_width(int no=0)      
       {
//           textprintf_ex(screen,font,111,111,0,21344,"status%d",status);
//           while (!keypressed());
           return (image[status][no]->w);
       }
       int get_height(int no=0)      
       {
           return (image[status][no]->h);
       }
       BITMAP *get_image(int no=0)
       {
           return (image[status][no]);       
       }
       void m_blit(BITMAP *dest,int s_x,int s_y,int d_x,int d_y)
       {
//           masked_blit(image,dest,s_x,s_y,d_x,d_y,image->w,image->h);
       }
       void draw(BITMAP *dest)
       {
//            textprintf_ex(screen,font,200,300,-1,466464,"status=%d    curframe=%d,  maxframe=%d",status,curframe[status],maxframe[status]);


//              if (status!=8)
                 draw_sprite (dest,image[status+fac_angl*img.size][curframe[status]],x-image[status+fac_angl*img.size][curframe[status]]->w/2,y-image[status+fac_angl*img.size][curframe[status]]->h/2);
//              else
//                 draw_sprite (dest,image[0+fac_angl*img.size][curframe[0]],x-image[0+fac_angl*img.size][curframe[0]]->w/2,y-image[0+fac_angl*img.size][curframe[0]]->h/2);



//            draw_sprite (dest,image[status][curframe],x-image[status][curframe]->w/2,y-image[status][curframe]->h/2);
       }
       
       void update_sprite()
       {
            //update frame based on animdir
            if (++framecount > framedelay)
            {
                framecount = 0;
                /*
                if (animdir == -1)
                {
                   if ( --curframe < 0)
                   curframe = maxframe;
                }
                else if (animdir == 1)
                {
                if (++curframe > maxframe)
                curframe = 0;
                }
                */
                if (++curframe[status] >= maxframe[status])
                   curframe[status] = 0;
            }
       }
       void load(char *name)
       {
//            maxframe=no;

              char f_name[20];
              sprintf(f_name,"%s\\%s.txt\0",name,name);              
            ifstream plr_data(f_name);
//            int flip;
//            int size;
            plr_data>>img.flip>>img.size;
//            textprintf_ex(screen,font,300,300,-1,222222,"%d   %d   %d",img.size,img.flip,img.size+img.flip*img.size);
//            rest(1000);
            image=new BITMAP** [img.size+img.flip*img.size];  
//            image=new BITMAP** [img.size];  
//            image=new BITMAP** [size];  
            maxframe=new int [img.size];
            curframe=new int [img.size];
            int count=0;
            for (int k=0;k<img.size;k++)
            {
                int x;
                int counter=0;
                plr_data>>maxframe[k];//total no of frames for each status
                curframe[k]=0;
                image[k]=new BITMAP *[maxframe[k]];
                plr_data>>x;
                do
                {             
                  char pl_bmp[15];
                  sprintf(pl_bmp,"%s\\%d.bmp\0",name,x);                              
                  image[k][counter]=load_bitmap(pl_bmp,NULL);
                  counter++;
                  count++;
                  plr_data>>x;
                //}while (counter<maxframe[k]);
                }while (x>-1);
                
            }
            if (img.flip)
              for (int k=0;k<img.size;k++)
              {
                image[k+img.size]=new BITMAP *[maxframe[k]];
                for (int j=0;j<maxframe[k];j++)
                {
                    image[k+img.size][j]=create_bitmap(image[k][j]->w,image[k][j]->h);
                    clear_to_color(image[k+img.size][j],PINK);
//                    draw_sprite(image[k+img.size][j],image[k][j],0,0);                  
                 draw_sprite_h_flip(image[k+img.size][j],image[k][j],0,0);                  
//                  textprintf_ex(screen,font,300,300,-1,466464,"%d   %d   %d   %d",img.size,img.flip,k+img.size,maxframe[k]);
//                  clear_bitmap(screen);
//                    draw_sprite(screen,image[k+img.size][j],100,100);                  
//                  draw_sprite(screen,image[k][j],0,0);                  
//                    rest(300);

                }
              }            

/*
            {
            maxframe=no;
            image=new BITMAP*[no];
            for (int k=0;k<no;k++)
            {
                char pl_bmp[15];
                sprintf(pl_bmp,"%s\\%d.bmp\0",name,k);
                image[k]=load_bitmap(pl_bmp,NULL);
            }
            }
*/
       }
};
class Player;//,public Muzzle

class Sprite2:public Sprite//for weapon   /*//for bullet*/
{
      public:
         float x1,y1,x2,y2;
         float counter;
         
         friend int weapon_collision(Player *player,int num);         
      void update_weapon(Player *player,int num,BITMAP *dest)
      {
           void explosion(BITMAP *bmp, int x,int y,int finalcolor);
//        for (int num=0;num<pl_no;num++)
        //int num=1;
        if (status==0)
        {     
            int v=60;
            //    float th=player[num].crosshair.rel_pos.fac_angl/128.0*M_PI;
            float th=fac_angl/128.0*M_PI;
            {
                x2=(v*cos(th)*counter );//d*pow(-1,num);
                y2=(-v*sin(th)*counter ) +.5*9.8*counter*counter;
                
                x=x2+x1-get_width()/2;
                y=y2+y1-get_height()/2;
                //          int y=player[num].weapon.y1-player[num].weapon.get_image()->h/2;

                textprintf_ex(dest,font,23,20,4554554,2,"angl%f , %f ,%f",th,cos(th),sin(th));
                textprintf_ex(dest,font,23,30,4554554,0,"weapon%f , %f ,%f",x2,y2);
                textprintf_ex(dest,font,23,40,4554554,1,"weapon %d ,%d",x,y);
                draw_sprite(dest,get_image(),x,y);
          
      //          textprintf_ex(dest,font,23,70,4554554,0,"weapon%f , %f ,%f",player[num].crosshair.pos.x,player[num].crosshair.pos.y);
//                textprintf_ex(dest,font,23,80,4554554,0,"weapon%f , %f ,%f",player[num].x,player[num].y);          
      //          draw_sprite(screen,player[num].bullet.get_image(),200,player[num].bullet.y1);
      //          draw_sprite(screen,player[num].bullet.get_image(),10,12);

                counter+=.15; 
                //rest(30);
      //rest(1000);
          }
          if (weapon_collision(player,num))
          {
             //explosion(buffer2,x,y,GREEN);
             explosions.create_explosion(x,y);
             status=-1;
          }          
// SOMETHING MUST BE DONE TO REPLACE THIS
        }
      }
};

class Grinade:public Sprite2
{
      public:
             int bounce;
      friend int weapon_collision2(Player *player,int num);         
      void update_weapon(Player *player,int num,BITMAP *dest)
      {
//        for (int num=0;num<pl_no;num++)
        //int num=1;
        if (status==0)
        {     
            int v=vel;
            //    float th=player[num].crosshair.rel_pos.fac_angl/128.0*M_PI;
            float th=fac_angl/128.0*M_PI;
            {
                x2=(v*cos(th)*counter );//d*pow(-1,num);
                y2=(-v*sin(th)*counter ) +.5*9.8*counter*counter;
                
                x=x2+x1-get_width()/2;
                y=y2+y1-get_height()/2;
                //          int y=player[num].weapon.y1-player[num].weapon.get_image()->h/2;

                textprintf_ex(dest,font,23,20,4554554,2,"angl%f , %f ,%f",th,cos(th),sin(th));
                textprintf_ex(dest,font,23,30,4554554,0,"weapon%f , %f ,%f",x2,y2);
                textprintf_ex(dest,font,23,40,4554554,1,"weapon %d ,%d",x,y);
                draw_sprite(dest,get_image(),x,y);
          
      //          textprintf_ex(dest,font,23,70,4554554,0,"weapon%f , %f ,%f",player[num].crosshair.pos.x,player[num].crosshair.pos.y);
//                textprintf_ex(dest,font,23,80,4554554,0,"weapon%f , %f ,%f",player[num].x,player[num].y);          
      //          draw_sprite(screen,player[num].bullet.get_image(),200,player[num].bullet.y1);
      //          draw_sprite(screen,player[num].bullet.get_image(),10,12);

                counter+=.15; 
                //rest(30);
      //rest(1000);
          
          }
          if (weapon_collision2(player,num))
          {
             fac_angl=rand()%120+4;//between 4 and 124
             vel*=.2;
             counter=0;
             x1=x;
             y1=y;
             if (++bounce==3)
             {
                status=-1;
                void explosion(BITMAP *bmp, int x,int y,int finalcolor);
                //explosion(buffer2,x,y,GREEN);
                explosions.create_explosion(x,y);
             }
             
             //not here
          }
// SOMETHING MUST BE DONE TO REPLACE THIS

        }
      }
};

class Homing:public Sprite2//homing missile //i will do this later
{
      public:
             int bounce;
             int tar_x,tar_y;
      friend int weapon_collision3(Player *player,int num);         
      void update_weapon(Player *player,int num,BITMAP *dest)
      {
//        for (int num=0;num<pl_no;num++)
        //int num=1;
        if (status==0)
        {     
            int v=vel;
            //    float th=player[num].crosshair.rel_pos.fac_angl/128.0*M_PI;
            float th=fac_angl/128.0*M_PI;
            {
                x2=(v*cos(th)*counter );//d*pow(-1,num);
                y2=(-v*sin(th)*counter ) +.5*9.8*counter*counter;
                
                x=x2+x1-get_width()/2;
                y=y2+y1-get_height()/2;
                //          int y=player[num].weapon.y1-player[num].weapon.get_image()->h/2;

                textprintf_ex(dest,font,23,20,4554554,2,"angl%f , %f ,%f",th,cos(th),sin(th));
                textprintf_ex(dest,font,23,30,4554554,0,"weapon%f , %f ,%f",x2,y2);
                textprintf_ex(dest,font,23,40,4554554,1,"weapon %d ,%d",x,y);
                draw_sprite(dest,get_image(),x,y);
          
      //          textprintf_ex(dest,font,23,70,4554554,0,"weapon%f , %f ,%f",player[num].crosshair.pos.x,player[num].crosshair.pos.y);
//                textprintf_ex(dest,font,23,80,4554554,0,"weapon%f , %f ,%f",player[num].x,player[num].y);          
      //          draw_sprite(screen,player[num].bullet.get_image(),200,player[num].bullet.y1);
      //          draw_sprite(screen,player[num].bullet.get_image(),10,12);

                counter+=.15; 
                //rest(30);
      //rest(1000);
          
          }
          if (weapon_collision3(player,num))
          {
             fac_angl=rand()%120+4;//between 4 and 124
             vel*=.2;
             counter=0;
             x1=x;
             y1=y;
             if (++bounce==3)
             {
                status=-1;
                void explosion(BITMAP *bmp, int x,int y,int finalcolor);
                //explosion(buffer2,x,y,GREEN);
                explosions.create_explosion(x,y);
             }
             
             //not here
          }
          
// SOMETHING MUST BE DONE TO REPLACE THIS

        }
      }
};

/*
class Inverntry{
      private:
      public:
             Sprite2 *Invent[3];   //3 weapons
             Invent[0]=new Binaculors;
             Invent[1]=new Grinade;
             Invent[2]=new Homing;
             
             int current;
             void select_weapon(int n){
                  current=n;
             }
             void fire_weapon();{
                
                  }
             }
};
*/

//class Muzzle:public Sprite
class Sprite3:public Sprite//crosshair
{
   public:
    //  float muz_x,muz_y;
      float crosshair_rad;
      
      Position rel_pos;//relative position
      ////////////////
      //this should be removed because pos is already in herited in Sprite and thus in Sprite3
      ////////////////
            
//      float muz_angl;
  //    BITMAP *crosshair;
      
      void set(float r,int angl)
      {//rel_pos.fac_angl is in relative position to the angle of projectile in realitytaking the angle with respect to positive x axis
           crosshair_rad=r;
           rel_pos.fac_angl=angl;
           rel_pos.x=crosshair_rad*cos((256-rel_pos.fac_angl)/128.0*M_PI);
           rel_pos.y=crosshair_rad*sin((256-rel_pos.fac_angl)/128.0*M_PI);
           
//           textprintf_ex(screen,font,111,111,654654,0,"rad%f  angl%d",crosshair_rad,rel_pos.fac_angl);
//           textprintf_ex(screen,font,111,121,654654,0,"x%f  y%f",rel_pos.x,rel_pos.y);
//           rest(3000);
      }
      
      void set()
      {
           rel_pos.x=crosshair_rad*cos((256-rel_pos.fac_angl)/128.0*M_PI);
           rel_pos.y=crosshair_rad*sin((256-rel_pos.fac_angl)/128.0*M_PI);
      }

/*
//      void update_cros(Player *player)
        void update_cros()
      {
          
            x=x+rel_pos.x;//+player[n].get_width();
            y=y+rel_pos.y;//-player[0].get_height()/2;
          
      }
 
//this one is defined in player
      
      void show_crosshair(BITMAP *dest,int x,int y)
      {
           draw_sprite(dest,crosshair,x,y);
      }
      
      
      void crosshair_load(char *name)
      {
           crosshair=load_bitmap(name,NULL);
      }*/
};


class Player:public Sprite//,public Muzzle
{
   protected:   
      char name[5];
      int group;
      
   public:
          int num;
          int jump_ht;//jump height time
          float
           jump_vel;
          int jump_phase;//jump dir//0 up, 1 down
          int key_pres_delay;//only required for live 2 player game
          
          
          Binaculors binaculor;
          
          //weapons
          Sprite2 weapon1;
          Grinade weapon2;
          Homing weapon3;
          
//          Muzzle muz;//Sprite3            
          Sprite3 crosshair;
//          friend int weapon_collision(Player *player,int num);         
          void update_cros()
      {
            crosshair.x=x+crosshair.rel_pos.x;//+player[n].get_width();
            crosshair.y=y+crosshair.rel_pos.y;//-player[0].get_height()/2;
      }
/*      void draw(BITMAP *dest)
       {
//            textprintf_ex(screen,font,200,300,-1,466464,"status=%d    curframe=%d,  maxframe=%d",status,curframe[status],maxframe[status]);
            draw_sprite (dest,image[status+fac_angl*img.size][curframe[status]],x-image[status+fac_angl*img.size][curframe[status]]->w/2,y-image[status+fac_angl*img.size][curframe[status]]->h/2-jump_ht);
//            draw_sprite (dest,image[status][curframe],x-image[status][curframe]->w/2,y-image[status][curframe]->h/2);
       }
*/
};

/*
class player:public Position,public Motion
{
   protected:   
      char name[5];
      int group;

   public:
};
*/


#endif
