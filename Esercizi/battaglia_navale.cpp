#include <stdio.h>

std::map<std::string, int> letter_to_number = {
    {"A", 0},
    {"B", 1},
    {"C", 2},
    {"D", 3},
    {"E", 4},
    {"F", 5},
    {"G", 6},
    {"H", 7},
    {"I", 8},
    {"J", 9},
    {"K", 10},
    {"L", 11},
    {"M", 12},
    {"N", 13},
    {"O", 14},
    {"P", 15}
};

// Definizione del campo
int m[16][16] = {0};

void barca5v(int r, int c, bool up){
    for(int i = 0; i < 5; i++){
        if (up)
            if(r <= 3){
                return;
            }
            m[r-i][c] = 1; 
        else
            m[r+i][c] = 1; 
    }
}

void barca3h(int r, int c, bool up){
    for(int i = 0; i < 3; i++){
        if(up)
            m[r][c+i] = 1; 
        else
            if(c <=1){
                return;
            }
            m[r][c-i] = 1;
    }
}

void bombarda(int r, int c){
    if(m[r][c]==1){
        m[r][c]='x';
    }else{
        printf("non ne azzecchi una SFIGATO!!!");
    }
}

void creaCampo(){
    barca5v(3,1, false);
    barca5v(10,10, false);

    barca3h(5,5, false);
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
        printf("scegli una delle seguenti opzioni \n1) attacca l'avversario! \n2) ricontrolla meglio il tuo campo \n3) se sei un codardo abbandona la missione\n\n");
        scanf("%d", &scelta);
        switch(scelta){
            
            case 1: {
                char* ris[4];
                int x;
                char c;

                printf("Inserisci la posizione da colpire usando\n");
                printf("questo formato: LETTERA-NUMERO\n");
                printf("Esempio: A12\n");
                scanf("%s", ris);
                
                c = ris[0];
                //TODO: estrapolare numero intero da posizioni
                x = snprintf(ris);
                //0 e 1. attenzione: il numero può essere di una cifra sola

                bombarda(x, y);
                break;
            }

            case 2: {
                stampaCampo();
                break;
            }
            
            case 3: {
                printf("hai abbandonato la missione, torna a casa scemo cacca pupu");
                break;
            }
        }
    }while(scelta != 3);
    
    return 0;
}
















/*PROF LE VOGLIAMO BENE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
io voglio bene ad Amarandaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
PATRIZIO MORELATO
IO AMO IL BREAKFAST CLUB
TAPPATI LE ORECCHIE SE NON VUOI SENTIRCI NOI SIAMO I PIU BELLI NOI SIAMO I PIU FIGHI 
ENTRIAMO NEL BACK MA DELLA SCUOLA NOI SIAMO LE STAR DEL PIANO DI SOPRA
HO SCRITTO UN LIBRO MI DANNO 10 PERCHE SONO IL PIU FIGO*/


