#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ordenador.h"
int menu(int resposta){
    int resposta2,i;
    char s[100][20];
    FILE *file;
    file = fopen("L100.txt", "r");
    printf("Qual metodo gostaria de utilizar?\n\n");
    printf("1-Bubble\n");
    printf("2-Insertion\n");
    printf("3-Selection\n");
    printf("4-Merge\n");
    printf("pressione 0 para voltar ao menu anterior   ");
    scanf("%d",&resposta2);
    switch (resposta2){
        case 1:
            bubbleS(resposta);
            break;
        case 2:
            insertionS(resposta);
            break;
        case 3:
            selectionS(resposta);
            break;
        case 4:
            for (i=0;i<101;i++){
                fscanf(file, "%s", &s[i]);
            }
            printf("***Lista Original   ***\n\n");
            for (i=0;i<100;i++){
                printf("%s\n",s[i]);
            }
            if (resposta == 1){
            mergesort(s,100);
            printf("\n\n\n\n***PALAVRAS ORDENADAS***\n\n");
            for(i=0; i<100; i++)
            {
                printf("%s\n",s[i]);
            }
            }
            if(resposta==2) {
                mergesort2(s,100);
                printf("\n\n\n\n***PALAVRAS ORDENADAS***\n\n");
                for(i=100; i>=0; i--){
                printf("%s\n",s[i]);
            }
            }
            break;
        case 0:
            main();
            break;
        default:
            printf("\n\nEntrada invalida!!\n\n\n\n");
            menu(resposta);
            break;
    }
    return 0;
}

void bubbleS(int a){
    int i,j,tam;
    char aux[20], s[1000][20];
    FILE *file;
    file = fopen("L1000.txt", "r");
    for (i=0;i<1000;i++){
        fscanf(file, "%s", &s[i]);
    }
    printf("***Lista Original***\n\n");
    for (i=0;i<1000;i++){
        printf("%s\n",s[i]);
    }
    if(a==1){
        for (i=1000; i>=1;i--){
            for (j=0;j<i;j++){
                if(strcmp(s[j],s[j+1]) > 0){
                    strcpy(aux,s[j]);
                    strcpy(s[j],s[j+1]);
                    strcpy(s[j+1],aux);
                }
            }
        }
        printf("\n\n\n\n***PALAVRAS ORDENADAS***\n\n");
        for (i=0;i<1000;i++){
            printf("%s\n",s[i]);
        }
        exit(0);
    }
    for (i=300; i>=1;i--){
        for (j=0;j<i;j++){
            if(strcmp(s[j],s[j+1]) < 0){
                strcpy(aux,s[j]);
                strcpy(s[j],s[j+1]);
                strcpy(s[j+1],aux);
            }
        }
    }
    printf("\n\n\n\n***PALAVRAS ORDENADAS***\n\n");
    for (i=0;i<300;i++){
        printf("%s\n",s[i]);
    }
}

void selectionS(int a ){
    int i,j,min;
    char s[100][20],aux[20];
    FILE *file;
    file=fopen("L100.txt", "r");
    for (i=0;i<100;i++){
        fscanf(file, "%s", &s[i]);
    }
    printf("***Lista Original***\n\n");
    for (i=0;i<100;i++){
        printf("%s\n",s[i]);
    }
    if(a==1){
        for (i = 0; i < 99; i++) {
            min = i;
            for (j = (i+1); j < 100; j++) {
                if(strcmp(s[j], s[min])<0){
                    min = j;
                }
                if (i != min) {
                    strcpy (aux , s[i]);
                    strcpy (s[i] , s[min]);
                    strcpy (s[min] , aux);
                }
            }
        }
        printf("\n\n\n\n***PALAVRAS  ORDENADAS***\n\n");
        for (i=0;i<100;i++){
            printf("%s\n",s[i]);
        }
        exit(0);
    }
    for (i = 0; i < 99; i++) {
            min = i;
            for (j = (i+1); j < 100; j++) {
                if(strcmp(s[j], s[min])>0){
                    min = j;
                }
                if (i != min) {
                    strcpy (aux , s[i]);
                    strcpy (s[i] , s[min]);
                    strcpy (s[min] , aux);
                }
            }
        }
        printf("\n\n\n\n***PALAVRAS ORDENADAS***\n\n");
        for (i=0;i<100;i++){
            printf("%s\n",s[i]);
        }
}

void insertionS(int a){
    int i,j;
    char aux[20], s[100][20];
    FILE *file;
    file=fopen("L100.txt", "r");
    for (i=0;i<100;i++){
        fscanf(file, "%s", &s[i]);
    }
    printf("***Lista Original***\n\n");
    for (i=0;i<101;i++){
        printf("%s\n",s[i]);
    }
    if (a==1){
        for (i=1;i<100;i++){
        strcpy(aux,s[i]);
        j=i-1;
        while ((j >= 0) && (strcmp(aux,s[j])<0)){
			strcpy(s[j + 1],s[j]);
			j=j-1;
		}
       strcpy(s[j + 1],aux);
    }
    printf("\n\n\n\n***PALAVRAS ORDENADAS***\n\n");
    for (i=0;i<100;i++){
        printf("%s\n",s[i]);
    }
    exit (0);
    }
    for (i=1;i<100;i++){
        strcpy(aux,s[i]);
        j=i-1;
        while ((j >= 0) && (strcmp(aux,s[j])>0)){
			strcpy(s[j + 1],s[j]);
			j=j-1;
		}
       strcpy(s[j + 1],aux);
    }
    printf("\n\n\n\n***PALAVRAS ORDENADAS***\n\n");
    for (i=0;i<100;i++){
        printf("%s\n",s[i]);
    }
}


int mergesort(char list[NUM][LEN], int length) {
    mergesort_r(0, length, list);
    return 0;
}

int mergesort2(char list[NUM][LEN], int length) {
    mergesort_r2(0, length, list);
    return 0;
}

int mergesort_r(int left, int right, char list[NUM][LEN]){
    if (right - left <= 1)
    {
        return 0;
    }


    int left_start  = left;
    int left_end    = (left+right)/2;
    int right_start = left_end;
    int right_end   = right;


    mergesort_r( left_start, left_end, list);

    mergesort_r( right_start, right_end, list);


    merge(list, left_start, left_end, right_start, right_end);
}

int mergesort_r2(int left, int right, char list[NUM][LEN])
{
    if (right - left <= 1)
    {
        return 0;
    }


    int left_start  = left;
    int left_end    = (left+right)/2;
    int right_start = left_end;
    int right_end   = right;


    mergesort_r2( left_start,left_end, list);

    mergesort_r2( right_start,right_end, list);


    merge2(list, left_start, left_end, right_start, right_end);
}

int merge(char list[NUM][LEN], int left_start, int left_end, int right_start, int      right_end)
{
    int left_length = left_end - left_start;
    int right_length = right_end - right_start;


    char left_half[left_length][LEN];
    char right_half[right_length][LEN];

    int r = 0;
    int l = 0;
    int i = 0;


    for (i = left_start; i < left_end; i++, l++)
    {
        strcpy(left_half[l], list[i]);
    }


    for (i = right_start; i < right_end; i++, r++)
    {
        strcpy(right_half[r], list[i]);
    }


    for ( i = left_start, r = 0, l = 0; l < left_length && r < right_length; i++)
    {
        if ( strcmp(left_half[l], right_half[r])<0 )
        { strcpy(list[i], left_half[l++]); }
        else { strcpy(list[i], right_half[r++]); }
    }


    for ( ; l < left_length; i++, l++) { strcpy(list[i], left_half[l]); }
    for ( ; r < right_length; i++, r++) { strcpy(list[i], right_half[r]); }

    return 0;
}

int merge2(char list[NUM][LEN], int left_start, int left_end, int right_start, int      right_end)
{
    int left_length = left_end - left_start;
    int right_length = right_end - right_start;


    char left_half[left_length][LEN];
    char right_half[right_length][LEN];

    int r = 0;
    int l = 0;
    int i = 0;


    for (i = left_start; i < left_end; i++, l++)
    {
        strcpy(left_half[l], list[i]);
    }


    for (i = right_start; i < right_end; i++, r++)
    {
        strcpy(right_half[r], list[i]);
    }


    for ( i = left_start, r = 0, l = 0; l < left_length && r < right_length; i++)
    {
        if ( strcmp(left_half[l], right_half[r])<0 )
        { strcpy(list[i], left_half[l++]); }
        else { strcpy(list[i], right_half[r++]); }
    }


    for ( ; l < left_length; i++, l++) { strcpy(list[i], left_half[l]); }
    for ( ; r <right_length; i++, r++) { strcpy(list[i], right_half[r]); }

    return 0;
}


