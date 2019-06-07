#include "used.h"

extern int numBook;
extern int arraySize;
extern book *books;

void Add_book()
{
    char str[4], yn;
    book add;
    int newbook=0;//count new books

    if(numBook > MAXNUM)
    {
        cout << "书籍库存已满，无法存储" << endl;
        return;
    }

    while(1)
    {
        //choose the mode to sort
        cout << "选择编号模式：\n1.手动编号  2.自动编号（按ESC退出此功能）：";
        yn = getch();
        while(yn!=27 && yn!=49 && yn!=50)
            yn = getch();
        if(yn==27) break;
        cout << endl;

        //check the main key if there are some conflicts
        if(yn==49)
        {
            cout << "输入序号：";        cin >> add.order;
            for(int i=0;i<numBook;i++)
            {
                if(books[i].order == add.order)
                {
                    cout << "已存在相同序号的书籍，存储失败！" << endl;
                    return;
                }
            }
        }
        else
            add.order=findNoConflict(numBook+1);

        cout << "输入书名：";        cin >> add.name;
        for(int i=0;i<numBook;i++)
        {
            if(!strcmp(books[i].name,add.name))
            {
                cout << "已存在相同书名的书籍，存储失败！" << endl;
                return;
            }
        }
        cout << "输入ISBN：";          cin >> add.ISBN;
        for(int i=0;i<numBook;i++)
        {
            if(add.ISBN==books[i].ISBN)
            {
                cout << "已存在相同ISBN的书籍，存储失败！" << endl;
                return;
            }
        }

        cout << "输入主编：";        cin >> add.editor;
        cout << "输入出版社：";       cin >> add.publisher;
        cout << "输入出版年份：";      cin >> add.year;
        cout << "输入版号：";        cin >> add.edition;
        cout << "输入价格：";        cin >> add.price;
        cout << "输入书籍数量：";       cin >> add.own;


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

        books[numBook].left = add.own;
        books[numBook].order = add.order;
        books[numBook].edition = add.edition;
        books[numBook].price = add.price;
        books[numBook].own = add.own;
        books[numBook].year = add.year;
        books[numBook].ISBN = add.ISBN;
        strcpy(books[numBook].name, add.name);
        strcpy(books[numBook].editor, add.editor);
        strcpy(books[numBook].publisher, add.publisher);

        numBook++;newbook++; //recode the amount of books about addition and origin

    }

    save_data();
    cout << endl << "成功连续新增" << newbook << "本书，现已有" << numBook << "本书。" << endl;

}


int findNoConflict(int num)
{
    for(int i=0; i<numBook; i++)
        if(num==books[i].order)
        {
            num = findNoConflict(num+1);
            break;
        }
    return num;
}

