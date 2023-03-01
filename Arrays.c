#include <stdlib.h>
#include <stdio.h>
#include "allFunctions.h"
//
// Created by Artem on 28.02.2023.
//
Computer * createArray(int count) {
    return (Computer *)calloc(count, sizeof(Computer));
}

void initStruct(Computer ** arr, int* sizeArr) {
    int size = 0;
    printf("Enter size of array:\n");
    size = getInt();
    *arr = createArray(size);
    *sizeArr = size;

    for(int i = 0; i < size; i++) {
        char name[100];
        int price;
        int purpose;
        int operationSystem;
        char CPU[50];
        char GPU[50];
        int memoryValue;
        int numberOfCores;
        rewind(stdin);
        printf("Struct %d\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        printf("Price");
        price = getInt();
        printf("Enter purpose: (1 - Homeuse PC, 2 - Gaming PC)");
        while(scanf("%d", &purpose) != 1 || getchar() != '\n' || purpose > 2 || purpose < 1)
        {
            printf("Incorrect input");
            rewind(stdin);
        }
        printf("Enter memory value:\n");
        memoryValue = getInt();
        printf("Enter operating system(1 - Windows, 2 - Dos, 3 - Linux):\n");
        while(scanf("%d", &operationSystem) != 1 || getchar() != '\n' || operationSystem > 2 || operationSystem < 1)
        {
            printf("Incorrect input");
            rewind(stdin);
        }
        printf("Enter number of cores:\n");
        numberOfCores = getInt();
        printf("CPU:\n");
        scanf("%s", CPU);
        printf("GPU\n");
        scanf("%s", GPU);
        (*arr)[i] = init(name, price,purpose,operationSystem,CPU,GPU,memoryValue,numberOfCores);
        printf("\n");
    }
}
