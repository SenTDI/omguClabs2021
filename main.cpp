#include "labs.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct AEROFLOT {
    char DESTINATION[260];
    int FLIGHT_NUMBER;
    char PILOT_NAME[260];
    int NUMBER_OF_PASSENGERS;
};

void lab0() { printf("%s", "������ ���!\n"); }

void lab5v2() {
    FILE* f; fopen_s(&f, "input.txt", "r+");
    char string[1000];
    char alphabet[] = { '�', '�', '�', '�', '�', '�', '�', '�'
                      , '�', '�', '�', '�', '�', '�', '�', '�'
       , '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'
       , '�', '�', '�', '�', '�', '�' };
    int charnum = 0, pos = 0, test = 0;
    rewind(f);
    fscanf_s(f, ".", &string);
    fgets(string, 1000, f); // printf("%c %d", string[i], string[i]);
    for (int i = 0; i < sizeof(string); i++) {
        if (string[i] == 46) test = 1;
        if (string[i] != alphabet[i]) { 
            pos = i + 1; 
            charnum = string[i]; break; }
    }
    if (test) printf("���� ���� ����� ���� �� ����������� �������");
    else printf("������� ������� ����������� ���������� �������: %d ��� ����� %c\n", pos, charnum);
    fclose(f);
}

void lab6v2() {
    GenericList<AEROFLOT> list;
    char Pilot_name[260], Destination[260];
    int Flight_num, Num_of_passagers, countel;
    printf("������� ���������� ������� -> ");
    scanf_s("%d", &countel);
    for (int i = 0; i < countel; i++) {
        printf_s("������� ��� ������ -> ");
        scanf_s("%s", Pilot_name, 260);
        printf_s("������� ��������������� -> ");
        scanf_s("%s", Destination, 260);    // -> ����� �������� � ���������� 
        printf_s("������� ����� ������ -> ");//   ���������� � �������� ������
        scanf_s("%d", &Flight_num);
        printf_s("������� ���������� ���������� -> ");
        scanf_s("%d", &Num_of_passagers);
        AEROFLOT devil = { *Destination, Flight_num, *Pilot_name, Num_of_passagers};
        list.Append(devil);
    }
    for (int i = 0; i < countel; i++) {
        printf("%s %s %d %d",
            list.Get(i)->PILOT_NAME,
            list.Get(i)->DESTINATION,
            list.Get(i)->FLIGHT_NUMBER,
            list.Get(i)->NUMBER_OF_PASSENGERS
        );
    }
}

// data1 = airport
AEROFLOT* printsort(AEROFLOT* data1, AEROFLOT* data2) {
    int i = 0, j = 0, imin = 0;
    int max = sizeof(int*);
    int min = max - 1;
    while (data1[i].FLIGHT_NUMBER != NULL) {
        if (data1[i].FLIGHT_NUMBER <= min) {
            *data2[j].DESTINATION = *data1[i].DESTINATION;
            data2[j].FLIGHT_NUMBER = data1[i].FLIGHT_NUMBER;
            *data2[j].PILOT_NAME = *data1[i].PILOT_NAME;
            data2[j].NUMBER_OF_PASSENGERS = data1[i].NUMBER_OF_PASSENGERS;
            min = data1[i].FLIGHT_NUMBER;
            data1[i].FLIGHT_NUMBER = max;
            imin = i;
            j++;
        }
        i++;
    }
    printf("���������������: %s\n��� ������: %s\n����� �����: %d\n���-�� ����������: %d\n\n",
        data1[imin].DESTINATION,
        data1[imin].PILOT_NAME,
        data1[imin].FLIGHT_NUMBER,
        data1[imin].NUMBER_OF_PASSENGERS
    );
    if (data1[0].FLIGHT_NUMBER != NULL) return data2 = printsort(data1, data2);
    else return data2;
}


void nor() {
    int countel;
    const int fapfap = 430;
    AEROFLOT airport[fapfap];
    AEROFLOT loqie[fapfap];
    for (;;) {
        int inputt;
        printf(
            "[0] �����.\n"
            "[1] ������ ������������� � ������.\n"
            "[2] ����� �� ������ ����������.\n"
            "[3] ����� � ����������� �� ���������� ����������.\n"
            "[4] ����� �� ����� ������.\n"
            "\t������� ����� �� ���� -> "
        );
        scanf_s("%d", &inputt);
        if (inputt == 0) break;
        if (inputt == 1) {
            printf("\n������� ���������� ������� -> ");
            scanf_s("%d", &countel);
            for (int i = 0; i < countel; i++) {
                printf("������� ��� ������ -> ");
                scanf_s("%s", airport[i].PILOT_NAME, 50);
                printf("������� ��������������� -> ");
                scanf_s("%s", airport[i].DESTINATION, 50);
                printf("������� ����� ������ -> ");
                scanf_s("%d", &airport[i].FLIGHT_NUMBER);
                printf("������� ���������� ���������� -> ");
                scanf_s("%d", &airport[i].NUMBER_OF_PASSENGERS);
                printf("%s\n%s\n%d\n%d\n\n",
                    airport[i].PILOT_NAME,
                    airport[i].DESTINATION,
                    airport[i].FLIGHT_NUMBER,
                    airport[i].NUMBER_OF_PASSENGERS
                );
            }
        }
        if (inputt == 2) {
            char destseach[260];
            printf("\n������� ����� ���������� -> ");
            scanf_s("%s", destseach, 260);
            for (int i = 0; i < countel; i++) {
                if (*airport[i].DESTINATION == *destseach) {
                    printf("���������������: %s\n��� ������: %s\n����� �����: %d\n���-�� ����������: %d\n\n",
                        airport[i].DESTINATION,
                        airport[i].PILOT_NAME,
                        airport[i].FLIGHT_NUMBER,
                        airport[i].NUMBER_OF_PASSENGERS
                    );
                }
            }
        }
        if (inputt == 3) {
            *loqie = *printsort(airport, loqie);
        }
        if (inputt == 4) {
            char pilotseach[260];
            printf("\n������� ��� ������ -> ");
            scanf_s("%s", pilotseach, 260);
            for (int i = 0; i < countel; i++) {
                if (*airport[i].PILOT_NAME == *pilotseach) {
                    printf("��� ������: %s\n���������������: %s\n����� �����: %d\n���-�� ����������: %d\n\n",
                        airport[i].PILOT_NAME,
                        airport[i].DESTINATION,
                        airport[i].FLIGHT_NUMBER,
                        airport[i].NUMBER_OF_PASSENGERS
                    );
                }
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    for (;;) {
        printf("\n\n[0] �����\n"
            "[1] 0. ������ ���!\n"
            "[2] 1.1.1 ���� ������.\n"
            "[3] 1.2.1 ��������� ���������.\n"
            "[4] 1.3.1 �����.\n"
            "[5] 2.1 ������ � �������.\n"
            "[6] 3.3 ���� ������.\n"
            "[7] 4.1 �������.\n"
            "[8] 5.1 ������\n"
            "[9] 6.1 ���������\n"
            "������� ����� �� ���� -> "
        );
        int a;
        scanf_s("%d", &a);
        printf("\n");
        switch (a) {
        case 0: return 0;
        case 1: system("cls"); lab0(); break;
        case 2: system("cls"); lab1v1z1(); break;
        case 3: system("cls"); lab1v1z2(); break;
        case 4: system("cls"); lab1v1z3(); break;
        case 5: system("cls"); lab2v2(); break;
        case 6: system("cls"); lab3v3(); break;
        case 7: system("cls"); lab4v5(); break;
        case 8: system("cls"); lab5v2(); break;
        case 9: system("cls"); lab6v2(); break;
        default: printf("%s", "�� ����� �� ��������� �����.\n");
        }
    }
}





/*
void lab7() {
    Node* list = create_list(100);
    for (int i = 0; i < 100; i++) {
        *get_list_value(list, i) = rand() % 10;
    }
    int a;
    a = 0;
    for (int i = 0; i < 100; i++) {
        if (*get_list_value(list, i) == 3) {
            a += 1;
        }
    }
    printf("%d", a);
}
*/
