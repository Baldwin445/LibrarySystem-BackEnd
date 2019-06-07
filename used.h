#ifndef USED_H_INCLUDED
#define USED_H_INCLUDED

//-----Constant-----//
#define MAXNUM 50000
#define MINNUM 0
#define INITIAL_SIZE 10
#define INCR_SIZE 5


//-----Headers-----//
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <windows.h>

using namespace std;



//-----Structure-----//
typedef struct book
{
    int order;
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

typedef struct account
{
    char username[12];
    char userpwd[19];
    int id; //1 for administrator, 2 for user
}account;


//-----Functions-----//
int Menu_UI(int idcode);
int Identify_UI();
void Add_book();
void Borrow_book();
void Info_book(int idcode);
void Modify_book();
void Return_book();
void Search_book();
void Showtable(int);
int CFindIndex(char *key,int from);
void cmd_info();
int save_data();
int load_data();
int CFindIndex(int keyword);
int findNoConflict(int from);
int findAcctSN(char *username, char* userpassword);
void showAcct();
int addUser();
int addAdmin();
int saveAcct();
int loadAcct();


#endif // USED_H_INCLUDED
