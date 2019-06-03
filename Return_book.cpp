#include "used.h"

extern book *books;
extern int numBook;

void Return_book()
{
    char key[20],yn;
    int index, count;

    if(numBook==0)
    {
        cout << "书库未存书籍信息，归还失败！" << endl;
        return;
    }

    cout << "输入归还书籍相关信息：";
    cin >> key;

    //print the info
    Showtable(2);
    index=CFindIndex(key,0);
    if(index==-1)
    {
        cout << "没有搜索记录！";
        return;
    }
    for(count=0;index!=-1;)
    {
        if(books[index].borrow>0)
        {
            count++;
            cout.setf(ios::left);// set align left
            cout << setw(8) << books[index].order; //Index + 1
            cout << setw(16) << books[index].name;
            cout << setw(16) << books[index].editor << endl;
        }
        if(count%20 == 0 && count!=0)
        {
            cout << "输入任意字符继续(ESC退出)...";
            char test = getch();
            if(test == 27) return;
            cout << endl << endl;
            Showtable(2);
        }
        index=CFindIndex(key,index+1);
    }
    if(count==0) cout << endl << "被借阅书籍中未查找到相关信息！" << endl;

    //confirm the info and send back
    if(yn=='N' || yn=='n') return;

    cout << "请输入归还书籍序号：";
    cin >> index;
    index = CFindIndex(index);
    while(index == -1)
    {
        cout << "查无此书，请重新输入：";
        cin >> index;
        index = CFindIndex(index);
    }

    cout << "序号\t书名\t\t主编\t\t出版商\t\t出版年\tISBN" << endl;
    cout.setf(ios::left);// set align left
    cout << setw(8) << books[index].order; //number
    cout << setw(16) << books[index].name;
    cout << setw(16) << books[index].editor;
    cout << setw(16) << books[index].publisher;
    cout << setw(8) << books[index].year;
    cout << setw(16) << books[index].ISBN << endl;
    cout << "您要归还的是否为此书(Y/N)：";
    cin >> yn;
    while(yn!='Y' && yn!='y' && yn!='N' && yn!='n')
    {
        cout << "请输入Y/N:";
        cin >> yn;
    }
    if(yn=='n' || yn=='N')
        return;
    else
        if(books[index].borrow > 0)
        {
            books[index].left++;
            books[index].borrow--;
            cout << "归还成功！" << endl;
        }
        else
            cout << "书籍未曾借出，归还失败！" << endl;



}
