#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
int main()
{
    
    
    
                 int x;
                 float y;
                 float g=9.8;
                 x=100;
                 y=451/5.0;
                 float mov_angl=45/180.0*128;
                 double angle=mov_angl/128.0*M_PI;
                 
                 double de,nu;
                 nu=g*x*x;
                 de=2*cos(angle)*cos(angle)*(x*tan(angle)-y);
                 double vel=pow(nu/de,.5);                 
                 
                 cout <<"velocity "<<nu<<"/"<<de<<endl;
                 cout <<"velocity "<<vel;
                 getchar();
    return 0;
}
