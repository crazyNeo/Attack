#define ALLEGRO_STATICLINK

#define GROUND 4000
//#define BUFFER2_W 3000
//#define BUFFER2_H 1440
#define BUFFER2_W 1500//this value should be greater than 1280 for smooth ground
#define BUFFER2_H 960//this value should be greater than 960 for smooth ground

#include <allegro.h>

#define GREEN makecol(0,255,0)
#define PINK makecol(255,0,255)


void get_input(int &x,int &y,BITMAP *ground)
{
    if (key[KEY_LEFT]&& x>0) x-=10;
    if (key[KEY_RIGHT] && x<ground->w-SCREEN_W) x+=10;
    if (key[KEY_UP] && y>0) y-=10;
    if (key[KEY_DOWN] && y<ground->h-SCREEN_H) y+=10;
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
          get_input(x,y,buffer6);
          clear_bitmap(screen);          

          masked_blit(buffer6,screen,x,y,0,0,SCREEN_W,SCREEN_H);
//          blit(buffer6,screen,x,y,0,0,SCREEN_W,SCREEN_H);
          rest(100);
    }
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
              if (d>10) d=10;
              else if (d<-10) d=-10;
              
//              if (k%10!=0) a[k]=a[k-1]+d;
//              else 
                     a[k]=a[k-1]+d+(rand()%3-1)*1.5;
              if (tr++>3) 
                 if (a[k]<200) a[k]=200;//upper limit
                 else if (a[k]>(buffer5->h-100)) a[k]=(buffer5->h-100);//lower limit
              
        }
        while (a[k]>(buffer5->h-100) || a[k]<20);
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




int main()
{
    allegro_init();
    set_color_depth(16);
    set_gfx_mode(2,800,600,0,0);
    install_keyboard();
//    BITMAP *buffer6=create_bitmap(GROUND,1000);
    BITMAP *buffer6=create_bitmap(BUFFER2_W*SCREEN_W/1280,BUFFER2_H*SCREEN_H/960);
    create_ground(buffer6);
    textprintf_ex(screen,font,300,300,0,4564,"^^^^^^^^^^^^^^^^^^^^^^^^");        
     while (!key[KEY_A]);
    
//    view (buffer6);

    

   
    
    
    
    
    view(buffer6);
       clear_bitmap(screen);
       textprintf_ex(screen,font,300,300,0,4564,"++++++++++");
        rest(1000);
masked_stretch_blit(buffer6,screen,0,0,buffer6->w,buffer6->h,0,0,SCREEN_W,SCREEN_H);
     while (!key[KEY_ESC]);


    allegro_exit();
    return 0;
}
END_OF_MAIN()

/*
    

   
    
    
    
    
    view(buffer6);
       clear_bitmap(screen);
       textprintf_ex(screen,font,300,300,0,4564,"++++++++++");
        rest(1000);
masked_stretch_blit(buffer5,screen,0,0,buffer6->w,buffer6->h,0,0,SCREEN_W,SCREEN_H);
return;

*/
