#include "used.h"

extern book *books;
extern int numBook;

void Borrow_book()
{
    int needID;
    char yn;

    if(numBook==0)
    {
        cout << "书库未存书籍信息，修改失败！" << endl;
        return;
    }

    cout << "查找书籍，请";
    Search_book();

    cout << "是否继续借阅(Y/N)？";
    cin >> yn;
    while(yn!='Y' || yn!='y' || yn!='N' || yn!='n')
    {
        cout << "请输入Y/N";
        cin >> yn;
    }
    if(yn=='N' || yn=='n') return;

    cout << "请输入借阅的书籍序号：";
    cin >> needID; //needID = array index +1
    while(needID<1 || needID>numBook)
    {
        cout << "查无此书，请重新输入：";
        cin >> needID;
    }

    //confirm the information and borrow
    needID--;//needID-1=index of book in array
    cout << "\t书名\t 主编\t 出版商\t 出版年份\t ISBN" << endl;
    cout.setf(ios::left);// set align left
    cout << setw(8) << needID+1; //number
    cout << setw(16) << books[needID].name;
    cout << setw(16) << books[needID].editor;
    cout << setw(16) << books[needID].publisher;
    cout << setw(8) << books[needID].year;
    cout << setw(16) << books[needID].ISBN <<endl;;
    cout << "您要借阅的是否为此书(Y/N)：";
    cin >> yn;
    while(yn!='Y' || yn!='y' || yn!='N' || yn!='n')
    {
        cout << "请输入Y/N";
        cin >> yn;
    }
    if(yn=='n' || yn=='N')
        return;
    else
        if(books[needID].left > 0)
        {
            books[needID].left--;
            books[needID].borrow++;
            cout << "借阅成功！" << endl;
        }
        else
            cout << "书籍剩余量不足，借阅失败！" << endl;

}
