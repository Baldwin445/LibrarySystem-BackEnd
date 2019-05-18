#include "used.h"

extern book *books;
extern int numBook;

void Return_book()
{
    char key[20],yn;
    int index, count;

    if(numBook==0)
    {
        cout << "书库未存书籍信息，修改失败！" << endl;
        return;
    }

    cout << "输入归还书籍相关信息：";
    cin >> key;

    //print the info
    Showtable(2);
    for(index=-1,count=0;;)
    {
        index=CFindIndex(key,index+1);
        if(index==-1 && count==0)
        {
            cout << "没有借阅记录！";
            return;
        }
        else if(index==-1 && count !=0)
            return;
        if(books[index].borrow>0)
        {
            count++;
            cout.setf(ios::left);// set align left
            cout << setw(8) << index+1; //Index + 1
            cout << setw(16) << books[index].name;
            cout << setw(16) << books[index].editor << endl;
        }
        if(count%20 == 0)
        {
            cout << "输入任意字符继续(ESC退出)...";
            char test = getch();
            if(test == 27) return;
            cout << endl << endl;
            Showtable(2);
        }
    }

    //confirm the info and send back
    cout << "是否继续借阅(Y/N)？";
    cin >> yn;
    while(yn!='Y' || yn!='y' || yn!='N' || yn!='n')
    {
        cout << "请输入Y/N";
        cin >> yn;
    }
    if(yn=='N' || yn=='n') return;

    cout << "请输入归还书籍序号：";
    cin >> index;
    while(index<1 || index>numBook)
    {
        cout << "查无此书，请重新输入：";
        cin >> index;
    }
    index--;
    cout << "\t书名\t 主编\t 出版商\t 出版年份\t ISBN" << endl;
    cout.setf(ios::left);// set align left
    cout << setw(8) << index+1; //number
    cout << setw(16) << books[index].name;
    cout << setw(16) << books[index].editor;
    cout << setw(16) << books[index].publisher;
    cout << setw(8) << books[index].year;
    cout << setw(16) << books[index].ISBN << endl;
    cout << "您要归还的是否为此书(Y/N)：";
    cin >> yn;
    while(yn!='Y' || yn!='y' || yn!='N' || yn!='n')
    {
        cout << "请输入Y/N";
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
