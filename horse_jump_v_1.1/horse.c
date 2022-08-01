#include <stdio.h>
#include <stdlib.h>

#include "horse.h"

struct hop offsets[8] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int solution_count = 0;

int **getTable() {
    int **table = (int **)calloc(8, sizeof(int *));
    for (int i = 0; i < 8; i++) {
        table[i] = (int *)calloc(8, sizeof(int));
    }
    return table;
}

void printTable(int **table) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (table[i][j] < 10) {
                printf(" ");
            }
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void freeTable(int **table) {
    for (int i  = 0; i < 8; i++) {
        free(table[i]);
    }
    free(table);
}

void horseJump(int **table) {
    int l, c;
    scanf("%d %d", &l, &c);
    table[l][c] = 1;
    allMoves(table, l, c, 2);
}

void allMoves(int **table, int l, int c, int idx) {
    for (int i = 0; i < 8; i++) {
        int l1 = l + offsets[i].hop_1;
        int c1 = c + offsets[i].hop_2;
        if ( 0 <= l1 && l1 < 8 && 0 <= c1 && c1 < 8 && table[l1][c1] == 0) {
            table[l1][c1] = idx;
            allMoves(table, l1, c1, idx + 1);
            table[l1][c1] = 0;
        }
    }
    if (idx == 65) {
        solution_count++;
        printTable(table);
        printf("\n%d\n", solution_count);
    }
}
