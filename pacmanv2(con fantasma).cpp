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

void menu();
void cuerpodeljuego();
void enemigo(struct Fantasma *fantasma, struct Pacman *pacman);
void dibujarmapa(struct Pacman *pacman, struct Fantasma *fantasma);
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
    "#0..............###..............0#",
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
    printf("==============================\n");
    printf("      Pacman The Game         \n");
    printf("==============================\n");
    printf("\n");
    printf("       [ 1. Jugar   ]         \n");
    printf("       [ 2. Salir   ]         \n");
    printf("	   [3. Puntajes ]		  \n");
    printf("\n");
    printf("==============================\n");
    printf("\n");
    printf("\n");
    printf("==============================\n");
    printf("     Ingrese su opcion:     \n");
    printf("==============================\n");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            cuerpodeljuego(); break;
        case 2:
            exit(0); break;
        default:
            printf("Opcion no valida\n"); break;
    }
}


void cuerpodeljuego(){
    int juego = 1, j = 1;
    
    //inicializacion estructuras para los personajes del juego(blinky y pacman)
    struct Pacman *pacman = (struct Pacman*)malloc(sizeof(struct Pacman));
    struct Fantasma *fantasma = (struct Fantasma*)malloc(sizeof(struct Fantasma));
    
    //posicion pocman
    pacman->x = 1;
    pacman->y = 1;
    int score = 0;
    
    //posicion blinky
    fantasma->x = 33;
	fantasma->y = 20;
	 
    char pared = '#';
    char punto = '.';
    char pastillapoder = '0';
    
    while(juego!=0){
        system("cls");
        dibujarmapa(pacman,fantasma);
        enemigo(fantasma,pacman);
        
        //Controles del personaje pacman
        if (_kbhit()) {
            char tecla = _getch();
			int sigX = pacman->x;
			int sigY = pacman->y;
            if (tecla == 'w' || tecla == 'W') sigY--;
            if (tecla == 's' || tecla == 'S') sigY++;
            if (tecla == 'a' || tecla == 'A') sigX--;
            if (tecla == 'd' || tecla == 'D') sigX++;
            
            // Evitar que pacman se mueva por una pared y se haga trampas
            if (mapa[sigY][sigX] != pared){
        	pacman->y = sigY;
        	pacman->x = sigX;
		
	        }
        }
        
        char posActual = mapa[pacman->y][pacman->x];
        
        if(posActual == punto){
            score += 10;
            mapa[pacman->y][pacman->x] = ' ';
        }
        if(posActual == pastillapoder){
            score += 50;
            mapa[pacman->y][pacman->x] = ' ';
        }
        
        if(pacman->x == fantasma->x && pacman->y == fantasma->y){
            juego = 0;
        }
		
        _sleep(200);
    }//while
    	system("cls");
    	printf("\n");
    	printf("=========================\n");
    	printf("       Game Over         \n");
    	printf("           :(            \n");
    	printf("=========================\n");
    	printf("      Your score: %d\n",score);
    
    
    free(pacman);
    tabladescore(score);
}



void dibujarmapa(struct Pacman *pacman, struct Fantasma *fantasma){
    for(int i = 0; i < REN; i++) {
        for(int j = 0; j < COL - 1; j++) {
            if (j == pacman->x && i == pacman->y) {
                printf("C"); // Dibuja a Pacman 
			}else if(j == fantasma->x && i == fantasma->y){
            	printf("A");//Dibuja a Blinky(o un fantasma xd)
            }else{
                printf("%c", mapa[i][j]);
			}
            
        }
        printf("\n");
    }
}  

void enemigo(struct Fantasma *fantasma, struct Pacman *pacman){
	
	int distancia;
	float mejdist = 500;
	int dire = -1;
	int nextY, nextX;
	
	int moveY[] = {-1,0,1,0};
	int moveX[] = {0,1,0,-1};
	
	for(int i=0; i<4; i++){
		nextY = fantasma->y + moveY[i];
		nextX = fantasma->x + moveX[i];
		
		if (mapa[nextY][nextX] != '#'){
			distancia = sqrt(pow((pacman->x - nextX), 2) + pow((pacman->y - nextY), 2));
			
			if (distancia < mejdist){
				mejdist = distancia;
				dire = i;
			}
		}
	}
	
	fantasma->x += moveX[dire];
	fantasma->y += moveY[dire];
}

int tabladescore(int score){
	FILE *arch;
	FILE *temp;
	arch  = fopen("JGscore.txt","a");
	
	if(arch == NULL){
		printf("¡ERROR DE ARCHIVO!");
	}
	
	fprintf(arch,"Pacman Score: \n");
	fprintf(arch,"%d \n",score);
	  
	fclose(arch);
		
}
