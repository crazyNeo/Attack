#define ALLEGRO_STATICLINK

#define SIZE 200
#include <allegro.h>

#define GREEN makecol(0,255,0)
#define PINK makecol(255,0,255)

int main()
{
    float a[2*SIZE];
    //initialize the random number seed
    srand(time(NULL));

    //for (int k=1;k<100;k++)
    {
    }
    allegro_init();
    set_color_depth(16);
    set_gfx_mode(2,800,600,0,0);

    
    install_keyboard();
    
    BITMAP *buffer5=create_bitmap(2000,600);
    clear_to_color(buffer5,PINK);
    BITMAP *buffer6=create_bitmap(buffer5->w,buffer5->h);
    BITMAP *tile=load_bitmap("tile.bmp",NULL);
    a[0]=500;    
         //textprintf_ex(buffer5,font,10,a[0],0,4564,"%d",a[0]);
         putpixel(buffer5,0,a[0],GREEN);  
         putpixel(screen,0,a[0],GREEN);
         
    a[1]=a[0];    
         //textprintf_ex(buffer5,font,25,a[1],0,4564,"%d",a[1]);
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
   for (int k=2;k<SIZE;k++)
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
                 else if (a[k]>(SCREEN_H-100)) a[k]=(SCREEN_H-100);
              
        }
        while (a[k]>(SCREEN_H-100) || a[k]<20);
        putpixel(buffer5,k*5,a[k],GREEN);  
        line(buffer5,(k-1)*5,a[k-1],k*5,a[k],GREEN);
        putpixel(screen,(k*5)%SCREEN_W,a[k],GREEN);  
//     textprintf_ex(buffer5,font,10+k*15,a[k],0,4564,"%d",a[k]);
    }
    
    
    ///*
    for(int k=SIZE;k<2*SIZE;k++)
    {
            a[k]=a[2*SIZE-k-1];
        putpixel(buffer5,k*5,a[k],GREEN);  
        line(buffer5,(k-1)*5,a[k-1],k*5,a[k],GREEN);
        putpixel(screen,(k*5)%SCREEN_W,a[k],GREEN);  
    }
    //*/
   // floodfill(buffer5,2,598,456456);
    line(buffer5,(2*SIZE-1)*5,a[2*SIZE-1],(2*SIZE)*5,a[2*SIZE-1],GREEN);
    int k=0;
    textprintf_ex(screen,font,300,300,0,4564,"gsdaasdf");
    rest(1000);
    
    while (!key[KEY_ESC]) 
    {
          
          blit(buffer5,screen,k,0,0,0,SCREEN_W,SCREEN_H);
          if( k++>2000-SCREEN_W)
          {   k=0; rest(4000);}
          rest(5);
    }
        floodfill(buffer5,0,0,GREEN);
    k=0;
    textprintf_ex(screen,font,300,300,0,4564,"gsdaasdf");
    rest(1000);
    while (!key[KEY_ESC]) 
    {
          
          blit(buffer5,screen,k,0,0,0,SCREEN_W,SCREEN_H);
          if( k++>2000-SCREEN_W) k=0;
          rest(10);
    }
    masked_blit(buffer5,buffer6,0,0,0,0,buffer6->w,buffer6->h);
    floodfill(buffer6,0,0,PINK);    
    textprintf_ex(screen,font,300,300,0,4564,"gsdaasdf");
    rest(1000);
    

    while (!key[KEY_ESC]) 
    {
          clear_bitmap(screen);          
          masked_blit(buffer6,screen,k,0,0,0,SCREEN_W,SCREEN_H);
          if( k++>2000-SCREEN_W) k=0;
          rest(50);
    }
    
    
    allegro_exit();
    return 0;
}
END_OF_MAIN()
