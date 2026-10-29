// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>

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



int main() {
    barca5v(3,1);
    barca5v(10,10);

    barca3h(5,5);
    
    printf("\n");
    printf("\n");
    
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 16; j++){
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
