
#define ALLEGRO_STATICLINK
#include <allegro.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>

using namespace std;

int main()
{
    allegro_init();
    install_keyboard();
    
    
    fstream outputFile;
    outputFile.open("keys2.txt", ios::out);//opening file
    
    //writing in the file
    for(char ch='A';ch<='Z';ch++)
    outputFile  <<"    outputFile <<$"<<ch<<"^t$<<KEY_"<<ch<<"<<endl;\n";
    for(int ch=0;ch<10;ch++)
    outputFile  <<"    outputFile <<$"<<ch<<"^t$<<KEY_"<<ch<<"<<endl;\n";    
    for(int ch=0;ch<10;ch++)
    outputFile  <<"    outputFile <<$"<<ch<<"_PAD^t$<<KEY_"<<ch<<"_PAD<<endl;\n";    

    for(int ch=1;ch<13;ch++)
    outputFile  <<"    outputFile <<$F"<<ch<<"^t$<<KEY_F"<<ch<<"<<endl;\n";    

    
    outputFile.close();
    getch();
    allegro_exit();
    return 0;
}
END_OF_MAIN()
