#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hanoi(int n) {
    if(n == 1){
        return 1;
    }
    else{
        return 1 + 2 * hanoi(n - 1);
    }
}

char bin[40];
char* decimal_to_binary(int num){
    if(num != 0){
        sprintf(bin, "%s%d", decimal_to_binary(num / 2), num%2);
    }
    return bin;
}

int N = 4;
int** matriz_espiral(){
    int matriz[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= N; j++){
            printf("Digite o digito %d, %d", j, i);
            scanf("%d", &matriz[j][i]);
        }
    }
    return matriz;
}

int main(void) {
    matriz_espiral();
}