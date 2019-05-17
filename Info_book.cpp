#include "used.h"

extern int numBook;
extern book *books;

//code 1 for detail, 0 for simple
void Showtable(int code)
{
    cout.setf(ios::left);// set align left
    if(code == 1)
        cout << "\t����\t ����\t ������\t �������\t ���\t ISBN\t ����\t ���\t ʣ��" << endl;
    else
        cout << "\t����\t ����" << endl;
}

void Info_book(int code)
{
    int i;

    if(numBook == 0)
    {
        cout << "�������鼮��¼��" << endl;
        return;
    }

    Showtable(code);
    if(code == 1)
        for(i=0; i<numBook; i++)
        {
            cout.setf(ios::left);// set align left
            cout << setw(8) << i+1; //number
            cout << setw(16) << books[i].name;
            cout << setw(16) << books[i].editor;
            cout << setw(16) << books[i].publisher;
            cout << setw(8) << books[i].year;
            cout << setw(8) << books[i].edition;
            cout << setw(16) << books[i].ISBN;
            cout << setw(8) << books[i].own;
            cout << setw(8) << books[i].borrow;
            cout << setw(8) << books[i].left;
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
        for(i=0; i<numBook; i++)
        {
            cout.setf(ios::left);// set align left
            cout << setw(8) << i+1; //number
            cout << setw(16) << books[i].name;
            cout << setw(16) << books[i].editor;
            if(i%2==0 && i!=0) cout << endl;
        }

}
