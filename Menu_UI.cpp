#include "used.h"

int Menu_UI(int code)
{
    int num;

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
        cout << "�U          ��ӭ����Ա Admin��                   �U" << endl;
        cout << "�U                                               �U" << endl;
        cout << "�U          1. �����Ŀ                          �U" << endl;
        cout << "�U          2. �޸���Ŀ                          �U" << endl;
        cout << "�U          3. �鿴�����Ϣ                      �U" << endl;
        cout << "�U          0. �˳�                              �U" << endl;

    }
    else
    {
        cout << "�U          ��ӭ�û� User��                      �U" << endl;
        cout << "�U                                               �U" << endl;
        cout << "�U          1. ����                              �U" << endl;
        cout << "�U          2. ����                              �U" << endl;
        cout << "�U          3. �����鼮                          �U" << endl;
        cout << "�U          0. �˳�                              �U" << endl;

    }

    cout << "�U                                               �U" << endl;
    cout << "�^===============================================�a" << endl;
    //When account system upload, print account information

    cout << "�����빦����ţ�";
    while(1)
    {
        cin >> num;
        if(code==1 && num>=0 && num<=3)
            return num;//Administrator Functions
        if(code==2 && num>=0 && num<=3)
            return num;//User Function
        cout << "���Ҳ����ù��ܣ����������룺";

    }

    return 0;

}
