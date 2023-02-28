#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "allFunctions.h"
//
// Created by Artem on 28.02.2023.
//
char *findString(char *str, const char *substr) {
    int j;

    for(int i = 0; str[i]; i++) {
        if(str[i] == substr[0]) {
            for(j = 0; substr[j] && str[i+j] == substr[j]; j++);
            if(!substr[j])
                return &str[i];
        }
    }

    return NULL;
}

int getCount(const char *str, const char *substr) {
    int j; int count = 0;

    for(int i = 0; str[i]; i++) {
        if(str[i] == substr[0]) {
            for(j = 0; substr[j] && str[i+j] == substr[j]; j++);
            if(!substr[j]) {
                count++;
            }
        }
    }

    return count;
}

int contains(const char *str, const char *substr) {
    int j;

    for(int i = 0; str[i]; i++) {
        if(str[i] == substr[0]) {
            for(j = 0; substr[j] && str[i+j] == substr[j]; j++);
            if(!substr[j]) {
                return 1;
            }
        }
    }

    return 0;
}

void getTagText(char *tag, char *buffer) {
    char *ptr1; const char *ptr2;

    ptr1 = findString(tag, ">") + 1;
    ptr2 = findString(ptr1, "<");
    strncpy(buffer, ptr1, ptr2-ptr1);
    buffer[ptr2-ptr1] = '\0';
}

char* getLeft(const char* str) {
    int sub = 0;
    char nbsp[6] = "&nbsp;";
    int j; int i;
    for(i = 0; str[i]; i++) {
        if(str[i] == '&' || str[i] == ' ') {
            for(j = 0; j < 6 && str[i+j] != nbsp[j]; j++);
            if(j == 6 || str[i] == ' ')
            {
                sub = i;
                break;
            }
        }
    }
    if(sub == 0)
        sub = i;
    char* buf = (char*)malloc((sub+1)*sizeof(char));
    strncpy(buf, str, sub);
    buf[sub] = '\0';
    return buf;
}
void removeSpaces(char *str) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void parseContent(char* ptr, const char* localEnd, Computer** computers, int currPos) {
    char name[100]; float price = 0.0f; int purpose = 0; int operationSystem = 0; char CPU[50]; char GPU[50]; int memoryValue; int numberOfCores;
    char buffer[1000]; char typeBuffer[1000];
    ptr = findString(ptr, "<span class=\"result__name\">");
    getTagText(ptr, buffer);
    snprintf(name, sizeof(name), "%s", buffer);
    char *descPtr = findString(ptr, "<td class='result__attr_var");
    while(descPtr != NULL && descPtr < localEnd) {
        getTagText(descPtr, typeBuffer);

        descPtr = findString(descPtr, "<td class='result__attr_val");
        getTagText(descPtr, buffer);

        if(contains(typeBuffer, "Назначение")) {
            if(contains(buffer, "домашниий")) {
                purpose = homeusePC;
            }
            else if(contains(buffer, "геймерский")) {
                purpose = gamingPC;
            }
        }
        else if(contains(typeBuffer, "Процессор")) {
            sscanf(buffer, "%s", CPU);
        }
        else if(contains(typeBuffer, "Операционная система")) {
            if(contains(buffer, "DOS")) {
                operationSystem = Dos;
            }
            else if(contains(buffer, "Windows")) {
                operationSystem = Windows;
            }
            else if(contains(buffer, "Linux")) {
                operationSystem = Linux;
            }
        }
        else if(contains(typeBuffer, "Объем памяти")) {
            char* gl = getLeft(buffer);
            sscanf(gl, "%d", &memoryValue);
            free(gl);
        }
        else if(contains(typeBuffer, "Модель видеокарты")) {
            sscanf(buffer, "%s", GPU);
        }
        else if(contains(typeBuffer, "Кол-во ядер процессора")) {
            sscanf(buffer, "%d", &numberOfCores);
        }
        descPtr = findString(descPtr, "<td class='result__attr_var");
    }
    ptr = findString(ptr, "<span data-code=\"");
    getTagText(ptr, buffer);
    removeSpaces(buffer);
    sscanf(buffer, "%f", &price);
    (*computers)[currPos] = init(name, price,purpose,operationSystem,CPU,GPU,memoryValue,numberOfCores);
}

void htmlParse(Computer ** computers, int* size) {
    char html[1000000]; char *ptr; char *start; const char *end;

    FILE *fp = fopen("C:\\Users\\Artem\\Desktop\\GamingPC.html", "r");
    if (fp == NULL) {
        printf("Error: Failed to open URL.");
        return;
    }

    fread(html, 1, sizeof(html), fp);
    fclose(fp);

    start = findString(html, "<ul class=\"b-result\" id=\"j-result-page-");
    end = findString(start, "</ul>");

    ptr = start;
    int count = getCount(ptr, "<li class=\"result__item cr-result__full");
    *size = count;
    *computers = (Computer *) calloc(60, sizeof(Computer));
    int currPos = 0;
    while (ptr < end) {
        ptr = findString(ptr, "<li class=\"result__item cr-result__full");
        if (ptr == NULL)
            break;
        char* localEnd = findString(ptr, "</li>");
        parseContent(ptr,localEnd,computers,currPos);
        currPos++;
        ptr = localEnd;
    }
}
