#include "used.h"

extern int acctsn;
extern account *acct;

int Menu_UI(int code)
{
    int num,length;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "�X===============================================�[" << endl;
    cout << "�U                                               �U" << endl;
    cout << "�U          �ɹ�����ͼ�����Ϣ�������           �U" << endl;
    cout << "�d-----------------------------------------------�g" << endl;
    cout << "�U                                               �U" << endl;
    if(code==1)
    {
        if(acctsn == -1)
            cout << "�U          ��ӭ����Ա Admin��                   �U" << endl;
        else
        {
            length = strlen(acct[acctsn].username);
            cout << "�U          ��ӭ����Ա " << acct[acctsn].username << "��";
            length = 24-length;
            while(length--) cout << " ";
            cout << "�U" << endl;
        }
        cout << "�U                                               �U" << endl;
        cout << "�U          1. �����Ŀ                          �U" << endl;
        cout << "�U          2. �޸���Ŀ                          �U" << endl;
        cout << "�U          3. �鿴�����Ϣ                      �U" << endl;
        cout << "�U          4. ���ص�¼����                      �U" << endl;
        cout << "�U          9. ע���¹���Ա�˺�                  �U" << endl;
        cout << "�U          0. �˳�                              �U" << endl;

    }
    else
    {
        if(acctsn == -2)
            cout << "�U          ��ӭ�û� User��                      �U" << endl;
        else
        {
            length = strlen(acct[acctsn].username);
            cout << "�U          ��ӭ�û� " << acct[acctsn].username << "��";
            length = 26-length;
            while(length--) cout << " ";
            cout << "�U" << endl;
        }
        cout << "�U                                               �U" << endl;
        cout << "�U          1. ����                              �U" << endl;
        cout << "�U          2. ����                              �U" << endl;
        cout << "�U          3. �����鼮                          �U" << endl;
        cout << "�U          4. ���ص�¼����                      �U" << endl;
        cout << "�U          0. �˳�                              �U" << endl;

    }

    cout << "�U                                               �U" << endl;
    cout << "�^===============================================�a" << endl;
    //When account system upload, print account information

    cout << "�����빦����ţ�";
    while(1)
    {
        num = getch()-48;
        cout << endl;
        if(code==1 && (num>=0 && num<=5 || num==9))
            return num;//Administrator Functions
        if(code==2 && num>=0 && num<=4)
            return num;//User Function
        cout << "���Ҳ����ù��ܣ����������룺";

    }

    return 0;

}
