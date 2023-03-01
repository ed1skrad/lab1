#include <stdio.h>
#include "allFunctions.h"
//
// Created by Artem on 28.02.2023.
//
int getInt() {
    int i;
    while(scanf("%d", &i) != 1 || getchar() != '\n') {
        printf("Incorrect input!\n");
        rewind(stdin);
    }
    return i;
}
