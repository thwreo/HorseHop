#ifndef _HORSE_H_
#define _HORSE_H_

typedef struct hop {
    int hop_2;
    int hop_1;
};


int **getTable();
void printTable(int **table);
void freeTable(int **table);
void horseJump(int **table);
void allMoves(int **table, int l, int c, int idx);


#endif