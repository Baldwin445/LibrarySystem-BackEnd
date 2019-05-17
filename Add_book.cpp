#include "used.h"

extern int numBook;
extern int arraySize;
extern book *books;

void Add_book()
{
    char str[4];
    int newbook=0;//count new books

    if(numBook > MAXNUM)
    {
        cout << "�鼮����������޷��洢" << endl;
        return;
    }

    while(1)
    {
        cout << "�Ƿ�ȷ���½��鼮��Ϣ(Y/N):" << endl;
        cin >> str;
        if(!strcmp(str,"N") || !strcmp(str,"n"))
            break;
        if(numBook >= arraySize)//no enough space to store
        {
            books = (book*)realloc(books,(arraySize+INCR_SIZE)*sizeof(books));
            if(books == NULL)
            {
                cout << "�ڴ��������洢ʧ�ܣ�" << endl;
                exit(-1);
            }
            arraySize += INCR_SIZE;//update the new size of array
        }

        cout << "�������ࣺ";        cin >> books[numBook].editor;
        cout << "��������磺";       cin >> books[numBook].publisher;
        cout << "���������ݣ�";      cin >> books[numBook].year;
        cout << "�����ţ�";        cin >> books[numBook].edition;
        cout << "����ISBN��";          cin >> books[numBook].ISBN;
        cout << "����������";        cin >> books[numBook].name;
        cout << "����۸�";        cin >> books[numBook].price;
        cout << "�����鼮����";       cin >> books[numBook].own;
        numBook++;newbook++;

        cout << endl << "�ɹ���������" << newbook << "���飬������" << numBook << "���顣" << endl;

    }



}
