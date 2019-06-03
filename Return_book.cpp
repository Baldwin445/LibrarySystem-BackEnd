#include "used.h"

extern book *books;
extern int numBook;

void Return_book()
{
    char key[20],yn;
    int index, count;

    if(numBook==0)
    {
        cout << "���δ���鼮��Ϣ���黹ʧ�ܣ�" << endl;
        return;
    }

    cout << "����黹�鼮�����Ϣ��";
    cin >> key;

    //print the info
    Showtable(2);
    index=CFindIndex(key,0);
    if(index==-1)
    {
        cout << "û��������¼��";
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
            cout << "���������ַ�����(ESC�˳�)...";
            char test = getch();
            if(test == 27) return;
            cout << endl << endl;
            Showtable(2);
        }
        index=CFindIndex(key,index+1);
    }
    if(count==0) cout << endl << "�������鼮��δ���ҵ������Ϣ��" << endl;

    //confirm the info and send back
    if(yn=='N' || yn=='n') return;

    cout << "������黹�鼮��ţ�";
    cin >> index;
    index = CFindIndex(index);
    while(index == -1)
    {
        cout << "���޴��飬���������룺";
        cin >> index;
        index = CFindIndex(index);
    }

    cout << "���\t����\t\t����\t\t������\t\t������\tISBN" << endl;
    cout.setf(ios::left);// set align left
    cout << setw(8) << books[index].order; //number
    cout << setw(16) << books[index].name;
    cout << setw(16) << books[index].editor;
    cout << setw(16) << books[index].publisher;
    cout << setw(8) << books[index].year;
    cout << setw(16) << books[index].ISBN << endl;
    cout << "��Ҫ�黹���Ƿ�Ϊ����(Y/N)��";
    cin >> yn;
    while(yn!='Y' && yn!='y' && yn!='N' && yn!='n')
    {
        cout << "������Y/N:";
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
