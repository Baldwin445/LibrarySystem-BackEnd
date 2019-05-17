#include "used.h"

extern book *books;
extern int numBook;

void Borrow_book()
{
    int needID;
    char yn;

    cout << "�����鼮����";
    Search_book();

    cout << "�Ƿ��������(Y/N)��";
    cin >> yn;
    while(yn!='Y' || yn!='y' || yn!='N' || yn!='n')
    {
        cout << "������Y/N";
        cin >> yn;
    }

    cout << "��������ĵ��鼮��ţ�";
    cin >> needID; //needID = array index +1
    while(needID<1 || needID>numBook)
    {
        cout << "���޴��飬���������룺";
        cin >> needID;
    }

    //confirm the information and borrow
    cout << "\t����\t ����\t ������\t �������\t ISBN" << endl;
    cout.setf(ios::left);// set align left
    cout << setw(8) << needID; //number
    cout << setw(16) << books[needID-1].name;
    cout << setw(16) << books[needID-1].editor;
    cout << setw(16) << books[needID-1].publisher;
    cout << setw(8) << books[needID-1].year;
    cout << setw(16) << books[needID-1].ISBN;
    cout << "��Ҫ���ĵ��Ƿ�Ϊ����(Y/N)��";
    cin >> yn;
    while(yn!='Y' || yn!='y' || yn!='N' || yn!='n')
    {
        cout << "������Y/N";
        cin >> yn;
    }
    if(yn='n' || yn='N')
        return;
    else
        if(books[needID-1].left > 0)
        {
            books[needID-1].left--;
            books[needID-1].borrow++;
            cout << "���ĳɹ���" << endl;
        }
        else
            cout << "�鼮ʣ�������㣬����ʧ�ܣ�" << endl;

}
