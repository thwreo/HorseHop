#include <stdio.h>
#include <stdlib.h>

#include "horse.h"

int main() {
    int **table = getTable();
    horseJump(table);
    freeTable(table);
    return 0;
}