//
// Created by Artem on 28.02.2023.
//

#ifndef LABSTRUCT_STRUCT_H
#define LABSTRUCT_STRUCT_H
enum Purpose{
    NONEclass,
    homeusePC,
    gamingPC
};

enum OperationSystem {
    NONEClass,
    Windows,
    Dos,
    Linux
};


typedef struct {
    char name[100];
    int price;
    enum Purpose purpose;
    enum OperationSystem operationSystem;
    char CPU[50];
    char GPU[50];
    int memoryValue;
    int numberOfCores;
}Computer;
#endif //LABSTRUCT_STRUCT_H
