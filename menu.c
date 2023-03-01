#include <stdio.h>
#include <stdlib.h>
#include "allFunctions.h"
//
// Created by Artem on 28.02.2023.
//
int checkArray(int size) {
    if(size <= 0)
    {
        printf("Incorrect input!\n");
        return 1;
    }
    return 0;
}

void indexDelete(Computer** arr, int* sizeArr) {
    int index;
    printf("Enter index of structure which u wanna delete: ");

    while(!scanf("%d", &index) || index < 0 || index >= *sizeArr) {
        printf("Incorrect input!\n");
        rewind(stdin);
    }
    removeFromArray(arr, sizeArr, index);
}

void menu() {
    int size = 0;
    Computer* computers;

    while(1) {
        printf("\nEnter number of task:\n"
               "1 - Input array\n"
               "2 - Output array\n"
               "3 - Sort by fields\n"
               "4 - Delete struct\n"
               "5 - Exit\n"
               "Your choice: ");
        int choice;
        while(!scanf("%d", &choice) || choice < 1 || choice > 6) {
            printf("Invalid choice! Valid choice [1-5]\n");
            rewind(stdin);
            printf("Your choice: ");
        }
        printf("\n");
        switch (choice) {
            case 1:
                if(size > 0)
                    free(computers);
                initStruct(&computers, &size);
                break;
            case 2:
                if(checkArray(size))
                    break;
                printArray(computers,size);
                break;
            case 3:
                if(checkArray(size))
                    break;
                sort(computers,size);
                break;
            case 4:
                if(checkArray(size))
                    break;
                indexDelete(&computers, &size);
                break;
            default:
                if(size > 0) free(computers);
                return;
        }
    }
}
