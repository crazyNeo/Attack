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
    outputFile.open("keys.txt", ios::out);//opening file
    

    /*
    //writing in the file
    for(char ch='A';ch<='Z';ch++)
    outputFile  <<"    outputFile <<$"<<ch<<"^t$<<KEY_"<<ch<<"<<endl;\n";
    for(int ch=0;ch<10;ch++)
    outputFile  <<"    outputFile <<$"<<ch<<"^t$<<KEY_"<<ch<<"<<endl;\n";    
    for(int ch=0;ch<10;ch++)
    outputFile  <<"    outputFile <<$"<<ch<<"_PAD^t$<<KEY_"<<ch<<"_PAD<<endl;\n";    

    for(int ch=1;ch<13;ch++)
    outputFile  <<"    outputFile <<$F"<<ch<<"^t$<<KEY_F"<<ch<<"<<endl;\n";      
    */
    
    //writing in the file
    outputFile <<"A\t"<<KEY_A<<endl;
    outputFile <<"B\t"<<KEY_B<<endl;
    outputFile <<"C\t"<<KEY_C<<endl;
    outputFile <<"D\t"<<KEY_D<<endl;
    outputFile <<"E\t"<<KEY_E<<endl;
    outputFile <<"F\t"<<KEY_F<<endl;
    outputFile <<"G\t"<<KEY_G<<endl;
    outputFile <<"H\t"<<KEY_H<<endl;
    outputFile <<"I\t"<<KEY_I<<endl;
    outputFile <<"J\t"<<KEY_J<<endl;
    outputFile <<"K\t"<<KEY_K<<endl;
    outputFile <<"L\t"<<KEY_L<<endl;
    outputFile <<"M\t"<<KEY_M<<endl;
    outputFile <<"N\t"<<KEY_N<<endl;
    outputFile <<"O\t"<<KEY_O<<endl;
    outputFile <<"P\t"<<KEY_P<<endl;
    outputFile <<"Q\t"<<KEY_Q<<endl;
    outputFile <<"R\t"<<KEY_R<<endl;
    outputFile <<"S\t"<<KEY_S<<endl;
    outputFile <<"T\t"<<KEY_T<<endl;
    outputFile <<"U\t"<<KEY_U<<endl;
    outputFile <<"V\t"<<KEY_V<<endl;
    outputFile <<"W\t"<<KEY_W<<endl;
    outputFile <<"X\t"<<KEY_X<<endl;
    outputFile <<"Y\t"<<KEY_Y<<endl;
    outputFile <<"Z\t"<<KEY_Z<<endl;
    
    outputFile <<"0\t"<<KEY_0<<endl;
    outputFile <<"1\t"<<KEY_1<<endl;
    outputFile <<"2\t"<<KEY_2<<endl;
    outputFile <<"3\t"<<KEY_3<<endl;
    outputFile <<"4\t"<<KEY_4<<endl;
    outputFile <<"5\t"<<KEY_5<<endl;
    outputFile <<"6\t"<<KEY_6<<endl;
    outputFile <<"7\t"<<KEY_7<<endl;
    outputFile <<"8\t"<<KEY_8<<endl;
    outputFile <<"9\t"<<KEY_9<<endl;
    
    outputFile <<"F1\t"<<KEY_F1<<endl;
    outputFile <<"F2\t"<<KEY_F2<<endl;
    outputFile <<"F3\t"<<KEY_F3<<endl;
    outputFile <<"F4\t"<<KEY_F4<<endl;
    outputFile <<"F5\t"<<KEY_F5<<endl;
    outputFile <<"F6\t"<<KEY_F6<<endl;
    outputFile <<"F7\t"<<KEY_F7<<endl;
    outputFile <<"F8\t"<<KEY_F8<<endl;
    outputFile <<"F9\t"<<KEY_F9<<endl;
    outputFile <<"F10\t"<<KEY_F10<<endl;
    outputFile <<"F11\t"<<KEY_F11<<endl;
    outputFile <<"F12\t"<<KEY_F12<<endl;
    
    outputFile <<"ENTER\t"<<KEY_ENTER<<endl;
    outputFile <<"SPACE\t"<<KEY_SPACE<<endl;
    outputFile <<"BACKSPACE\t"<<KEY_BACKSPACE<<endl;
    outputFile <<"TAB\t"<<KEY_TAB<<endl;
    outputFile <<"LSHIFT\t"<<KEY_TAB<<endl;
    outputFile <<"RSHIFT\t"<<KEY_TAB<<endl;
    
    outputFile <<"INSERT\t"<<KEY_INSERT<<endl;
    outputFile <<"DEL\t"<<KEY_DEL<<endl;
    outputFile <<"HOME\t"<<KEY_HOME<<endl;
    outputFile <<"END\t"<<KEY_END<<endl;
    outputFile <<"PGUP\t"<<KEY_PGUP<<endl;
    outputFile <<"PGDN\t"<<KEY_PGDN<<endl;
    
    outputFile <<"UP\t"<<KEY_UP<<endl;
    outputFile <<"DOWN\t"<<KEY_DOWN<<endl;
    outputFile <<"LEFT\t"<<KEY_LEFT<<endl;
    outputFile <<"RIGHT\t"<<KEY_RIGHT<<endl;
    
    outputFile <<"0_PAD\t"<<KEY_0_PAD<<endl;
    outputFile <<"1_PAD\t"<<KEY_1_PAD<<endl;
    outputFile <<"2_PAD\t"<<KEY_2_PAD<<endl;
    outputFile <<"3_PAD\t"<<KEY_3_PAD<<endl;
    outputFile <<"4_PAD\t"<<KEY_4_PAD<<endl;
    outputFile <<"5_PAD\t"<<KEY_5_PAD<<endl;
    outputFile <<"6_PAD\t"<<KEY_6_PAD<<endl;
    outputFile <<"7_PAD\t"<<KEY_7_PAD<<endl;
    outputFile <<"8_PAD\t"<<KEY_8_PAD<<endl;
    outputFile <<"9_PAD\t"<<KEY_9_PAD<<endl;
    outputFile <<"9_ENTER\t"<<KEY_9_PAD<<endl;

    
    outputFile.close();
    getch();
    allegro_exit();
    return 0;
}
END_OF_MAIN()
