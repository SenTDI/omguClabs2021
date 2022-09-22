#include <stdio.h>
#include <stdlib.h>
#include "labs.h"

void lab1v1z1() {
    int milk = 75 * 2;
    double pech = 54.458;
    float kolbassa = 194.442 * 3;
    long double xleb = 25.5 * 5, sum = 0.0;
    sum += pech + kolbassa + xleb + milk;
    printf("%.2Lf\n", sum);
}


void lab1v1z2() {
    int d, m;
    printf("Введите день: ");
    scanf_s("%d", &d);
    printf("\nВведите месяц: ");
    scanf_s("%d", &m);
    if ((m == 3 && d >= 21) || (m == 4 && d <= 20))
        printf("Овен\n");
    if ((m == 4 && d >= 21) || (m == 5 && d <= 21))
        printf("Телец\n");
    if ((m == 5 && d >= 22) || (m == 6 && d <= 21))
        printf("Близнецы\n");
    if ((m == 6 && d >= 22) || (m == 7 && d <= 22))
        printf("Рак\n");
    if ((m == 7 && d >= 23) || (m == 8 && d <= 23))
        printf("Лев\n");
    if ((m == 8 && d >= 24) || (m == 9 && d <= 23))
        printf("Дева\n");
    if ((m == 9 && d >= 24) || (m == 10 && d <= 23))
        printf("Весы\n");
    if ((m == 10 && d >= 24) || (m == 11 && d <= 22))
        printf("Скорпион\n");
    if ((m == 11 && d >= 23) || (m == 12 && d <= 21))
        printf("Стрелец\n");
    if ((m == 12 && d >= 22) || (m == 1 && d <= 20))
        printf("Козерог\n");
    if ((m == 1 && d >= 21) || (m == 2 && d <= 18))
        printf("Водолей\n");
    if ((m == 2 && d >= 19) || (m == 3 && d <= 20))
        printf("Рыба\n");
    if ((d > 31) || (d < 1))
        printf("Вы ввели не правильно день.");
    if ((m > 12) || (m < 1))
        printf("Вы ввели не правильно месяц.");
}

void lab1v1z3() {
    unsigned int a, b;
    printf("Введите число a ");
    scanf_s("%d", &a);
    printf("Введите число b ");
    scanf_s("%d", &b);
    int mul = 0;
    for (unsigned int i = 0; i < b; i++) {
        mul += a;
    }
    printf("%d\n", mul);
}



void lab2v2() {
    int d;
    FILE* f; fopen_s(&f, "input.txt", "r+");
    FILE* fp; fopen_s(&fp, "output.txt", "r+");
    char chet[6] = "     ";
    char nonchet[11] = "          ";
    rewind(f);
    rewind(fp);
    while (fscanf_s(f, "%d", &d) != EOF) {
        if (d % 2 == 0) {
            printf("%s%d\n", chet, d);
            fprintf(fp, "%s%d\n", chet, d);
        }
        else {
            printf("%s%d\n", nonchet, d);
            fprintf(fp, "%s%d\n", nonchet, d);
        }
    }
    fclose(f);
    fclose(fp);
}

void lab3v3() {
    char d[101] = {};
    int a;
    printf("Введите число ");
    scanf_s("%d", &a);
    for (int i = 0; i <= 100; i++) {
        d[i] = rand() % 10;
        if (d[i] < a) printf("%d\n", d[i]);
    }
}
void lab4v5() {
    int N, M, MIN, MAX;

    printf("Введите сколько чисел будет по x -> ");
    scanf_s("%d", &N);
    system("cls");
    printf("\nВведите сколько чисел будет по y -> ");
    scanf_s("%d", &M);
    system("cls");
    printf("\nВведите минимальное значение для гспч -> ");
    scanf_s("%d", &MIN);
    system("cls");
    printf("\nВведите максимальное значение для гспч -> ");
    scanf_s("%d", &MAX);
    system("cls");

    int minnum = MAX + 1;
    int k = 0;
    int** matrix = (int**)malloc(sizeof(int*) * M);
    for (size_t i = 0; i < M; i++)
        matrix[i] = (int*)malloc(sizeof(int) * N);

    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++)
        {
            matrix[i][j] = ((double)rand() / RAND_MAX) * (MAX - MIN) + MIN;
            if (matrix[i][j] <= minnum) minnum = matrix[i][j];
            if (matrix[i][j] < 0) printf("%3d", matrix[i][j]);
            if (matrix[i][j] >= 0) printf("%3d", matrix[i][j]);
            if (j == N - 1) printf("\n");
        }
    }
    printf("\n\n");
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++)
        {
            if (matrix[i][j] == minnum) {
                printf(" %3d", matrix[i][j]);
                k += 1;
            }
            else printf(" %3%d", matrix[i][j]);
            if (j == N - 1) printf("\n");
        }
    }
    printf("\n\nКоличество чисел %d, %d\n", minnum, k);
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++)
        {
            if (matrix[i][j] == minnum) printf(" %d,%d", i + 1, j + 1);
            else printf(" %%d", matrix[i][j]);
            if (j == N - 1) printf("\n");
        }
    }
    printf("\n\nКоординаты минимального числа %d:\n", minnum);
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            if (matrix[i][j] == minnum) printf("%d,%d; ", i + 1, j + 1);
        }
    }
    printf("\n\n");
}