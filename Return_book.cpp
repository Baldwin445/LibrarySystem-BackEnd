#include "used.h"

extern book *books;
extern int numBook;

void Return_book()
{
    char key[20],yn;
    int index, count;

    if(numBook==0)
    {
        cout << "���δ���鼮��Ϣ���޸�ʧ�ܣ�" << endl;
        return;
    }

    cout << "����黹�鼮�����Ϣ��";
    cin >> key;

    //print the info
    Showtable(2);
    for(index=-1,count=0;;)
    {
        index=CFindIndex(key,index+1);
        if(index==-1 && count==0)
        {
            cout << "û�н��ļ�¼��";
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
            cout << "���������ַ�����(ESC�˳�)...";
            char test = getch();
            if(test == 27) return;
            cout << endl << endl;
            Showtable(2);
        }
    }

    //confirm the info and send back
    cout << "�Ƿ��������(Y/N)��";
    cin >> yn;
    while(yn!='Y' || yn!='y' || yn!='N' || yn!='n')
    {
        cout << "������Y/N";
        cin >> yn;
    }
    if(yn=='N' || yn=='n') return;

    cout << "������黹�鼮��ţ�";
    cin >> index;
    while(index<1 || index>numBook)
    {
        cout << "���޴��飬���������룺";
        cin >> index;
    }
    index--;
    cout << "\t����\t ����\t ������\t �������\t ISBN" << endl;
    cout.setf(ios::left);// set align left
    cout << setw(8) << index+1; //number
    cout << setw(16) << books[index].name;
    cout << setw(16) << books[index].editor;
    cout << setw(16) << books[index].publisher;
    cout << setw(8) << books[index].year;
    cout << setw(16) << books[index].ISBN << endl;
    cout << "��Ҫ�黹���Ƿ�Ϊ����(Y/N)��";
    cin >> yn;
    while(yn!='Y' || yn!='y' || yn!='N' || yn!='n')
    {
        cout << "������Y/N";
        cin >> yn;
    }
    if(yn=='n' || yn=='N')
        return;
    else
        if(books[index].borrow > 0)
        {
            books[index].left++;
            books[index].borrow--;
            cout << "�黹�ɹ���" << endl;
        }
        else
            cout << "�鼮δ��������黹ʧ�ܣ�" << endl;



}
