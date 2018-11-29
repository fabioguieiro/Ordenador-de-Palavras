#ifndef ORDENADOR_H_INCLUDED
#define ORDENADOR_H_INCLUDED
#include <time.h>
#define NUM 100
#define LEN 20
int menu(int resposta);
void bubbleS(int a);
void selectionS(int a);
int mergesort(char list[NUM][LEN], int length);
int mergesort_r(int left, int right, char list[NUM][LEN]);
int merge(char list[NUM][LEN], int left_start, int left_end, int right_start, int right_end);
void insertionS(int a);
int mergesort2(char list[NUM][LEN], int length);
int mergesort_r2(int left, int right, char list[NUM][LEN]);
int merge2(char list[NUM][LEN], int left_start, int left_end, int right_start, int right_end);

#endif // ORDENADOR_H_INCLUDED
