#include "allFunctions.h"
#include <stdio.h>
#include <stdlib.h>
//
// Created by Artem on 28.02.2023.
//
void removeFromArray(Computer **arr, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Incorrect input!");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

        *size -= 1;

    *arr = (Computer *)realloc(*arr, (*size) * sizeof(Computer));
}
