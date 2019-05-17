#include "used.h"

extern int numBook;
extern int arraySize;
extern book *books;

void Add_book()
{
    char str[4];
    int newbook=0;//count new books

    if(numBook > MAXNUM)
    {
        cout << "书籍库存已满，无法存储" << endl;
        return;
    }

    while(1)
    {
        cout << "是否确认新建书籍信息(Y/N):" << endl;
        cin >> str;
        if(!strcmp(str,"N") || !strcmp(str,"n"))
            break;
        if(numBook >= arraySize)//no enough space to store
        {
            books = (book*)realloc(books,(arraySize+INCR_SIZE)*sizeof(books));
            if(books == NULL)
            {
                cout << "内存已满，存储失败！" << endl;
                exit(-1);
            }
            arraySize += INCR_SIZE;//update the new size of array
        }

        cout << "输入主编：";        cin >> books[numBook].editor;
        cout << "输入出版社：";       cin >> books[numBook].publisher;
        cout << "输入出版年份：";      cin >> books[numBook].year;
        cout << "输入版号：";        cin >> books[numBook].edition;
        cout << "输入ISBN：";          cin >> books[numBook].ISBN;
        cout << "输入书名：";        cin >> books[numBook].name;
        cout << "输入价格：";        cin >> books[numBook].price;
        cout << "输入书籍数量";       cin >> books[numBook].own;
        numBook++;newbook++;

        cout << endl << "成功连续新增" << newbook << "本书，现已有" << numBook << "本书。" << endl;

    }



}
