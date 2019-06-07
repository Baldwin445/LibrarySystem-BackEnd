#include "used.h"

extern int numBook;
extern book *books;

void Modify_book()
{
    int needID, num, change, flag;
    char yn;

    if(numBook==0)
    {
        cout << "书库未存书籍信息，修改失败！" << endl;
        return;
    }

    flag=1;
    while(flag)
    {
        cout << "查找所需修改的书籍，请";
        Search_book();

        cout << "请输入修改的书籍序号：";
        cin >> needID;
        needID = CFindIndex(needID);// find the real index in array
        while(needID ==-1)
        {
            cout << "查无此书，请重新输入：";
            cin >> needID;
            needID = CFindIndex(needID);
        }

        //input info again
        while(flag)
        {
            cout << endl << endl;
            cout << "1.书名  2.主编  3.出版社    4.出版年份  5.版号" << endl;
            cout << "6.ISBN  7.价格  8.书籍数量  9.借出数量  0.全部" << endl;
            cout << "输入修改的对应序号（输入其他任意键退出）：";

            num = getch();
            cout << endl << endl;

            switch(num)
            {
                case 49:
                    cout << "输入书名：";
                    cin >> books[needID].name;
                    break;
                case 50:
                    cout << "输入主编：";
                    cin >> books[needID].editor;
                    break;
                case 51:
                    cout << "输入出版社：";
                    cin >> books[needID].publisher;
                    break;
                case 52:
                    cout << "输入版号：";
                    cin >> books[needID].edition;
                    break;
                case 53:
                    cout << "输入出版年份：";
                    cin >> books[needID].year;
                    break;
                case 54:
                    cout << "输入ISBN：";
                    cin >> books[needID].ISBN;
                    break;
                case 55:
                    cout << "输入价格：";
                    cin >> books[needID].price;
                    break;
                case 56:
                    cout << "输入书籍数量：";
                    cin >> change;
                    while(change<books[needID].borrow)
                    {
                        cout << "不在可输入范围！重新输入：";
                        cin >> change;
                    }
                    books[needID].own=change;
                    books[needID].left=books[needID].own-books[needID].borrow;
                    break;
                case 57:
                    cout << "输入已借出数量：";
                    cin >> change;
                    while(change>books[needID].own || change<0)
                    {
                        cout << "不在可输入范围！重新输入：";
                        cin >> change;
                    }
                    books[needID].borrow=change;
                    books[needID].left=books[needID].own-books[needID].borrow;
                    break;
                case 48:
                    cout << "重新输入该书籍信息：";
                    cout << "输入主编：";        cin >> books[needID].editor;
                    cout << "输入出版社：";       cin >> books[needID].publisher;
                    cout << "输入出版年份：";      cin >> books[needID].year;
                    cout << "输入版号：";        cin >> books[needID].edition;
                    cout << "输入ISBN：";          cin >> books[needID].ISBN;
                    cout << "输入书名：";        cin >> books[needID].name;
                    cout << "输入价格：";        cin >> books[needID].price;
                    cout << "输入书籍数量";       cin >> books[needID].own;
                    break;
                default:
                    flag=0;
            }
        }

        cout << endl << "已成功修改书籍信息！" << endl;

    }

}
