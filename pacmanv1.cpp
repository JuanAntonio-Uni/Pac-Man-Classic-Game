//Juego Pacman proyecto programacion 
//Luis Angel Maldonado Valenzuela
//Juan Antonio Torres Montoya 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<math.h>

#define REN 22 //eje y
#define COL 36 //eje x

struct Pacman {
    int x;
    int y;
};

struct Fantasma{
    int x;
    int y;
};

struct Fantasma fantasmas[3];

void menu();
void cuerpodeljuego();
int enemigos(struct Fantasma fantasmas[3], struct Pacman *pacman);
void dibujarmapa();
int tabladescore(int score);


/*mapa en el que se movera pacman*/
char mapa  [REN][COL] = {
    "###################################",
    "#..............######.............#",
    "#0######.#####.######.#####.#####0#",
    "#.######.#####.######.#####.#####.#",
    "#.................................#",
    "#.######.## ###########.##.######.#",
    "#.######.##.###########.##.######.#",
    "#........##.....###.....##........#",
    "########.######.###.######.########",
    "######## ##.............##.########",
    "#........##.###########.##........#",
    "#.######....###########....######.#",
    "#.######.##.....###.....##.######.#",
    "#.######.###### ### ######.######.#",
    "#.######...................######.#",
    "#.###### ################# ######.#",
    "#...............###...............#",
    "########.##.###.### ###.## ########",
    "#....... ##.....###.....##........#",
    "#.#############.###.#############.#",
    "#.................................#",
    "###################################",
};

int main(){
    menu();
}

//Menu de opciones, jugar o salir del juego
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
    int juego = 1, j = 1;
    struct Pacman *pacman = (struct Pacman*)malloc(sizeof(struct Pacman));
    struct Fantasma fantasmas[3];
    pacman->x = 18;
    pacman->y = 14;
    int score = 0;
    char personaje = 'C';
    char pared = '#';
    char punto = '.';
    char pastillapoder = '0';
    while(juego!=0){
        system("cls");
        dibujarmapa();
        // Evitar que pacman se mueva por una pared
        if (pacman->y--||pacman->x++||pacman->x--||pacman->y++ != pared){
            if (_kbhit()) {
            char tecla = _getch();

            if (tecla == 'w' || tecla == 'W') pacman->y--;
            if (tecla == 's' || tecla == 'S') pacman->y++;
            if (tecla == 'a' || tecla == 'A') pacman->x--;
            if (tecla == 'd' || tecla == 'D') pacman->x++;
            }
        }
        personaje = mapa[pacman->y][pacman->x];
            if(personaje == punto){
                score += 10;
                mapa[pacman->y][pacman->x] = ' ';
            }
            if(personaje == '0'){
                score += 50;
                mapa[pacman->y][pacman->x] = ' ';
            }
            if(pacman->x && pacman->y == fantasmas[0].x && fantasmas[0].y){
                juego = 0;
            }
            if(juego == 0){
                printf("\n");
                printf("=========================\n");
                printf("       Game Over         \n");
                printf("=========================\n");
                printf("high scorre: %d\n",score);
            }//i
        }//while
        tabladescore(score);
    }

void dibujarmapa(){
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}

int enemigos(struct Fantasma fantasmas[3], struct Pacman){
    
}

int tabladescore(int score){
   
}