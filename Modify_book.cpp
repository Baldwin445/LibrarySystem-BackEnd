#include "used.h"

extern int numBook;
extern book *books;

void Modify_book()
{
    int needID;
    char yn;

    if(numBook==0)
    {
        cout << "书库未存书籍信息，修改失败！" << endl;
        return;
    }

    cout << "是否确认修改书籍信息(Y/N):" << endl;
    cin >> yn;
    if(yn=='N' || yn=='n') return;

    while(1)
    {
        cout << "查找所需修改的书籍，请";
        Search_book();

        cout << "请输入修改的书籍序号：";
        cin >> needID; //needID = array index +1
        while(needID<1 || needID>numBook)
        {
            cout << "查无此书，请重新输入：";
            cin >> needID;
        }

        //confirm the info and modify it
        needID--;
        cout.setf(ios::left);// set align left
        cout << setw(8) << needID+1; //number
        cout << setw(16) << books[needID].name;
        cout << setw(16) << books[needID].editor;
        cout << setw(16) << books[needID].publisher;
        cout << setw(8) << books[needID].year;
        cout << setw(8) << books[needID].edition;
        cout << setw(16) << books[needID].ISBN;
        cout << endl;

        cout << "是否为修改目标(Y/N)？";
        cin >> yn;
        while(yn!='Y' && yn!='y' && yn!='N' && yn!='n')
        {
            cout << "请输入Y/N";
            cin >> yn;
        }
        if(yn=='N' || yn=='n') return;
        cout << "重新输入该书籍信息：";
        cout << "输入主编：";        cin >> books[needID].editor;
        cout << "输入出版社：";       cin >> books[needID].publisher;
        cout << "输入出版年份：";      cin >> books[needID].year;
        cout << "输入版号：";        cin >> books[needID].edition;
        cout << "输入ISBN：";          cin >> books[needID].ISBN;
        cout << "输入书名：";        cin >> books[needID].name;
        cout << "输入价格：";        cin >> books[needID].price;
        cout << "输入书籍数量";       cin >> books[needID].own;

        cout << endl << "已成功修改书籍信息！" << endl;

    }

}
