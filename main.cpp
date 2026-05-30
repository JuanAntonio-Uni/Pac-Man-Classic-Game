//Juego Pacman proyecto programacion 
//Luis Angel Maldonado Valenzuela
//Juan Antonio Torres Montoya 

#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

//#define REN 40
//#define COL 40
#define ANCHO_PTLL 600
#define LARGO_PTLL 800

//void menu();
//void gamebody();

int main(){
    char Punt_txt[] = "HIGH SCORE";
    InitWindow(ANCHO_PTLL, LARGO_PTLL, "Pac-Man-Classic-Game");
    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        //void menu();
        //Draw
        BeginDrawing();
        DrawText(Punt_txt, 175, 0, 40, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}