#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenador.h"
int main(int argc, char **argv){
    int resposta1=3;
    do{
        system("cls");
        printf("\t\t\t*bem vindo ao organizador de palavras*\n\n\n\n");
        printf("O que deseja fazer?\n\n");
        printf("1-Ordenar de forma crescente \n");
        printf("2-Ordenar de forma decrescente\n");
        printf("0- SAIR                 ");
        scanf("%d",&resposta1);
        printf("\n\n\n");
        if(resposta1 == 0) break;
        if(resposta1 <=2) resposta1=menu(resposta1);
    }while(resposta1>2);
    return 0;
}
