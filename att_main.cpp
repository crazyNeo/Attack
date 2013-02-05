///////////////
////main.h/////
///////////////

#define ALLEGRO_STATICLINK

#include "header1.h"
#include "prototyp.h"
#include "att_game.h"
#include "att_clas.h"

#include "allegro.h"
#include "math.h"
#include <process.h>//Temporary
#include "att_timer.h"

int main()
{
    
    allegro_init();
            //lock interrupt variables
    LOCK_VARIABLE(counter);
    LOCK_VARIABLE(ticks);
    LOCK_VARIABLE(framerate);
    
    LOCK_FUNCTION(timer1);
    //creates interrupt handler for timer --> timer1
    install_int(timer1,1000);//1000 is in milliseconds
    install_keyboard();
    srand(time(NULL));
//    main_game();
//    RealTime_Game();
    Turn_Game();
    destroy_bitmap(buffer);
    allegro_exit();
}
END_OF_MAIN()
