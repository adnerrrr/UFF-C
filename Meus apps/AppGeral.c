#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gradeHoraria.h"
#include "Notas.h"

int main(){
    int op = 0;
    while (op != 8){
        printf("O que deseja fazer?\n");
        printf("[1] Editar a Grade Horaria atual\n");
        printf("[2] Esvaziar a Grade Horaria atual\n");
        printf("[3] Adicionar materia\n");
        printf("[4] Deletar materia\n");
        printf("[5] Editar materia\n");
        printf("[6] Ver CR\n");
        printf("[7] Ver notas\n");
        printf("[8] Sair\n");
        mostrar();
        printf("-> ");
        scanf(" %d", &op);
        switch (op)
        {
        case 1:
            editar();
            break;
        case 2:
            preenche();
            break;
        case 3:
            adiciona();
            break;
        case 4:
            deleta();
            break;
        case 5:
            edit();
            break;
        case 6:
            cr();
            break;
        case 7:
            materias();
            espera();
            break;
        case 8:
            break;
        default:
            printf("\nIsso nao e uma opcao seu boboca\n");
            espera();
            break;
        }
    }   
}