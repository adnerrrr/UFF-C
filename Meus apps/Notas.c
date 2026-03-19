#include <stdlib.h>
#include <stdio.h>

void espera(){
    printf("\n[ENTER TO CONTINUE]");
    getchar();
    getchar();
    system("cls");
}

void adiciona(){
    float grade;
    int hora;
    char nome[50];
    FILE *nota = fopen("notas.txt", "a");
    printf("Digite o NOME: ");
    scanf(" %[^\n]", nome);
    printf("Digite a NOTA: ");
    scanf(" %f", &grade);
    printf("Digite as HORAS: ");
    scanf(" %d", &hora);
    fprintf(nota, "%f | %d h %s\n", grade, hora, nome);
    fclose(nota);
    printf("\nMateria Adicionada.\n");
    espera();
}

void cr(){
    FILE *nota = fopen("notas.txt", "r");
    float grade, hora, notas, horas, cr;
    char nome[50];
    notas = 0;
    horas = 0;
    while (fscanf(nota, "%f | %f h %[^\n]", &grade, &hora, nome) == 3){
        notas += (grade * hora);
        horas += hora;
    }
    cr = notas / horas;
    printf("\nSeu CR e: %.1f\n", cr);
    fclose(nota);
    espera();
}

void materias(){
    printf("\n");
    FILE *nota = fopen("notas.txt", "r");
    float grade;
    char nome[50];
    int hora;
    int mat = 1;
    while (fscanf(nota, "%f | %d h %[^\n]", &grade, &hora, nome) == 3){
        printf("[%d] %s -> %.1f\n", mat, nome, grade);
        mat++;
    }
    fclose(nota);
}

void deleta(){
    FILE *nota = fopen("notas.txt", "r");
    int linha;
    int atual = 1;
    float grade;
    char nome[50];
    int hora;
    materias();
    printf("Qual materia deseja deletar?\n-> ");
    scanf(" %d", &linha);
    FILE *temp = fopen("temp.txt", "w");
    while (fscanf(nota, "%f | %d h %[^\n]", &grade, &hora, nome) == 3){
        if (atual != linha){
            fprintf(temp, "%f | %d h %s\n", grade, hora, nome);
        }
        atual++;
    }
    fclose(nota);
    fclose(temp);
    remove("notas.txt");
    rename("temp.txt", "notas.txt");
    printf("\nMateria Deletada.\n");
    espera();
}

void edit(){
    FILE *nota = fopen("notas.txt", "r");
    int linha;
    int atual = 1;
    float grade;
    char nome[50];
    int hora;
    materias();
    printf("Qual materia deseja editar?\n-> ");
    scanf(" %d", &linha);
    FILE *temp = fopen("temp.txt", "w");
    while (fscanf(nota, "%f | %d h %[^\n]", &grade, &hora, nome) == 3){
        if (atual != linha){
            fprintf(temp, "%f | %d h %s\n", grade, hora, nome);
        }
        else{
            printf("Digite o NOME: ");
            scanf(" %[^\n]", nome);
            printf("Digite a NOTA: ");
            scanf(" %f", &grade);
            printf("Digite as HORAS: ");
            scanf(" %d", &hora);
            fprintf(temp, "%f | %d h %s\n", grade, hora, nome);
        }
        atual++;
    }
    fclose(nota);
    fclose(temp);
    remove("notas.txt");
    rename("temp.txt", "notas.txt");
    printf("\nMateria Editada.\n");
    espera();
}

/* int main(){
    int op = 0;
    while (op != 6){
        printf("\nQual atividade deseja realizar?\n");
        printf("[1] Adicionar materia\n");
        printf("[2] Deletar materia\n");
        printf("[3] Editar materia\n");
        printf("[4] Ver CR\n");
        printf("[5] Ver notas\n");
        printf("[6] Sair\n-> ");
        scanf(" %d", &op);
        switch (op)
        {
        case 1:
            adiciona();
            break;
        case 2:
            deleta();
            break;
        case 3:
            edit();
            break;
        case 4:
            cr();
            break;
        case 5:
            materias();
            espera();
            break;
        case 6:
            break;
        default:
            printf("\nNao e uma opcao.\n");
        }
    }
}
*/