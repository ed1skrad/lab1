#include <stdio.h>
#include "allFunctions.h"
//
// Created by Artem on 28.02.2023.
//
void printArray(Computer * array, int count) {
    const char *purposes[] = { "NONE", "homeusePC", "gamingPC"};
    const char *operationSystems[] = { "NONE", "Dos", "Windows", "Linux"};
    for(int i = 0; i < count; i++) {
        printf("Struct %d\n", i);
        printf("Name: %s\n", array[i].name);
        printf("Price: %f\n", array[i].price);
        printf("Purpose:(1 - homeuse pc, 2 - gaming pc)%s\n", purposes[array[i].purpose]);
        printf("CPU: %s\n", array[i].CPU);
        printf("Operation System(1 - Windows, 2 - Dos, 3 - Linux: %s\n", operationSystems[array[i].operationSystem]);
        printf("GPU: %s\n", array[i].GPU);
        printf("Memory Value: %d\n", array[i].memoryValue);
        printf("Number of cores: %d\n", array[i].numberOfCores);
        printf("\n");
    }
}
