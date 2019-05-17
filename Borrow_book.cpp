#include "used.h"

extern book *books;
extern int numBook;

void Borrow_book()
{
    int needID;
    char yn;

    cout << "查找书籍，请";
    Search_book();

    cout << "是否继续借阅(Y/N)？";
    cin >> yn;
    while(yn!='Y' || yn!='y' || yn!='N' || yn!='n')
    {
        cout << "请输入Y/N";
        cin >> yn;
    }

    cout << "请输入借阅的书籍序号：";
    cin >> needID; //needID = array index +1
    while(needID<1 || needID>numBook)
    {
        cout << "查无此书，请重新输入：";
        cin >> needID;
    }

    //confirm the information and borrow
    cout << "\t书名\t 主编\t 出版商\t 出版年份\t ISBN" << endl;
    cout.setf(ios::left);// set align left
    cout << setw(8) << needID; //number
    cout << setw(16) << books[needID-1].name;
    cout << setw(16) << books[needID-1].editor;
    cout << setw(16) << books[needID-1].publisher;
    cout << setw(8) << books[needID-1].year;
    cout << setw(16) << books[needID-1].ISBN;
    cout << "您要借阅的是否为此书(Y/N)：";
    cin >> yn;
    while(yn!='Y' || yn!='y' || yn!='N' || yn!='n')
    {
        cout << "请输入Y/N";
        cin >> yn;
    }
    if(yn='n' || yn='N')
        return;
    else
        if(books[needID-1].left > 0)
        {
            books[needID-1].left--;
            books[needID-1].borrow++;
            cout << "借阅成功！" << endl;
        }
        else
            cout << "书籍剩余量不足，借阅失败！" << endl;

}
