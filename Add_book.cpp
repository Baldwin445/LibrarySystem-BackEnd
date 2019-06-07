#include "used.h"

extern int numBook;
extern int arraySize;
extern book *books;

void Add_book()
{
    char str[4], yn;
    book add;
    int newbook=0;//count new books

    if(numBook > MAXNUM)
    {
        cout << "�鼮����������޷��洢" << endl;
        return;
    }

    while(1)
    {
        //choose the mode to sort
        cout << "ѡ����ģʽ��\n1.�ֶ����  2.�Զ���ţ���ESC�˳��˹��ܣ���";
        yn = getch();
        while(yn!=27 && yn!=49 && yn!=50)
            yn = getch();
        if(yn==27) break;
        cout << endl;

        //check the main key if there are some conflicts
        if(yn==49)
        {
            cout << "������ţ�";        cin >> add.order;
            for(int i=0;i<numBook;i++)
            {
                if(books[i].order == add.order)
                {
                    cout << "�Ѵ�����ͬ��ŵ��鼮���洢ʧ�ܣ�" << endl;
                    return;
                }
            }
        }
        else
            add.order=findNoConflict(numBook+1);

        cout << "����������";        cin >> add.name;
        for(int i=0;i<numBook;i++)
        {
            if(!strcmp(books[i].name,add.name))
            {
                cout << "�Ѵ�����ͬ�������鼮���洢ʧ�ܣ�" << endl;
                return;
            }
        }
        cout << "����ISBN��";          cin >> add.ISBN;
        for(int i=0;i<numBook;i++)
        {
            if(add.ISBN==books[i].ISBN)
            {
                cout << "�Ѵ�����ͬISBN���鼮���洢ʧ�ܣ�" << endl;
                return;
            }
        }

        cout << "�������ࣺ";        cin >> add.editor;
        cout << "��������磺";       cin >> add.publisher;
        cout << "���������ݣ�";      cin >> add.year;
        cout << "�����ţ�";        cin >> add.edition;
        cout << "����۸�";        cin >> add.price;
        cout << "�����鼮������";       cin >> add.own;


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

        books[numBook].left = add.own;
        books[numBook].order = add.order;
        books[numBook].edition = add.edition;
        books[numBook].price = add.price;
        books[numBook].own = add.own;
        books[numBook].year = add.year;
        books[numBook].ISBN = add.ISBN;
        strcpy(books[numBook].name, add.name);
        strcpy(books[numBook].editor, add.editor);
        strcpy(books[numBook].publisher, add.publisher);

        numBook++;newbook++; //recode the amount of books about addition and origin

    }

    save_data();
    cout << endl << "�ɹ���������" << newbook << "���飬������" << numBook << "���顣" << endl;

}


int findNoConflict(int num)
{
    for(int i=0; i<numBook; i++)
        if(num==books[i].order)
        {
            num = findNoConflict(num+1);
            break;
        }
    return num;
}

