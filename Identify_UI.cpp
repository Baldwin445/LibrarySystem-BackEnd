#include "used.h"

extern int acctsn;
extern account *acct;

int Identify_UI()
{
    char user[12], password[19], word;
    int i;

    cout << "╔===============================================╗" << endl;
    cout << "║                                               ║" << endl;
    cout << "║          欢迎使用图书馆信息管理软件           ║" << endl;
    cout << "╠-----------------------------------------------╣" << endl;
    cout << "║                                               ║" << endl;
    cout << "║                                               ║" << endl;
    cout << "║                              请登录...        ║" << endl;
    cout << "║                              回车注册新用户   ║" << endl;
    cout << "╚===============================================╝" << endl;

    while(1)
    {
        cout << "请输入账号：";
        //get user name
        i=0;
        user[i] = getch();
        if(user[i]==13)
        {
            if(!addUser()) cout << "注册成功！" << endl;
            cout << endl;
            continue;
        }
        else
        {
            if((user[i]>=48 && user[i]<=57) || (user[i]>=65 && user[i]<=90)
               || (user[i]>=97 && user[i]<=122))
                cout << user[i];
            i++;
            do
            {
                user[i] = getch();
                if(user[i]==13)
                {
                    user[i] = '\0';
                    cout << endl;
                    break;
                }
                else
                    if(user[i]==8)
                    {
                        if(i!=0)
                        {
                            cout << char(8) << " " << char(8);
                            i--;
                        }
                    }
                    else
                    {
                        cout << user[i];
                        i++;
                    }
            }
            while(i<11);
            user[i] = '\0';
            if(i==11) cout << endl;
        }


        cout << "请输入密码：";
        //get password
        i=0;
        do
        {
            word = getch();
            if((word>=48 && word<=57) || (word>=65 && word<=90) || (word>=97 && word<=122))
            {
                password[i++] = word;
                cout << "*";
            }
            else
                if(word == 8)
                {
                    if(i!=0)
                    {
                        cout << char(8) << " " << char(8);
                        i--;
                    }
                }
                else
                    if(word == 13)
                    {
                        password[i] = '\0';
                        cout << endl;
                        break;
                    }
        }while(i<18);//hide the password

        password[i] = '\0';
        if(i==18) cout << endl << endl;

        acctsn = findAcctSN(user,password);

        if(acctsn!=-1)
            return acct[acctsn].id;

        if(!strcmp(user,"admin")&&!strcmp(password,"root"))
        {
            acctsn = -1;//special admin account SN
            return 1;//if administrator, return 1
        }

        if(!strcmp(user,"user")&&!strcmp(password,"123456"))
        {
            acctsn = -2;//special user account SN
            return 2;//if user, return 2
        }



        cout << "账号密码错误，请重新输入！" << endl;
    }

    return 0;//neither return 0

}
