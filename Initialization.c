#include <stdio.h>
#include "struct.h"
//
// Created by Artem on 28.02.2023.
//
Computer init(char name[100], int price, int purpose, int operationSystem, char CPU[50], char GPU[50], int memoryValue, int numberOfCores) {
    Computer computer;
    snprintf(computer.name, sizeof(computer.name), "%s", name);
    computer.price = price;
    computer.purpose = purpose;
    computer.operationSystem = operationSystem;
    computer.memoryValue = memoryValue;
    computer.numberOfCores = numberOfCores;
    snprintf(computer.CPU, sizeof(computer.CPU), "%s", CPU);
    snprintf(computer.GPU, sizeof(computer.GPU), "%s", GPU);
    return computer;
}
