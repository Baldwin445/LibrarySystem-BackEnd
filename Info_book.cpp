#include "used.h"

extern int numBook;
extern book *books;

void Info_book(int code)
{
    int i;

    if(numBook == 0)
    {
        cout << "�������鼮��¼��" << endl;
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
                cout << "���������ַ�����(ESC�˳�)...";
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
        cout << "���\t����\t����\t������\t������\t���\tISBN\t\t����\t���" << endl;
    else
        if(code == 2)
        cout << "���\t����\t\t����\t\t������" << endl;
}

//show info for CMD by every book
void cmd_info()
{
    int i;
    if(numBook == 0)
    {
        cout << "�������鼮��¼��" << endl;
        return;
    }

    for(i=0;i<numBook;i++)
    {
        cout << "��������" << books[i].name << "��" << endl;
        cout << "���ࣺ" << books[i].editor << endl;
        cout << "�����̣�" << books[i].publisher << endl;
        cout << "������ݣ�" << books[i].year << endl;
        cout << "��ţ�" << books[i].edition << endl;
        cout << "ISBN��" << books[i].ISBN << endl;
        cout << "������" << books[i].own << endl;
        cout << "�۸�" << books[i].price << endl;
        cout << "�����" << books[i].borrow << endl;
        cout << endl;

    }
}
