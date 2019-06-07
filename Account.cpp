#include "used.h"

extern int acctsn;
extern int numAcct;
extern int acctSize;
extern struct account *acct;

int addUser()
{
    int i;
    char pwd[19];
    if(numAcct > MAXNUM)
    {
        cout << "注册账号数量达到上限！" << endl;
        return -1;
    }

    cout << endl;
    cout << "输入新用户名：";
    cin >> acct[numAcct].username;
    cout << "输入密码：";
    //get the password
    i=0;
    while(i<19)
    {
        char ch = getch();
        if((ch>=48 && ch<=57) || (ch>=65 && ch<=90) || (ch>=97 && ch<=122))
        {
            pwd[i] = ch;
            cout << "*";
            i++;
        }
        else
            if(ch == 8)
            {
                if(i!=0)
                {
                    cout << char(8) << " " << char(8);
                    i--;
                }
            }
            else
                if(ch==13)
                {
                    pwd[i] = '\0';
                    cout << endl;
                    break;
                }
        if(i==18)
        {
            pwd[i] = '\0';
            cout << endl;
            break;
        }
    }
    strcpy(acct[numAcct].userpwd, pwd);
    acct[numAcct].id = 2;
    numAcct++;

    if(saveAcct()) cout << "新账户存储失败！" << endl;
    cout << endl;

    return 0;
}


int addAdmin()
{
    int i;
    char key[10],pwd[19];
    cout << endl << "请输入管理密码：";
    cin >> key;

    if(strcmp(key,"0204"))
    {
        cout << "管理密码错误！" << endl;
        return -1;
    }
    cout << endl;
    cout << "输入新管理员用户名：";
    cin >> acct[numAcct].username;
    cout << "输入密码：";
    //get the password
    i=0;
    while(i<19)
    {
        char ch = getch();
        if((ch>=48 && ch<=57) || (ch>=65 && ch<=90) || (ch>=97 && ch<=122))
        {
            pwd[i] = ch;
            cout << "*";
            i++;
        }
        else
            if(ch == 8)
            {
                if(i!=0)
                {
                    cout << char(8) << " " << char(8);
                    i--;
                }
            }
            else
                if(ch==13)
                {
                    pwd[i] = '\0';
                    cout << endl;
                    break;
                }
        if(i==18)
        {
            pwd[i] = '\0';
            cout << endl;
            break;
        }
    }
    strcpy(acct[numAcct].userpwd, pwd);
    acct[numAcct].id = 1;
    numAcct++;

    if(saveAcct()) cout << "新账户存储失败！" << endl;
    cout << "添加成功！" << endl;


    return 0;
}


int saveAcct()
{
    FILE *fp;
    char fname[30];

    if(numAcct == 0)
    {
        cout << "无记录存储！";
        return -1;
    }
    strcpy(fname,"account.txt");
    if((fp=fopen(fname,"wb"))==NULL)
    {
        cout << "存入文件失败！" << endl;
        return -1;
    }

    fwrite(acct,sizeof(account)*numAcct,1,fp);
    //SetFileAttributes(fname, FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_SYSTEM);
    fclose(fp);

    return 0;
}


int loadAcct()
{
    FILE *fp;
    char fname[30];

    strcpy(fname,"account.txt");
    if((fp=fopen(fname,"ab+"))==NULL)
    {
        cout << "无法打开文件！" << endl;
        return -1;
    }

    while(!feof(fp))
    {
        //add the space
        if(numAcct >= acctSize)
        {
            acct = (account*)realloc(acct,sizeof(account)*(numAcct+INCR_SIZE));
            if(acct == NULL)
            {
                cout << "Memory Failed!" << endl;
                return -1;
            }
            acctSize += INCR_SIZE;
        }

        if(fread(&acct[numAcct],sizeof(account),1,fp) != 1) break;
        numAcct++;
    }
    fclose(fp);

    return 0;
}


int findAcctSN(char *name, char* pwd)
{
    for(int i=0;i<numAcct;i++)
    {
        if(!strcmp(name,acct[i].username) && !strcmp(pwd,acct[i].userpwd))
            return i;
    }
    return -1;//not found: return -1
}


void showAcct()
{
    cout.setf(ios::left);// set align left
    cout << endl;
    cout << setw(6) << "序号";
    cout << setw(10) << "权限";
    cout << setw(15) << "用户名";
    cout << setw(20) << "密码";
    cout << endl;
    for(int i=0;i<numAcct;i++)
    {
        cout << setw(6) << i+1;
        if(acct[i].id==1)
            cout << setw(10) << "管理员";
        else
            cout << setw(10) << "用户";
        cout << setw(15) << acct[i].username;
        cout << setw(20) << acct[i].userpwd;
        cout << endl;
    }
    cout << endl;
    return;
}
