#include "used.h"

extern int acctsn;
extern account *acct;

int Menu_UI(int code)
{
    int num,length;

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
        if(acctsn == -1)
            cout << "║          欢迎管理员 Admin！                   ║" << endl;
        else
        {
            length = strlen(acct[acctsn].username);
            cout << "║          欢迎管理员 " << acct[acctsn].username << "！";
            length = 24-length;
            while(length--) cout << " ";
            cout << "║" << endl;
        }
        cout << "║                                               ║" << endl;
        cout << "║          1. 添加书目                          ║" << endl;
        cout << "║          2. 修改书目                          ║" << endl;
        cout << "║          3. 查看书库信息                      ║" << endl;
        cout << "║          4. 返回登录界面                      ║" << endl;
        cout << "║          9. 注册新管理员账号                  ║" << endl;
        cout << "║          0. 退出                              ║" << endl;

    }
    else
    {
        if(acctsn == -2)
            cout << "║          欢迎用户 User！                      ║" << endl;
        else
        {
            length = strlen(acct[acctsn].username);
            cout << "║          欢迎用户 " << acct[acctsn].username << "！";
            length = 26-length;
            while(length--) cout << " ";
            cout << "║" << endl;
        }
        cout << "║                                               ║" << endl;
        cout << "║          1. 借书                              ║" << endl;
        cout << "║          2. 还书                              ║" << endl;
        cout << "║          3. 查找书籍                          ║" << endl;
        cout << "║          4. 返回登录界面                      ║" << endl;
        cout << "║          0. 退出                              ║" << endl;

    }

    cout << "║                                               ║" << endl;
    cout << "╚===============================================╝" << endl;
    //When account system upload, print account information

    cout << "请输入功能序号：";
    while(1)
    {
        num = getch()-48;
        cout << endl;
        if(code==1 && (num>=0 && num<=5 || num==9))
            return num;//Administrator Functions
        if(code==2 && num>=0 && num<=4)
            return num;//User Function
        cout << "查找不到该功能，请重新输入：";

    }

    return 0;

}
