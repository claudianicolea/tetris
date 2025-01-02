/*

    0 - black
    1 - blue
    2 - green
    3 - aqua
    4 - red
    5 - purple
    6 - yellow
    7 - white
    8 - gray
    9 - light blue
    10 / A - light green
    11 / B - light aqua
    12 / C - light red
    13 / D - light purple
    14 / E - light yellow
    15 / F - bright white

*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void gotoxy(int x, int y){
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void hidecursor(int visible){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}

void shape(int appear_disappear_rest, int mat[26][36], int x, int y, int shape_nr, int rotation){

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    // 0 - disappear
    // 1 - appear and move
    // 2 - (appear and) rest

    if(shape_nr==1){
        if(appear_disappear_rest==0) SetConsoleTextAttribute(h, 9*16+7);
        if(appear_disappear_rest==1) SetConsoleTextAttribute(h, 9*16+1);

        if(appear_disappear_rest==2){
            mat[y][x]=21;
            mat[y][x+1]=21;
            mat[y+1][x]=21;
            mat[y+1][x+1]=21;
        }else{
            mat[y][x]=appear_disappear_rest;
            mat[y][x+1]=appear_disappear_rest;
            mat[y+1][x]=appear_disappear_rest;
            mat[y+1][x+1]=appear_disappear_rest;
        }

        gotoxy(x, y);
        printf("%c", 178);
        gotoxy(x+1, y);
        printf("%c", 178);
        gotoxy(x, y+1);
        printf("%c", 178);
        gotoxy(x+1, y+1);
        printf("%c", 178);
    }

    if(shape_nr==2){
        if(appear_disappear_rest==0) SetConsoleTextAttribute(h, 9*16+7);
        if(appear_disappear_rest==1) SetConsoleTextAttribute(h, 9*16+2);

        if(rotation==1 || rotation==3){

            if(appear_disappear_rest==2){
                mat[y][x]=22;
                mat[y+1][x]=22;
                mat[y+2][x]=22;
                mat[y+3][x]=22;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+2][x]=appear_disappear_rest;
                mat[y+3][x]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x, y+2);
            printf("%c", 178);
            gotoxy(x, y+3);
            printf("%c", 178);
        }
        if(rotation==2 || rotation==4){

            if(appear_disappear_rest==2){
                mat[y][x]=22;
                mat[y][x+1]=22;
                mat[y][x+2]=22;
                mat[y][x+3]=22;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y][x+1]=appear_disappear_rest;
                mat[y][x+2]=appear_disappear_rest;
                mat[y][x+3]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+2, y);
            printf("%c", 178);
            gotoxy(x+3, y);
            printf("%c", 178);
        }
    }

    if(shape_nr==3){
        if(appear_disappear_rest==0) SetConsoleTextAttribute(h, 9*16+7);
        if(appear_disappear_rest==1) SetConsoleTextAttribute(h, 9*16+3);

        if(rotation==1 || rotation==3){

            if(appear_disappear_rest==2){
                mat[y][x+1]=23;
                mat[y+1][x]=23;
                mat[y+1][x+1]=23;
                mat[y+2][x]=23;
            }else{
                mat[y][x+1]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y+2][x]=appear_disappear_rest;
            }

            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x, y+2);
            printf("%c", 178);
        }
        if(rotation==2 || rotation==4){

            if(appear_disappear_rest==2){
                mat[y][x]=23;
                mat[y][x+1]=23;
                mat[y+1][x+1]=23;
                mat[y+1][x+2]=23;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y][x+1]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y+1][x+2]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x+2, y+1);
            printf("%c", 178);
        }
    }

    if(shape_nr==4){
        if(appear_disappear_rest==0) SetConsoleTextAttribute(h, 9*16+7);
        if(appear_disappear_rest==1) SetConsoleTextAttribute(h, 9*16+4);

        if(rotation==1 || rotation==3){
            if(appear_disappear_rest==2){
                mat[y][x]=24;
                mat[y+1][x]=24;
                mat[y+1][x+1]=24;
                mat[y+2][x+1]=24;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y+2][x+1]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+2);
            printf("%c", 178);
        }
        if(rotation==2 || rotation==4){

            if(appear_disappear_rest==2){
                mat[y][x+1]=24;
                mat[y][x+2]=24;
                mat[y+1][x]=24;
                mat[y+1][x+1]=24;
            }else{
                mat[y][x+1]=appear_disappear_rest;
                mat[y][x+2]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
            }

            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+2, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
        }
    }

    if(shape_nr==5){
        if(appear_disappear_rest==0) SetConsoleTextAttribute(h, 9*16+7);
        if(appear_disappear_rest==1) SetConsoleTextAttribute(h, 9*16+5);

        if(rotation==1){

            if(appear_disappear_rest==2){
                mat[y][x]=25;
                mat[y][x+1]=25;
                mat[y][x+2]=25;
                mat[y+1][x+2]=25;
                mat[y+2][x+2]=25;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y][x+1]=appear_disappear_rest;
                mat[y][x+2]=appear_disappear_rest;
                mat[y+1][x+2]=appear_disappear_rest;
                mat[y+2][x+2]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+2, y);
            printf("%c", 178);
            gotoxy(x+2, y+1);
            printf("%c", 178);
            gotoxy(x+2, y+2);
            printf("%c", 178);
        }
        if(rotation==2){

            if(appear_disappear_rest==2){
                mat[y+2][x]=25;
                mat[y+2][x+1]=25;
                mat[y+2][x+2]=25;
                mat[y+1][x+2]=25;
                mat[y][x+2]=25;
            }else{
                mat[y+2][x]=appear_disappear_rest;
                mat[y+2][x+1]=appear_disappear_rest;
                mat[y+2][x+2]=appear_disappear_rest;
                mat[y+1][x+2]=appear_disappear_rest;
                mat[y][x+2]=appear_disappear_rest;
            }

            gotoxy(x, y+2);
            printf("%c", 178);
            gotoxy(x+1, y+2);
            printf("%c", 178);
            gotoxy(x+2, y+2);
            printf("%c", 178);
            gotoxy(x+2, y+1);
            printf("%c", 178);
            gotoxy(x+2, y);
            printf("%c", 178);
        }
        if(rotation==3){

            if(appear_disappear_rest==2){
                mat[y][x]=25;
                mat[y+1][x]=25;
                mat[y+2][x]=25;
                mat[y+2][x+1]=25;
                mat[y+2][x+2]=25;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+2][x]=appear_disappear_rest;
                mat[y+2][x+1]=appear_disappear_rest;
                mat[y+2][x+2]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x, y+2);
            printf("%c", 178);
            gotoxy(x+1, y+2);
            printf("%c", 178);
            gotoxy(x+2, y+2);
            printf("%c", 178);
        }
        if(rotation==4){

            if(appear_disappear_rest==2){
                mat[y][x]=25;
                mat[y][x+1]=25;
                mat[y][x+2]=25;
                mat[y+1][x]=25;
                mat[y+2][x]=25;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y][x+1]=appear_disappear_rest;
                mat[y][x+2]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+2][x]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+2, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x, y+2);
            printf("%c", 178);
        }
    }

    if(shape_nr==6){
        if(appear_disappear_rest==0) SetConsoleTextAttribute(h, 9*16+7);
        if(appear_disappear_rest==1) SetConsoleTextAttribute(h, 9*16+6);

        if(rotation==1){

            if(appear_disappear_rest==2){
                mat[y][x]=26;
                mat[y][x+1]=26;
                mat[y+1][x+1]=26;
                mat[y+2][x+1]=26;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y][x+1]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y+2][x+1]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+2);
            printf("%c", 178);
        }
        if(rotation==2){

            if(appear_disappear_rest==2){
                mat[y][x+2]=26;
                mat[y+1][x]=26;
                mat[y+1][x+1]=26;
                mat[y+1][x+2]=26;
            }else{
                mat[y][x+2]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y+1][x+2]=appear_disappear_rest;
            }

            gotoxy(x+2, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x+2, y+1);
            printf("%c", 178);
        }
        if(rotation==3){

            if(appear_disappear_rest==2){
                mat[y][x]=26;
                mat[y+1][x]=26;
                mat[y+2][x]=26;
                mat[y+2][x+1]=26;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+2][x]=appear_disappear_rest;
                mat[y+2][x+1]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x, y+2);
            printf("%c", 178);
            gotoxy(x+1, y+2);
            printf("%c", 178);
        }
        if(rotation==4){

            if(appear_disappear_rest==2){
                mat[y][x]=26;
                mat[y][x+1]=26;
                mat[y][x+2]=26;
                mat[y+1][x]=26;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y][x+1]=appear_disappear_rest;
                mat[y][x+2]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+2, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
        }
    }

    if(shape_nr==7){
        if(appear_disappear_rest==0) SetConsoleTextAttribute(h, 9*16+7);
        if(appear_disappear_rest==1) SetConsoleTextAttribute(h, 9*16+12);

        if(rotation==1){

            if(appear_disappear_rest==2){
                mat[y][x]=27;
                mat[y+1][x]=27;
                mat[y+2][x]=27;
                mat[y][x+1]=27;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+2][x]=appear_disappear_rest;
                mat[y][x+1]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x, y+2);
            printf("%c", 178);
            gotoxy(x+1, y);
            printf("%c", 178);
        }
        if(rotation==2){

            if(appear_disappear_rest==2){
                mat[y][x]=27;
                mat[y][x+1]=27;
                mat[y][x+2]=27;
                mat[y+1][x+2]=27;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y][x+1]=appear_disappear_rest;
                mat[y][x+2]=appear_disappear_rest;
                mat[y+1][x+2]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+2, y);
            printf("%c", 178);
            gotoxy(x+2, y+1);
            printf("%c", 178);
        }
        if(rotation==3){

            if(appear_disappear_rest==2){
                mat[y][x+1]=27;
                mat[y+1][x+1]=27;
                mat[y+2][x+1]=27;
                mat[y+2][x]=27;
            }else{
                mat[y][x+1]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y+2][x+1]=appear_disappear_rest;
                mat[y+2][x]=appear_disappear_rest;
            }

            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+2);
            printf("%c", 178);
            gotoxy(x, y+2);
            printf("%c", 178);
        }
        if(rotation==4){

            if(appear_disappear_rest==2){
                mat[y][x]=27;
                mat[y+1][x]=27;
                mat[y+1][x+1]=27;
                mat[y+1][x+2]=27;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y+1][x+2]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x+2, y+1);
            printf("%c", 178);
        }
    }

    if(shape_nr==8){
        if(appear_disappear_rest==0) SetConsoleTextAttribute(h, 9*16+7);
        if(appear_disappear_rest==1) SetConsoleTextAttribute(h, 9*16+13);

        if(rotation==1){

            if(appear_disappear_rest==2){
                mat[y][x]=28;
                mat[y][x+1]=28;
                mat[y+1][x+1]=28;
                mat[y][x+2]=28;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y][x+1]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y][x+2]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x+2, y);
            printf("%c", 178);
        }
        if(rotation==2){

            if(appear_disappear_rest==2){
                mat[y][x+1]=28;
                mat[y+1][x]=28;
                mat[y+1][x+1]=28;
                mat[y+2][x+1]=28;
            }else{
                mat[y][x+1]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y+2][x+1]=appear_disappear_rest;
            }

            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+2);
            printf("%c", 178);
        }
        if(rotation==3){

            if(appear_disappear_rest==2){
                mat[y+1][x]=28;
                mat[y+1][x+1]=28;
                mat[y][x+1]=28;
                mat[y+1][x+2]=28;
            }else{
                mat[y+1][x]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y][x+1]=appear_disappear_rest;
                mat[y+1][x+2]=appear_disappear_rest;
            }

            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x+1, y);
            printf("%c", 178);
            gotoxy(x+2, y+1);
            printf("%c", 178);
        }
        if(rotation==4){

            if(appear_disappear_rest==2){
                mat[y][x]=28;
                mat[y+1][x]=28;
                mat[y+1][x+1]=28;
                mat[y+2][x]=28;
            }else{
                mat[y][x]=appear_disappear_rest;
                mat[y+1][x]=appear_disappear_rest;
                mat[y+1][x+1]=appear_disappear_rest;
                mat[y+2][x]=appear_disappear_rest;
            }

            gotoxy(x, y);
            printf("%c", 178);
            gotoxy(x, y+1);
            printf("%c", 178);
            gotoxy(x+1, y+1);
            printf("%c", 178);
            gotoxy(x, y+2);
            printf("%c", 178);
        }
    }

}

int fall_into_place(int mat[26][36], int x, int y, int shape_nr, int rotation){
    int go;
    go=0;

    if(shape_nr==1){
        if(mat[y+1][x]==0 && mat[y+1][x+1]==0) go=1;
    }

    if(shape_nr==2){
        if(rotation==1 || rotation==3)
            if(mat[y+3][x]==0) go=1;
        if(rotation==2 || rotation==4)
            if(mat[y][x]==0 && mat[y][x+1]==0 && mat[y][x+2]==0 && mat[y][x+3]==0) go=1;
    }

    if(shape_nr==3){
        if(rotation==1 || rotation==3)
            if(mat[y+2][x]==0 && mat[y+1][x+1]==0) go=1;
        if(rotation==2 || rotation==4)
            if(mat[y][x]==0 && mat[y+1][x+1]==0 && mat[y+1][x+2]==0) go=1;
    }

    if(shape_nr==4){
        if(rotation==1 || rotation==3)
            if(mat[y+1][x]==0 && mat[y+2][x+1]==0) go=1;
        if(rotation==2 || rotation==4)
            if(mat[y+1][x]==0 && mat[y+1][x+1]==0 && mat[y][x+2]==0) go=1;
    }

    if(shape_nr==5){
        if(rotation==1)
            if(mat[y][x]==0 && mat[y][x+1]==0 && mat[y+2][x+2]==0) go=1;
        if(rotation==2)
            if(mat[y+2][x]==0 && mat[y+2][x+1]==0 && mat[y+2][x+2]==0) go=1;
        if(rotation==3)
            if(mat[y+2][x]==0 && mat[y+2][x+1]==0 && mat[y+2][x+2]==0) go=1;
        if(rotation==4)
            if(mat[y+2][x]==0 && mat[y][x+1]==0 && mat[y][x+2]==0) go=1;
    }

    if(shape_nr==6){
        if(rotation==1)
            if(mat[y][x]==0 && mat[y+2][x+1]==0) go=1;
        if(rotation==2)
            if(mat[y+1][x]==0 && mat[y+1][x+1]==0 && mat[y+1][x+2]==0) go=1;
        if(rotation==3)
            if(mat[y+2][x]==0 && mat[y+2][x+1]==0) go=1;
        if(rotation==4)
            if(mat[y+1][x]==0 && mat[y][x+1]==0 && mat[y][x+2]==0) go=1;
    }

    if(shape_nr==7){
        if(rotation==1)
            if(mat[y+2][x]==0 && mat[y][x+1]==0) go=1;
        if(rotation==2)
            if(mat[y][x]==0 && mat[y][x+1]==0 && mat[y+1][x+2]==0) go=1;
        if(rotation==3)
            if(mat[y+2][x]==0 && mat[y+2][x+1]==0) go=1;
        if(rotation==4)
            if(mat[y+1][x]==0 && mat[y+1][x+1]==0 && mat[y+1][x+2]==0) go=1;
    }

    if(shape_nr==8){
        if(rotation==1)
            if(mat[y][x]==0 && mat[y+1][x+1]==0 && mat[y][x+2]==0) go=1;
        if(rotation==2)
            if(mat[y+1][x]==0 && mat[y+2][x+1]==0) go=1;
        if(rotation==3)
            if(mat[y+1][x]==0 && mat[y+1][x+1]==0 && mat[y+1][x+2]==0) go=1;
        if(rotation==4)
            if(mat[y+2][x]==0 && mat[y+1][x+1]==0) go=1;
    }

    return go;
}

int move_x_right(int mat[26][36], int x, int y, int shape_nr, int rotation){
    int go;
    go=0;

    // go=1 - can move to the right
    // go=2 - can move to the left

    if(shape_nr==1){
        if(mat[y][x+1]==0 && mat[y+1][x+1]==0) go=1; // use x+1 when using function
    }

    if(shape_nr==2){
        if(rotation==1 || rotation==3)
            if(mat[y][x]==0 && mat[y+1][x]==0 && mat[y+2][x]==0 && mat[y+3][x]==0){
                go=1; // use x+1 (right)
            }
        if(rotation==2 || rotation==4)
            if(mat[y][x+3]==0){
                go=1; // use x+1 (right)
            }
    }

    if(shape_nr==3){
        if(rotation==1 || rotation==3){
            if(mat[y][x+1]==0 && mat[y+1][x+1]==0 && mat[y+2][x]==0) go=1; // right
        }
        if(rotation==2 || rotation==4){
            if(mat[y][x+1]==0 && mat[y+1][x+2]==0) go=1; // right
        }
    }

    if(shape_nr==4){
        if(rotation==1 || rotation==3){
            if(mat[y][x]==0 && mat[y+1][x+1]==0 && mat[y+2][x+1]==0) go=1; // right
        }
        if(rotation==2 || rotation==4){
            if(mat[y][x+2]==0 && mat[y+1][x+1]==0) go=1; // right
        }
    }

    if(shape_nr==5){
        if(rotation==1){
            if(mat[y][x+2]==0 && mat[y+1][x+2]==0 && mat[y+2][x+2]==0) go=1; // right
        }
        if(rotation==2){
            if(mat[y][x+2]==0 && mat[y+1][x+2]==0 && mat[y+2][x+2]==0) go=1; // right
        }
        if(rotation==3){
            if(mat[y][x]==0 && mat[y+1][x]==0 && mat[y+2][x+2]==0) go=1; // right
        }
        if(rotation==4){
            if(mat[y][x]==0 && mat[y+1][x]==0 && mat[y+2][x]==0) go=1; // right
        }
    }

    if(shape_nr==6){
        if(rotation==1){
            if(mat[y][x+1]==0 && mat[y+1][x+1]==0 && mat[y+2][x+1]==0) go=1; // right
        }
        if(rotation==2){
            if(mat[y][x+2]==0 && mat[y+1][x+2]==0) go=1; // right
        }
        if(rotation==3){
            if(mat[y][x]==0 && mat[y+1][x]==0 && mat[y+2][x+1]==0) go=1; // right
        }
        if(rotation==4){
            if(mat[y][x+2]==0 && mat[y+1][x]==0) go=1; // right
        }
    }

    if(shape_nr==7){
        if(rotation==1){
            if(mat[y][x+1]==0 && mat[y+1][x]==0 && mat[y+2][x]==0) go=1; // right
        }
        if(rotation==2){
            if(mat[y][x+2]==0 && mat[y+1][x+2]==0) go=1; // right
        }
        if(rotation==3){
            if(mat[y][x+1]==0 && mat[y+1][x+1]==0 && mat[y+2][x+1]==0) go=1; // right
        }
        if(rotation==4){
            if(mat[y][x]==0 && mat[y+1][x+2]==0) go=1; // right
        }
    }

    if(shape_nr==8){
        if(rotation==1){
            if(mat[y][x+2]==0 && mat[y+1][x+1]==0) go=1; // right
        }
        if(rotation==2){
            if(mat[y][x+1]==0 && mat[y+1][x+1]==0 && mat[y+2][x+1]==0) go=1; // right
        }
        if(rotation==3){
            if(mat[y][x+1]==0 && mat[y+1][x+2]==0) go=1; // right
        }
        if(rotation==4){
            if(mat[y][x]==0 && mat[y+1][x+1]==0 && mat[y+2][x]==0) go=1; // right
        }
    }

    return go;
}

int move_x_left(int mat[26][36], int x, int y, int shape_nr, int rotation){
    int go;
    go=0;

    // go=1 - can move to the right
    // go=2 - can move to the left

    if(shape_nr==1){
        if(mat[y][x]==0 && mat[y+1][x]==0) go=2; // use x-1 when using function
    }

    if(shape_nr==2){
        if(rotation==1 || rotation==3)
            if(mat[y][x]==0 && mat[y+1][x]==0 && mat[y+2][x]==0 && mat[y+3][x]==0){
                go=2; // use x-1 (left)
            }
        if(rotation==2 || rotation==4)
            if(mat[y][x]==0){
                go=2; // use x-1 (left)
            }
    }

    if(shape_nr==3){
        if(rotation==1 || rotation==3){
            if(mat[y][x+1]==0 && mat[y+1][x]==0 && mat[y+2][x]==0) go=2; // left
        }
        if(rotation==2 || rotation==4){
            if(mat[y][x]==0 && mat[y+1][x+1]==0) go=2; // left
        }
    }

    if(shape_nr==4){
        if(rotation==1 || rotation==3){
            if(mat[y][x]==0 && mat[y+1][x]==0 && mat[y+2][x+1]==0) go=2; // left
        }
        if(rotation==2 || rotation==4){
            if(mat[y][x+1]==0 && mat[y+1][x]==0) go=2; // left
        }
    }

    if(shape_nr==5){
        if(rotation==1){
            if(mat[y][x]==0 && mat[y+1][x+2]==0 && mat[y+2][x+2]==0) go=2; // left
        }
        if(rotation==2){
            if(mat[y][x+2]==0 && mat[y+1][x+2]==0 && mat[y+2][x]==0) go=2; // left
        }
        if(rotation==3){
            if(mat[y][x]==0 && mat[y+1][x]==0 && mat[y+2][x]==0) go=2; // left
        }
        if(rotation==4){
            if(mat[y][x+2]==0 && mat[y+1][x]==0 && mat[y+2][x]==0) go=2; // left
        }
    }

    if(shape_nr==6){
        if(rotation==1){
            if(mat[y][x]==0 && mat[y+1][x+1]==0 && mat[y+2][x+1]==0) go=2; // left
        }
        if(rotation==2){
            if(mat[y][x+2]==0 && mat[y+1][x]==0) go=2; // left
        }
        if(rotation==3){
            if(mat[y][x]==0 && mat[y+1][x]==0 && mat[y+2][x]==0) go=2; // left
        }
        if(rotation==4){
            if(mat[y][x]==0 && mat[y+1][x]==0) go=2; // left
        }
    }

    if(shape_nr==7){
        if(rotation==1){
            if(mat[y][x]==0 && mat[y+1][x]==0 && mat[y+2][x]==0) go=2; // left
        }
        if(rotation==2){
            if(mat[y][x]==0 && mat[y+1][x+2]==0) go=2; // left
        }
        if(rotation==3){
            if(mat[y][x+1]==0 && mat[y+1][x+1]==0 && mat[y+2][x]==0) go=2; // left
        }
        if(rotation==4){
            if(mat[y][x]==0 && mat[y+1][x]==0) go=2; // left
        }
    }

    if(shape_nr==8){
        if(rotation==1){
            if(mat[y][x]==0 && mat[y+1][x+1]==0) go=2; // left
        }
        if(rotation==2){
            if(mat[y][x+1]==0 && mat[y+1][x]==0 && mat[y+2][x+1]==0) go=2; // left
        }
        if(rotation==3){
            if(mat[y][x+1]==0 && mat[y+1][x]==0) go=2; // left
        }
        if(rotation==4){
            if(mat[y][x]==0 && mat[y+1][x]==0 && mat[y+2][x]==0) go=2; // left
        }
    }

    return go;
}

int main(){

    hidecursor(0);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    srand((unsigned)time(0));


    int mat[26][36], i, j, x, y, shape_nr, rotation, shape_lowest_point[10][5], fall, game, max_x[10][5], score, row_completed, speed;
    char c;
    int color;

    max_x[1][1]=1;
    max_x[1][2]=1;
    max_x[1][3]=1;
    max_x[1][4]=1;

    max_x[2][1]=0;
    max_x[2][2]=3;
    max_x[2][3]=0;
    max_x[2][4]=3;

    max_x[3][1]=1;
    max_x[3][2]=2;
    max_x[3][3]=1;
    max_x[3][4]=2;

    max_x[4][1]=1;
    max_x[4][2]=2;
    max_x[4][3]=1;
    max_x[4][4]=2;

    max_x[5][1]=2;
    max_x[5][2]=2;
    max_x[5][3]=2;
    max_x[5][4]=2;

    max_x[6][1]=1;
    max_x[6][2]=2;
    max_x[6][3]=1;
    max_x[6][4]=2;

    max_x[7][1]=1;
    max_x[7][2]=2;
    max_x[7][3]=1;
    max_x[7][4]=2;

    max_x[8][1]=2;
    max_x[8][2]=1;
    max_x[8][3]=2;
    max_x[8][4]=1;

    // INCEPUT JOC

    while(1){

    //DEFAULT
        SetConsoleTextAttribute(h, 9*16+0);
        system("CLS");
        system("Color 90");
        color=4;
        c=0;
        score=0;

        while(c!='2'){
            c=0;
                Sleep(150);
            SetConsoleTextAttribute(h, 9*16+0);
            gotoxy(50, 3);
            printf("Welcome to");
            SetConsoleTextAttribute(h, 9*16+color);
            gotoxy(52, 5);
            printf("TETRIS");
            color++;
            if(color==9) color=4;
            SetConsoleTextAttribute(h, 9*16+0);
            gotoxy(60, 10);
            printf("Press 1 to read the rules of the game");
            gotoxy(60, 12);
            printf("Press 2 to start the game");
            if(kbhit()) c=getch();

            if(c=='1'){
                system("CLS");
                c=0;
                while(c!='1'){
                    SetConsoleTextAttribute(h, 9*16+6);
                    gotoxy(10, 3);
                    printf("Controls:");
                    gotoxy(25, 5);
                    printf("E - left");
                    gotoxy(25, 6);
                    printf("R - rotate");
                    gotoxy(25, 7);
                    printf("T - right");

                    SetConsoleTextAttribute(h, 9*16+6);
                    gotoxy(40, 3);
                    printf("Instructions:");
                    gotoxy(55, 5);
                    printf("You receive 5 points for each completed row.");
                    gotoxy(55, 6);
                    printf("The game finishes if you reach the top row.");
                    gotoxy(55, 7);
                    printf("You can pause the game by pressing P.");

                    SetConsoleTextAttribute(h, 9*16+14);
                    gotoxy(30, 10);
                    printf("Good luck!");

                    SetConsoleTextAttribute(h, 9*16+0);
                    gotoxy(60, 11);
                    printf("Press 1 to go back to the main screen.");
                    if(kbhit()) c=getch();
                }
                system("CLS");
            }
        }
        c=0;
        system("CLS");
        system("Color 97");

        for(i=0; i<25; i++){ // ca sa nu fie nr random in matrice
            for(j=0; j<35; j++){
                mat[i][j]=0;
            }
        }
        for(i=0; i<35; i++) mat[25][i]=3;

        for(i=0; i<25; i++){ // matricea alba
            for(j=0; j<35; j++)
                printf("%c", 178);
            printf("\n");
        }
        SetConsoleTextAttribute(h, 7*16+1);
        for(i=40; i<=90; i++)
                for(j=5; j<=11; j++){
                    gotoxy(i, j);
                    printf(" ");
                }
        gotoxy(45, 6);
        printf("E");
        gotoxy(45, 7);
        printf("|");
        gotoxy(42, 8);
        printf("Left");

        gotoxy(50, 6);
        printf("R");
        gotoxy(50, 7);
        printf("|");
        gotoxy(47, 8);
        printf("Rotate");

        gotoxy(55, 6);
        printf("T");
        gotoxy(55, 7);
        printf("|");
        gotoxy(55, 8);
        printf("Right");

        gotoxy(84, 6);
        printf("P");
        gotoxy(84, 7);
        printf("|");
        gotoxy(84, 8);
        printf("Pause");

        SetConsoleTextAttribute(h, 9*16+1);
        gotoxy(45, 10);
        printf("Score: %d", score);

        game=1;
        speed=300;
        score=0;

        while(game){

            for(i=0; i<25; i++){ // reseteaza randul
                row_completed=0;
                for(i=0; i<35; i++){
                    if(mat[i][j]/10==2) row_completed++;
                }
                if(row_completed==35){
                    for(i=24; i>=0; i--){
                        for(j=0; j<35; j++){
                            mat[i][j]=mat[i-1][j];

                            if(mat[i][j]==0) SetConsoleTextAttribute(h, 9*16+7);
                            if(mat[i][j]==21) SetConsoleTextAttribute(h, 9*16+1);
                            if(mat[i][j]==22) SetConsoleTextAttribute(h, 9*16+2);
                            if(mat[i][j]==23) SetConsoleTextAttribute(h, 9*16+3);
                            if(mat[i][j]==24) SetConsoleTextAttribute(h, 9*16+4);
                            if(mat[i][j]==25) SetConsoleTextAttribute(h, 9*16+5);
                            if(mat[i][j]==26) SetConsoleTextAttribute(h, 9*16+6);
                            if(mat[i][j]==27) SetConsoleTextAttribute(h, 9*16+12);
                            if(mat[i][j]==28) SetConsoleTextAttribute(h, 9*16+13);

                            gotoxy(j, i);
                            printf("%c", 178);
                        }
                    }
                    score=score+5;
                }
            }

            x=rand()%30;
            y=-1;
            shape_nr=(rand()%8)+1;
            rotation=1;
            fall=1;
            if(speed>150) speed=speed-1;

            while(fall==1){

                if(kbhit()){ c=getch();

                    if(c=='p'){
                        c=0;
                        shape(1, mat, x, y, shape_nr, rotation);
                        SetConsoleTextAttribute(h, 1*16+15);
                        for(i=40; i<=90; i++)
                            for(j=5; j<=15; j++){
                                gotoxy(i, j);
                                printf(" ");
                            }
                        gotoxy(60, 6);
                        printf("GAME PAUSED");
                        gotoxy(57, 11);
                        printf("Press Q to quit.");
                        gotoxy(57, 13);
                        printf("Press P to continue.");
                        c=getch();
                        while(c!='p' && c!='q') c=getch();
                        if(c=='q'){
                            game=0;
                            fall=0;
                        }else{
                            SetConsoleTextAttribute(h, 9*16+7);
                            for(i=40; i<=90; i++)
                                for(j=5; j<=15; j++){
                                    gotoxy(i, j);
                                    printf(" ");
                                }
                            SetConsoleTextAttribute(h, 7*16+1);
                            for(i=40; i<=90; i++)
                                    for(j=5; j<=11; j++){
                                        gotoxy(i, j);
                                        printf(" ");
                                    }
                            gotoxy(45, 6);
                            printf("E");
                            gotoxy(45, 7);
                            printf("|");
                            gotoxy(42, 8);
                            printf("Left");

                            gotoxy(50, 6);
                            printf("R");
                            gotoxy(50, 7);
                            printf("|");
                            gotoxy(47, 8);
                            printf("Rotate");

                            gotoxy(55, 6);
                            printf("T");
                            gotoxy(55, 7);
                            printf("|");
                            gotoxy(55, 8);
                            printf("Right");

                            gotoxy(84, 6);
                            printf("P");
                            gotoxy(84, 7);
                            printf("|");
                            gotoxy(84, 8);
                            printf("Pause");

                            SetConsoleTextAttribute(h, 9*16+1);
                            gotoxy(45, 10);
                            printf("Score: %d", score);
                            shape(0, mat, x, y, shape_nr, rotation);
                        }
                    }else{
                        if(c=='r'){
                            rotation++;
                            if(rotation==5) rotation=1;
                            //c=0;
                            shape(1, mat, x, y, shape_nr, rotation);
                            Sleep(50);
                        }
                        if(c=='t' && x+max_x[shape_nr][rotation]<34){ // move right (T)
                            if((shape_nr==2 && (rotation==2 || rotation==4)) || shape_nr!=2){
                                if(move_x_right(mat, x+max_x[shape_nr][rotation], y, shape_nr, rotation)==1) x++;
                            }else{
                                x++;
                            }
                        }
                        if(c=='e' && x>0) // move left (E)
                            if(move_x_left(mat, x-1, y, shape_nr, rotation)==2)
                                x--;

                        shape(1, mat, x, y, shape_nr, rotation);
                        // Sleep(speed);
                        shape(0, mat, x, y, shape_nr, rotation);
                        fall=fall_into_place(mat, x, y+1, shape_nr, rotation);
                    }
                }
                else{
                    y++;
                    shape(1, mat, x, y, shape_nr, rotation);
                    Sleep(speed);
                    shape(0, mat, x, y, shape_nr, rotation);
                    fall=fall_into_place(mat, x, y+1, shape_nr, rotation);
                }
            }
            shape(1, mat, x, y, shape_nr, rotation);
            shape(2, mat, x, y, shape_nr, rotation);
            if(y==0){
                Sleep(150);
                game=0;
            }
        }
        SetConsoleTextAttribute(h, 4*16+15);
        for(i=40; i<=90; i++)
                for(j=5; j<=15; j++){
                    gotoxy(i, j);
                    printf(" ");
                }
        gotoxy(55, 6);
        printf("Thanks for playing!");
        gotoxy(45, 9);
        printf("Your score: %d", score);
        gotoxy(60, 13);
        printf("Press ENTER to start again.");

        c=getch();
        while(c!=13) c=getch();
    }
}
