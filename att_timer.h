#pragma once

//tmer variable declaration
volatile int counter,ticks,framerate,resting,rested,cor_rest=8;

//function definition for timer
void timer1(void)
{
     counter++;
     framerate=ticks;
     ticks=0;
     rested=resting;
}
END_OF_FUNCTION(timer1)

void rest1(void)
{
     resting++;
}

void* auto_framerate(int desir=60)
{
     static int framerate1=desir,
                framerate2=desir,
                framerate3=desir,
                framerate4=desir;
     //finding mean
     float mean_fr_rate=(framerate4+framerate3+framerate2+framerate1+framerate)/5.0;
     framerate4=framerate3;
     framerate3=framerate2;
     framerate2=framerate1;
     framerate1=framerate;
     int delta=desir/10;//10%=10/100 of ()
     if (cor_rest>0 && mean_fr_rate<desir-delta)
         cor_rest--;        
     else if (mean_fr_rate>desir+delta)
         cor_rest++;     
}
