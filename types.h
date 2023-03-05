
#ifndef TYPES_H
#define TYPES_H
#include <ctype.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std;
//typedef int Data;
enum genre { Detective = 'D', Roman = 'R', Fantasy = 'F' };
struct List {
    List* prev;
    List* next;
    string autor;
    string name;
    genre gen;
    int pages;
    string year;
};
void pause();
void createList();
List* createList_1();
void pop();
void destroyList();
void delete_all_object();
void pushFront();
void printList();
void printList_search();
void store_to_file();
void restore_from_file();

#endif // TYPES_H
