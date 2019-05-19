#include "used.h"

extern int numBook;
extern book *books;

void Search_book()
{
    char key[20];
    int count = 0, index[numBook+5];

    if(numBook==0)
    {
        cout << "书库未存书籍信息，查找失败！" << endl;
        return;
    }

    cout << "输入关键字：";
    cin >> key;
    index[count] = CFindIndex(key,0);
    if(index[count] == -1)
    {
        cout << "没有找到相关数据！" << endl;
        return;
    }
    while(index[count]!=-1 && ++count<=numBook)
    {
        index[count] = CFindIndex(key,index[count-1]+1);
    }

    //print the info
    if(count == 0)
        cout << "没有找到相关数据！" << endl;
    else
        cout << "一共找到" << count << "条数据：" << endl;
    Showtable(2);
    for(int i=0; i<count; i++)
    {
        cout.setf(ios::left);// set align left
        cout << setw(8) << index[i]+1; //Index + 1
        cout << setw(16) << books[index[i]].name;
        cout << setw(16) << books[index[i]].editor;
        cout << endl;
        if(i%40 == 0 && i!=0)
        {
            cout << "输入任意字符继续(ESC退出)...";
            char test = getch();
            if(test == 27) return;
            cout << endl << endl;
            Showtable(2);
        }
    }
}

int CFindIndex(char *key, int from)//Complete field search to Find Index
{
    int i;
    for(i=from; i<numBook; i++)
    {
        if(!strcmp(key,books[i].editor) || atoi(key)==books[i].ISBN || !strcmp(key,books[i].name) ||
           !strcmp(key,books[i].publisher) || atoi(key)==books[i].year)
            return i;
    }
    return -1;//if not found, return -1
}
