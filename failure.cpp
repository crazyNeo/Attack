#define ALLEGRO_STATICLINK

#define GROUND 4000
#define BUFFER2_W 3000
#define BUFFER2_H 1440

#include <allegro.h>

#define GREEN makecol(0,255,0)
#define PINK makecol(255,0,255)

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
//         textprintf_ex(buffer5,font,10,a[0],0,4564,"%d",a[0]);
         putpixel(buffer5,0,a[0],GREEN);  
         putpixel(screen,0,a[0],GREEN);
         
    a[1]=a[0];    
//         textprintf_ex(buffer5,font,25,a[1],0,4564,"%d",a[1]);
         putpixel(buffer5,1,a[1],GREEN);  
         
         line(buffer5,(0)*5,a[0],1*5,a[1],GREEN);
         putpixel(screen,1,a[1],GREEN);
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
              if (d>10) d=10;
              else if (d<-10) d=-10;
              
//              if (k%10!=0) a[k]=a[k-1]+d;
//              else 
                     a[k]=a[k-1]+d+(rand()%3-1)*1.5;
              if (tr++>3) 
                 if (a[k]<20) a[k]=20;
                 else if (a[k]>(buffer5->h-100)) a[k]=(buffer5->h-100);
              
        }
        while (a[k]>(buffer5->h-100) || a[k]<20);
        putpixel(buffer5,k*5,a[k],GREEN);  
        line(buffer5,(k-1)*5,a[k-1],k*5,a[k],GREEN);
        putpixel(screen,(k*5)%SCREEN_W,a[k],GREEN);  
//     textprintf_ex(buffer5,font,10+k*15,a[k],0,4564,"%d",a[k]);
    }
    
    

    for(int k=size;k<2*size;k++)
    {
            a[k]=a[2*size-k-1];
        putpixel(buffer5,k*5,a[k],GREEN);  
        line(buffer5,(k-1)*5,a[k-1],k*5,a[k],GREEN);
        putpixel(screen,(k*5)%SCREEN_W,a[k],GREEN);  
    }
   // floodfill(buffer5,2,598,456456);
    line(buffer5,(2*size-1)*5,a[2*size-1],(2*size)*5,a[2*size-1],GREEN);
    int k=0;
    textprintf_ex(screen,font,300,300,0,4564,"gsdaasdf");
    rest(1000);

    while (!key[KEY_ESC]) 
    {
          
          blit(buffer5,screen,0,0,0,0,SCREEN_W,SCREEN_H);
          
          
   
          if( k++>buffer5->w-SCREEN_W)
          {   k=0;     textprintf_ex(screen,font,300,300,0,4564,"end *"); rest(1000);break;}
          rest(5);
    }
    

        floodfill(buffer5,0,0,GREEN);
    k=0;
    textprintf_ex(screen,font,300,300,0,4564,"gsdaasdf");
    rest(1000);
    while (!key[KEY_ESC]) 
    {
          
          blit(buffer5,screen,k,0,0,0,SCREEN_W,SCREEN_H);
          if( k++>buffer5->w-SCREEN_W) k=0;
          rest(10);
    }

    masked_blit(buffer5,buffer6,0,0,0,0,buffer6->w,buffer6->h);
    floodfill(buffer6,0,0,PINK);    
    textprintf_ex(screen,font,300,300,0,4564,"gsdaasdf");
    
    
    rest(2000);
    destroy_bitmap(buffer5);
    destroy_bitmap(tile);
    delete[] a;
}

void get_input(int &x,int &y,BITMAP *ground)
{
    if (key[KEY_LEFT]&& x>10) x-=10;
    if (key[KEY_RIGHT] && x<ground->w-SCREEN_W+100) x+=10;
    if (key[KEY_UP] && y>10) y-=10;
    if (key[KEY_DOWN] && y<ground->h-SCREEN_H+100) y+=10;
}

void view(BITMAP *buffer6)
{
     int x=0,y=0;
     int k=0;
               clear_bitmap(screen);          
                   textprintf_ex(screen,font,300,300,0,4564,"===========");
     rest(1000);
     while (!key[KEY_ESC])
    {
//          clear_bitmap(screen);          
               get_input(x,y,buffer6);
//          masked_blit(buffer6,screen,x,y,0,0,SCREEN_W,SCREEN_H);
          blit(buffer6,screen,x,y,0,0,SCREEN_W,SCREEN_H);
          rest(10);
    }
}

int main()
{
    allegro_init();
    set_color_depth(16);
    set_gfx_mode(2,800,600,0,0);
    install_keyboard();
    BITMAP *buffer6=create_bitmap(GROUND,600);
    BITMAP *buffer2=create_bitmap(BUFFER2_W*SCREEN_W/1280,BUFFER2_H*SCREEN_H/960);
    BITMAP *buffer1=create_bitmap(1600,600);
    create_ground(buffer1);
        

    
view (buffer6);
    textprintf_ex(screen,font,300,300,0,4564,"***********");
    while (!key[KEY_ESC]) ;
    allegro_exit();
    return 0;
}
END_OF_MAIN()
/*

   clear_bitmap(screen);
        rest(1000);
masked_stretch_blit(buffer5,screen,0,0,buffer5->w,buffer5->h,0,0,SCREEN_W,SCREEN_H);
return;

*/
