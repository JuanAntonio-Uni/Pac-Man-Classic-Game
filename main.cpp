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
#define CL_FROJO GetColor(0xFF0000FF)
#define CL_FROSA GetColor(0xffb8ffFF)
#define CL_FAZUL GetColor(0x00ffffFF)
#define CL_FNARANJA GetColor(0xffb852FF)

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
        DrawText(Punt_txt, 204, 0, 30, WHITE);
        DrawText("CHARACTER / NICKNAME", 150, 70, 30, WHITE);
        DrawText("-SHADOW     \"BLINKY\"", 155, 120, 30, CL_FROJO);
        DrawText("-SPEEDY     \"PINKY\"", 155, 200, 30, CL_FROSA);
        DrawText("-BASHFUL    \"INKY\"", 155, 280, 30, CL_FAZUL);
        DrawText("-POKEY       \"CLYDE\"", 155, 360, 30, CL_FNARANJA);
        DrawCircle(250, 500, 3, WHITE);
        DrawText("10", 270, 485, 30, WHITE);
        DrawText("PTS", 315, 490, 20, WHITE);
        DrawCircle(250, 560, 10, WHITE);
        DrawText("50", 270, 545, 30, WHITE);
        DrawText("PTS", 315, 550, 20, WHITE);
        DrawText("PRESS ENTER TO START", 100, 660, 30, CL_FNARANJA);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}