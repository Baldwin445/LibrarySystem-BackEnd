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
    char editor[10];
    char publisher[10];
    int year;
    int edition;
    long int ISBN;
    char name[16];
    int price;
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
int CFindIndex(char,int);


#endif // USED_H_INCLUDED
