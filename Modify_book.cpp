#include "used.h"

extern int numBook;
extern book *books;

void Modify_book()
{
    int needID, num, change, flag;
    char yn;

    if(numBook==0)
    {
        cout << "���δ���鼮��Ϣ���޸�ʧ�ܣ�" << endl;
        return;
    }

    flag=1;
    while(flag)
    {
        cout << "���������޸ĵ��鼮����";
        Search_book();

        cout << "�������޸ĵ��鼮��ţ�";
        cin >> needID;
        needID = CFindIndex(needID);// find the real index in array
        while(needID ==-1)
        {
            cout << "���޴��飬���������룺";
            cin >> needID;
            needID = CFindIndex(needID);
        }

        //input info again
        while(flag)
        {
            cout << endl << endl;
            cout << "1.����  2.����  3.������    4.�������  5.���" << endl;
            cout << "6.ISBN  7.�۸�  8.�鼮����  9.�������  0.ȫ��" << endl;
            cout << "�����޸ĵĶ�Ӧ��ţ���������������˳�����";

            num = getch();
            cout << endl << endl;

            switch(num)
            {
                case 49:
                    cout << "����������";
                    cin >> books[needID].name;
                    break;
                case 50:
                    cout << "�������ࣺ";
                    cin >> books[needID].editor;
                    break;
                case 51:
                    cout << "��������磺";
                    cin >> books[needID].publisher;
                    break;
                case 52:
                    cout << "�����ţ�";
                    cin >> books[needID].edition;
                    break;
                case 53:
                    cout << "���������ݣ�";
                    cin >> books[needID].year;
                    break;
                case 54:
                    cout << "����ISBN��";
                    cin >> books[needID].ISBN;
                    break;
                case 55:
                    cout << "����۸�";
                    cin >> books[needID].price;
                    break;
                case 56:
                    cout << "�����鼮������";
                    cin >> change;
                    while(change<books[needID].borrow)
                    {
                        cout << "���ڿ����뷶Χ���������룺";
                        cin >> change;
                    }
                    books[needID].own=change;
                    books[needID].left=books[needID].own-books[needID].borrow;
                    break;
                case 57:
                    cout << "�����ѽ��������";
                    cin >> change;
                    while(change>books[needID].own || change<0)
                    {
                        cout << "���ڿ����뷶Χ���������룺";
                        cin >> change;
                    }
                    books[needID].borrow=change;
                    books[needID].left=books[needID].own-books[needID].borrow;
                    break;
                case 48:
                    cout << "����������鼮��Ϣ��";
                    cout << "�������ࣺ";        cin >> books[needID].editor;
                    cout << "��������磺";       cin >> books[needID].publisher;
                    cout << "���������ݣ�";      cin >> books[needID].year;
                    cout << "�����ţ�";        cin >> books[needID].edition;
                    cout << "����ISBN��";          cin >> books[needID].ISBN;
                    cout << "����������";        cin >> books[needID].name;
                    cout << "����۸�";        cin >> books[needID].price;
                    cout << "�����鼮����";       cin >> books[needID].own;
                    break;
                default:
                    flag=0;
            }
        }

        cout << endl << "�ѳɹ��޸��鼮��Ϣ��" << endl;

    }

}
