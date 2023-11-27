#include <conio.h>
#include <iostream>
#include <windows.h>
#include "menu.h"
using namespace std;
 
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
char s1[256];
void GotoXY(int X, int Y){
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
} 
 
void SetColor(int text, int background){
    SetConsoleTextAttribute(hStdOut, background*16+text);
}
 
char *Rus (char *s2) {
    AnsiToOem(s2,s1); 
    return s1; 
} 
 
void gamefunc()
{
    system ("cls");
    GotoXY(50,20);
    const char str[] = "начали игру=)\n";
    cout<<Rus("начали игру=)\n");
 
}
 
void menu(){  
    int f=1,k,code;
    SetColor(0,0);
    GotoXY(27,12);
    SetColor(14,0);
    const char str[] = "-->Новая игра<--"; 
    cout<<Rus("-->Новая игра<--");
    GotoXY(30,13);
    SetColor(15,0); 
    const char str[] = "   Выход   ";
    cout<<Rus("   Выход   ");
    do{
        k=0;
        code=getch();
        if (code==224||code==0)
            code=getch();
        if(code==80){
            f=f*(-1);
            if (f==1){
                const char str[] = "-->Новая игра<--";
                GotoXY(27,12); SetColor(14,0); cout<<Rus("-->Новая игра<--");
                const char str[] = "-->Новая игра<--";
                GotoXY(30,13); SetColor(15,0); cout<<Rus("   Выход   ");
            }else{ 
                const char str[] = "-->Новая игра<--";
                GotoXY(27,12); SetColor(15,0); cout<<Rus("   Новая игра   ");
                const char str[] = "-->Новая игра<--";
                GotoXY(30,13); SetColor(14,0); cout<<Rus("-->Выход<--");
            }
        }else if(code==72){
            f=f*(-1);
            if (f==1){
                GotoXY(27,12); SetColor(14,0); cout<<Rus("-->Новая игра<--");
                GotoXY(30,13); SetColor(15,0); cout<<Rus("   Выход   ");
            }else{ 
                GotoXY(27,12); SetColor(15,0);  cout<<Rus("   Новая игра   ");
                GotoXY(30,13); SetColor(14,0); cout<<Rus("-->Выход<--");
            }
        }else if(code==13) k=1; 
    }while (k==0);
    if(f!=1) exit(0);
    //дальше запускаем функцию игры=)
    gamefunc();
}
 
int main(){
    menu();
}