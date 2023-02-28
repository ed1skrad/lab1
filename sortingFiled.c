#include "allFunctions.h"
#include <string.h>
#include <stdio.h>

int compareName(const Computer* a, const Computer* b) {
    return strcmp(a->name, b->name);
}
int comparePrice(const void *a, const void *b) {
    Computer* compa = (Computer*)a;
    Computer* compb = (Computer*)b;
    if(compa->price<compb->price)
        return -1;
    else if(compa->price>compb->price)
        return 1;
    return 0;
}
int comparePurpose(const Computer * a, const Computer * b) {
    if(a->purpose<b->purpose)
        return -1;
    else if(a->purpose>b->purpose)
        return 1;
    return 0;
}
int compareOperationSystem(const Computer * a, const Computer * b) {
    if(a->operationSystem<b->operationSystem)
        return -1;
    else if(a->operationSystem>b->operationSystem)
        return 1;
    return 0;
}
int compareMemoryValue(const Computer * a, const Computer * b) {
    if(a->memoryValue<b->memoryValue)
        return -1;
    else if(a->memoryValue>b->memoryValue)
        return 1;
    return 0;
}
int compareCores(const Computer * a, const Computer * b) {
    if(a->numberOfCores<b->numberOfCores)
        return -1;
    else if(a->numberOfCores>b->numberOfCores)
        return 1;
    return 0;
}

int compareCPU(const Computer* a, const Computer* b) {
    return strcmp(a->CPU, b->CPU);
}

int compareGPU(const Computer* a, const Computer* b) {
    return strcmp(a->GPU, b->GPU);
}


int secondSort(int (*compareTypes[8]) (Computer*, Computer*), Computer* a, Computer* b) {
    int comp = 0;
    for(int i = 0; i < 8; i++) {
        if(compareTypes[i] == NULL || comp != 0) break;
        comp = ((*compareTypes[i])(a, b));
    }
    return comp;
}

void sort(Computer * arr, int size) {
    int (*compareTypes[8]) (Computer*, Computer*) = {(int (*)(Computer *, Computer *)) &compareName,
                                                     (int (*)(Computer *, Computer *)) &comparePrice,
                                                     (int (*)(Computer *, Computer *)) &comparePurpose,
                                                     (int (*)(Computer *, Computer *)) &compareOperationSystem
                                                        , (int (*)(Computer *, Computer *)) &compareCPU,
                                                     (int (*)(Computer *, Computer *)) &compareCores,
                                                     (int (*)(Computer *, Computer *)) &compareMemoryValue,
                                                     (int (*)(Computer *, Computer *)) &compareGPU};
    int count;
    printf("Choose sort count: ");
    while(!scanf("%d", &count) || count < 1 || count > 8) {
        printf("Incorrect input!\n");
        rewind(stdin);
        printf("Choose sort count: ");
    }
    printf("0 - Name\n"
           "1 - Price\n"
           "2 - Purpose\n"
           "3 - Operation System\n"
           "4 - CPU\n"
           "5 - Cores\n"
           "6 - Memory Value\n"
           "7 - GPU\n");
    int (*secondTypes[8]) (Computer*, Computer*);
    for(int i = 0; i < count; i++) {
        int ss;
        printf("Choose sort type: ");
        while(!scanf("%d", &ss) || ss < 0 || ss > 8) {
            printf("Incorrect input!\n");
            rewind(stdin);
            printf("Choose second sort type: ");
        }
        secondTypes[i] = compareTypes[ss];
    }
    for(int i = count; i < 8; i++) {
        secondTypes[i] = NULL;
    }

    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            int comp = secondSort(secondTypes, &arr[j], &arr[j+1]);
            if(comp > 0) {
                Computer tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}