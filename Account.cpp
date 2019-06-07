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
        cout << "ע���˺������ﵽ���ޣ�" << endl;
        return -1;
    }

    cout << endl;
    cout << "�������û�����";
    cin >> acct[numAcct].username;
    cout << "�������룺";
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

    if(saveAcct()) cout << "���˻��洢ʧ�ܣ�" << endl;
    cout << endl;

    return 0;
}


int addAdmin()
{
    int i;
    char key[10],pwd[19];
    cout << endl << "������������룺";
    cin >> key;

    if(strcmp(key,"0204"))
    {
        cout << "�����������" << endl;
        return -1;
    }
    cout << endl;
    cout << "�����¹���Ա�û�����";
    cin >> acct[numAcct].username;
    cout << "�������룺";
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

    if(saveAcct()) cout << "���˻��洢ʧ�ܣ�" << endl;
    cout << "��ӳɹ���" << endl;


    return 0;
}


int saveAcct()
{
    FILE *fp;
    char fname[30];

    if(numAcct == 0)
    {
        cout << "�޼�¼�洢��";
        return -1;
    }
    strcpy(fname,"account.txt");
    if((fp=fopen(fname,"wb"))==NULL)
    {
        cout << "�����ļ�ʧ�ܣ�" << endl;
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
        cout << "�޷����ļ���" << endl;
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
    cout << setw(6) << "���";
    cout << setw(10) << "Ȩ��";
    cout << setw(15) << "�û���";
    cout << setw(20) << "����";
    cout << endl;
    for(int i=0;i<numAcct;i++)
    {
        cout << setw(6) << i+1;
        if(acct[i].id==1)
            cout << setw(10) << "����Ա";
        else
            cout << setw(10) << "�û�";
        cout << setw(15) << acct[i].username;
        cout << setw(20) << acct[i].userpwd;
        cout << endl;
    }
    cout << endl;
    return;
}
