//Juego Pacman proyecto programacion 
//Luis Angel Maldonado Valenzuela
//Juan Antonio Torres Montoya 

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define REN 22 //eje y
#define COL 35 //eje x

struct Pacman {
    int x;
    int y;
};

struct Fantasma{
    int x;
    int y;
};

struct Fantasma fantasmas[4];

void menu();
void cuerpodeljuego();
int fantasmas();
int pacman1();
void dibujarmapa();

char mapa  [REN][COL] = {
    "##################################",
    "#.............######............ #",
    "#.#####.#####.######.#####.#####.#",
    "# ##### ##### ###### ##### ##### #",
    "#................................#",
    "# ###### ##                      #",
    "# ###### ##                      #",
    "#        ##                      #",
    "######## ##                      #",
    "#        ##                      #",
    "#        ##                      #",
    "#                                #",
    "#                                #",
    "#                                #",
    "#                                #",
    "#                                #",
    "#                                #",
    "#                                #",
    "#                                #",
    "#                                #",
    "#                                #",
    "##################################",
};

int main(){
    void menu();
}

void menu(){
    int opcion;
    printf("\n");
    printf("     Bienvenido a Pacman    \n");
    printf("\n");
    printf("        1. Jugar            \n");
    printf("        2. Salir            \n");
    printf("\n");
    printf("\n");
    printf("     Ingrese su opcion:     \n");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            cuerpodeljuego();
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("Opcion no valida\n");
            break;
    }
}


void cuerpodeljuego(){
    int juego = 1,x = 0, y = 0;
    int highscore = 0;
    char pared = '#';
    struct Pacman pacman;
    if (_kbhit()) {
            char tecla = _getch();

            if (tecla == 'w' || tecla == 'W') y--;
            if (tecla == 's' || tecla == 'S') y++;
            if (tecla == 'a' || tecla == 'A') x--;
            if (tecla == 'd' || tecla == 'D') x++;

            // Evitar que pacman se mueva por una pared
            if (mapa[pacman.y][pacman.x] != pared) {
                pacman.x = x;
                pacman.y = y;
            }
        }

    while(juego){
        system("cls");
        
        dibujarmapa();
        if(pacman1() == 0){
            juego = 0;
            printf("\n");
            printf("=========================\n");
            printf("       Game Over         \n");
            printf("=========================\n");
            printf("high scorre: %d\n",highscore);
        }
    }
}

void dibujarmapa(){
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}

int pacman1(){

}

int fantasmas(){

}