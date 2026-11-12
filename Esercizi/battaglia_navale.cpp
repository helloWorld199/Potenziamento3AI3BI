
#include <stdio.h>

// Definizione del campo
int m[16][16] = {0};

void barca5v(int r, int c){
    for(int i = 0; i < 5; i++){
        m[r+i][c] = 1;
    }
}

void barca3h(int r, int c){
    for(int i = 0; i < 3; i++){
        m[r][c+i] = 1;
    }
}

void bombarda(int r, int c){
    if(m[r][c]==1){
        m[r][c]='x';
    }else{
        printf("non hai colpito niente");
    }
}

void creaCampo(){
    barca5v(3,1);
    barca5v(10,10);

    barca3h(5,5);
}

void stampaCampo(){
    for(int i = 0; i < 16; i++){
        printf("%c  ", 'A' + i);
    }
    printf("\n\n");
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            if(m[i][j] == 'x')
                printf("%cca  ", m[i][j]);
            else
                printf("%d  ", m[i][j]);
        }
        printf("   .%d", i);
        printf("\n");
    }
}

int main() {
    creaCampo();
    int scelta=0;
    do{
        printf("scegli una delle seguenti opzioni \n1=attacca \n2=guarda il tuo campo \n3=abbandona la partita\n\n");
        scanf("%d", &scelta);
        switch(scelta){
            
            case 1: {
                int x;
                char y;
                printf("inserisci un numero x e una lettera y");
                scanf("%d", &x);
                scanf("%c", &y);
                bombarda(x, y);
                break;
            }

            case 2: {
                stampaCampo();
                break;
            }
            
            case 3: {
                printf("sei uscito");
                break;
            }
        }
    }while(scelta != 3);
    
    return 0;
}
