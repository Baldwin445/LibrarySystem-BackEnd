#include "used.h"

//constants
int numBook = MINNUM; //amount of Books
int arraySize = INITIAL_SIZE; //size of Book Array
struct book *books = NULL; //array of books

int acctsn = MAXNUM+1;//identity code
int numAcct = MINNUM; //amount of acct
int acctSize = INITIAL_SIZE; //size of Acct Array
struct account *acct = NULL;//array of acct



int main()
{
    char func=0;//function code
    int code, flag, choose;
    books = (book*)malloc(sizeof(book)*INITIAL_SIZE);
    acct = (account*)malloc(sizeof(account)*INITIAL_SIZE);
    //code 0 for null, 1 for administrator, 2 for user
    //flag: situation of program

    if(loadAcct()) cout << "账号导入失败！" << endl;
    if(load_data()) cout << "数据载入失败！" << endl;

    while(1)
    {
        code = Identify_UI();
        if(acctsn == -1) code=1;//for special Admin account
        if(acctsn == -2) code=2;//for special User account
        if(code!=1 && code!=2)
        {
            cout << "不存在此用户" << endl;
            exit(0);
        }//check login user for Second time for Account System
        flag=1;
        while(flag)
        {
            //ASCII: Administrator=A-1 User=a-1
            if(code == 1) func=64;
            else func=96;

            switch(func+Menu_UI(code))
            {
                //Administrator Functions
                case 'A':
                    Add_book();
                    break;
                case 'B':
                    Modify_book();
                    break;
                case 'C':
                    cout << "请选择显示方式：1.表格  2.列表：";
                    choose = getch()-48;
                    cout << endl;
                    if(choose==2) Info_book(code+2);
                    else Info_book(code);
                    break;
                case 'D':
                    flag=0;
                    cout << endl << endl;
                    break;
                case 'I':
                    addAdmin();
                    break;
                case 'E':
                    showAcct();
                    break;

                //User Functions
                case 'a':
                    Borrow_book();
                    break;
                case 'b':
                    Return_book();
                    break;
                case 'c':
                    Search_book();
                    break;
                case 'd':
                    flag=0;
                    cout << endl << endl;
                    break;

                //exit
                default:
                    cout << "感谢使用，再见！" << endl;
                    exit(0);

            }

        }
    }

    return 0;
}
