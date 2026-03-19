#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct opcao{
    int dia;
    int horario;
    char nome[50];
} opcao;

void espere(){
    printf("\n[ENTER TO CONTINUE]");
    getchar();
    getchar();
    system("cls");
}

void salvar(int dia, int horario, char nome[50]){
    FILE* grade = fopen("grade.txt", "rb+");
    opcao materia;
    materia.dia = dia;
    materia.horario = horario;
    strcpy(materia.nome, nome); 
    // --- A MÁGICA DO FSEEK ---
    // Calcula a posição exata: (Dia anterior * 7 aulas) + (Horario anterior)
    // Exemplo: Dia 1, Horario 1 -> (0*7) + 0 = Posição 0
    int posicao = ((dia - 1) * 7) + (horario - 1);

    // Pula o cursor direto para o byte correto
    fseek(grade, posicao * sizeof(opcao), SEEK_SET);

    // Grava APENAS essa materia por cima da antiga
    fwrite(&materia, sizeof(opcao), 1, grade);
    fclose(grade);
}

void editar(){
    int dia = -1, horario = -1, rep;
    char nome[50];

    printf("Quantas vezes a materia se repete? \n-> ");
    scanf(" %d", &rep);
    
    printf("Digite o nome: ");
    scanf(" %[^\n]", nome);

    while (horario != 0)
    {
        printf("[1] 7-9 | [2] 9-11 | [3] 11-13 | [4] 14-16 | [5] 16-18 | [6] 18-20 | [7] 20-22\n");
        printf("Selecione o horario (1-7): ");
        scanf(" %d", &horario);
        if (horario > 0 && horario < 8) break;
        else printf("Esse horario nao existe seu boboca\n");
    }

    while (dia != 0)
    {   
        for (int i = 0; i < rep; i++){
            printf("[1] SEG | [2] TER | [3] QUA | [4] QUI | [5] SEX\n");
            printf("Selecione o dia: ");
            scanf(" %d", &dia);
            salvar(dia, horario, nome);
        }
        if (dia > 0 && dia < 6) break;
        else printf("Esse dia nao existe seu boboca\n");        
    }  
    espere();
}

void mostrar() {
    FILE* grade = fopen("grade.txt", "rb");
    opcao agenda[7][5] = {0};
    opcao temp;
    while (fread(&temp, sizeof(opcao), 1, grade) == 1) {
        // Verificação de segurança para não travar se o arquivo tiver lixo
        if (temp.dia >= 1 && temp.dia <= 5 && temp.horario >= 1 && temp.horario <= 7) {
            // Ajustamos -1 porque arrays em C começam no zero
            agenda[temp.horario - 1][temp.dia - 1] = temp;
        }
    }
    fclose(grade);
    char *horas[] = {" 7 -  9", " 9 - 11", "11 - 13", "14 - 16", "16 - 18", "18 - 20", "20 - 22"};
    printf("\nHORARIO |       SEG       |       TER       |       QUA       |       QUI       |       SEX       |\n");
    for (int h = 0; h < 7; h++) {
        printf("%s |", horas[h]);
        for (int d = 0; d < 5; d++) {
            // "%-8.8s" significa: alinhe a esquerda, use 8 espaços, corte se for maior que 8
            printf(" %-15.15s |", agenda[h][d].nome);
        }
        printf("\n");
    }
    printf("\n");
}

void preenche(){
    FILE * grade = fopen("grade.txt", "wb");
    opcao materia;
    char nome[50] = " - ";
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 7; j++){
            materia.dia = i;
            materia.horario = j;
            strcpy(materia.nome, nome);
            fwrite(&materia, sizeof(opcao), 1, grade);
        }
    }
    fclose(grade);
    espere();
}



/* int main(){
    int op;
    while (op != 3){
        mostrar();
        printf("O que deseja fazer?\n");
        printf("[1] Editar a Grade Horaria atual\n");
        printf("[2] Esvaziar a Grade Horaria atual\n");
        printf("[3] Sair\n-> ");
        scanf(" %d", &op);
        switch (op){
            case 1:
                editar();
                break;
            case 2:
                preenche();
                break;
            case 3:
                break;
            default:
                printf("\nIsso nao e uma opcao seu boboca\n");
                espere();
        }
    }
    mostrar();
}
*/
