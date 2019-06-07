#include "used.h"

extern int numBook;
extern book *books;

void Info_book(int code)
{
    int i;

    if(numBook == 0)
    {
        cout << "库中无书籍记录。" << endl;
        return;
    }

    cout << endl;
    Showtable(code);
    if(code == 1)
        for(i=0; i<numBook; i++)
        {
            cout.setf(ios::left);// set align left
            cout << setw(8) << books[i].order; //number
            cout << setw(8) << books[i].name;
            cout << setw(8) << books[i].editor;
            cout << setw(8) << books[i].publisher;
            cout << setw(8) << books[i].year;
            cout << setw(8) << books[i].edition;
            cout << setw(16) << books[i].ISBN;
            cout << setw(8) << books[i].own;
            cout << setw(8) << books[i].borrow;
            cout << endl;
            if(i%20==0 && i!=0)//stop printing every 20 times
            {
                cout << "输入任意字符继续(ESC退出)...";
                char test = getch();
                if(test == 27) return;
                cout << endl << endl;
                Showtable(code);
            }
        }
    else
        if(code == 2)
            for(i=0; i<numBook; i++)
            {
                cout.setf(ios::left);// set align left
                cout << setw(8) << books[i].order; //number
                cout << setw(16) << books[i].name;
                cout << setw(16) << books[i].editor;
                cout << setw(16) << books[i].publisher;
                cout << endl;
            }
        else
            cmd_info();

}

//code 1 for detail, 0 for simple
void Showtable(int code)
{
    cout.setf(ios::left);// set align left
    if(code == 1)
        cout << "序号\t书名\t主编\t出版商\t出版年\t版号\tISBN\t\t数量\t借出" << endl;
    else
        if(code == 2)
        cout << "序号\t书名\t\t主编\t\t出版商" << endl;
}

//show info for CMD by every book
void cmd_info()
{
    int i;
    if(numBook == 0)
    {
        cout << "库中无书籍记录。" << endl;
        return;
    }

    for(i=0;i<numBook;i++)
    {
        cout << "书名：《" << books[i].name << "》" << endl;
        cout << "主编：" << books[i].editor << endl;
        cout << "出版商：" << books[i].publisher << endl;
        cout << "出版年份：" << books[i].year << endl;
        cout << "版号：" << books[i].edition << endl;
        cout << "ISBN：" << books[i].ISBN << endl;
        cout << "数量：" << books[i].own << endl;
        cout << "价格：" << books[i].price << endl;
        cout << "借出：" << books[i].borrow << endl;
        cout << endl;

    }
}
