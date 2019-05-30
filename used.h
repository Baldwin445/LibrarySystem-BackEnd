#ifndef USED_H_INCLUDED
#define USED_H_INCLUDED

//-----Constant-----//
#define MAXNUM 50000
#define MINNUM 0
#define INITIAL_SIZE 10
#define INCR_SIZE 5

//-----Structure-----//
typedef struct book
{
    char editor[20];
    char publisher[20];
    int year;
    int edition;
    long long int ISBN;
    char name[30];
    float price;
    int own;
    int borrow;
    int left;
}book;


//-----Headers-----//
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;


//-----Functions-----//
int Menu_UI(int);
int Identify_UI();
void Add_book();
void Borrow_book();
void Info_book(int);
void Modify_book();
void Return_book();
void Search_book();
void Showtable(int);
int CFindIndex(char*,int);
void cmd_info();
void save_data();
void load_data();

#endif // USED_H_INCLUDED
