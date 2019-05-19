#include "used.h"

extern int numBook;
extern book *books;

void Modify_book()
{
    int needID;
    char yn;

    if(numBook==0)
    {
        cout << "���δ���鼮��Ϣ���޸�ʧ�ܣ�" << endl;
        return;
    }

    cout << "�Ƿ�ȷ���޸��鼮��Ϣ(Y/N):" << endl;
    cin >> yn;
    if(yn=='N' || yn=='n') return;

    while(1)
    {
        cout << "���������޸ĵ��鼮����";
        Search_book();

        cout << "�������޸ĵ��鼮��ţ�";
        cin >> needID; //needID = array index +1
        while(needID<1 || needID>numBook)
        {
            cout << "���޴��飬���������룺";
            cin >> needID;
        }

        //confirm the info and modify it
        needID--;
        cout.setf(ios::left);// set align left
        cout << setw(8) << needID+1; //number
        cout << setw(16) << books[needID].name;
        cout << setw(16) << books[needID].editor;
        cout << setw(16) << books[needID].publisher;
        cout << setw(8) << books[needID].year;
        cout << setw(8) << books[needID].edition;
        cout << setw(16) << books[needID].ISBN;
        cout << endl;

        cout << "�Ƿ�Ϊ�޸�Ŀ��(Y/N)��";
        cin >> yn;
        while(yn!='Y' && yn!='y' && yn!='N' && yn!='n')
        {
            cout << "������Y/N";
            cin >> yn;
        }
        if(yn=='N' || yn=='n') return;
        cout << "����������鼮��Ϣ��";
        cout << "�������ࣺ";        cin >> books[needID].editor;
        cout << "��������磺";       cin >> books[needID].publisher;
        cout << "���������ݣ�";      cin >> books[needID].year;
        cout << "�����ţ�";        cin >> books[needID].edition;
        cout << "����ISBN��";          cin >> books[needID].ISBN;
        cout << "����������";        cin >> books[needID].name;
        cout << "����۸�";        cin >> books[needID].price;
        cout << "�����鼮����";       cin >> books[needID].own;

        cout << endl << "�ѳɹ��޸��鼮��Ϣ��" << endl;

    }

}
