#include "used.h"

extern book *books;
extern int numBook;

void Borrow_book()
{
    int needID;
    char yn;

    if(numBook==0)
    {
        cout << "���δ���鼮��Ϣ������ʧ�ܣ�" << endl;
        return;
    }
    while(1)
    {
        cout << "�����鼮����";
        Search_book();

        cout << endl << "��������ĵ��鼮��ţ�";
        cin >> needID; //needID = array index +1
        while(needID<1 || needID>numBook)
        {
            cout << "���޴��飬���������룺";
            cin >> needID;
        }

        //confirm the information and borrow
        needID--;//needID-1=index of book in array
        cout << "���\t����\t\t����\t\t������\t\t������\tISBN" << endl;
        cout.setf(ios::left);// set align left
        cout << setw(8) << needID+1; //number
        cout << setw(16) << books[needID].name;
        cout << setw(16) << books[needID].editor;
        cout << setw(16) << books[needID].publisher;
        cout << setw(8) << books[needID].year;
        cout << setw(16) << books[needID].ISBN <<endl;;
        cout << "��Ҫ���ĵ��Ƿ�Ϊ����(Y/N)��";
        cin >> yn;
        while(yn!='Y' && yn!='y' && yn!='N' && yn!='n')
        {
            cout << "������Y/N:";
            cin >> yn;
        }
        if(yn=='n' || yn=='N')
            return;
        else
            if(books[needID].left > 0)
            {
                books[needID].left--;
                books[needID].borrow++;
                cout << "���ĳɹ���" << endl;
            }
            else
                cout << "�鼮ʣ�������㣬����ʧ�ܣ�" << endl;

        cout << endl;
        cout << "�Ƿ��������(Y/N)��";
        cin >> yn;
        while(yn!='Y' && yn!='y' && yn!='N' && yn!='n')
        {
            cout << "������Y/N:";
            cin >> yn;
        }
        if(yn=='N' || yn=='n') return;
    }


}
