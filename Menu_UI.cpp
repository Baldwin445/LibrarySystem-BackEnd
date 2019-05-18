#include "used.h"

int Menu_UI(int code)
{
    int num;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "╔===============================================╗" << endl;
    cout << "║                                               ║" << endl;
    cout << "║          成功进入图书馆信息管理软件           ║" << endl;
    cout << "╠-----------------------------------------------╣" << endl;
    cout << "║                                               ║" << endl;
    if(code==1)
    {
        cout << "║          欢迎管理员 Admin！                   ║" << endl;
        cout << "║                                               ║" << endl;
        cout << "║          1. 添加书目                          ║" << endl;
        cout << "║          2. 修改书目                          ║" << endl;
        cout << "║          3. 查看书库信息                      ║" << endl;
        cout << "║          0. 退出                              ║" << endl;

    }
    else
    {
        cout << "║          欢迎用户 User！                      ║" << endl;
        cout << "║                                               ║" << endl;
        cout << "║          1. 借书                              ║" << endl;
        cout << "║          2. 还书                              ║" << endl;
        cout << "║          3. 查找书籍                          ║" << endl;
        cout << "║          0. 退出                              ║" << endl;

    }

    cout << "║                                               ║" << endl;
    cout << "╚===============================================╝" << endl;
    //When account system upload, print account information

    cout << "请输入功能序号：";
    while(1)
    {
        cin >> num;
        if(code==1 && num>=0 && num<=3)
            return num;//Administrator Functions
        if(code==2 && num>=0 && num<=3)
            return num;//User Function
        cout << "查找不到该功能，请重新输入：";

    }

    return 0;

}
