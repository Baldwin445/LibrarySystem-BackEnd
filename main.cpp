#include "used.h"

//constants
int numBook = MINNUM; //amount of Books
int arraySize = INITIAL_SIZE; //size of Array
struct book *books = NULL; //array of books


int main()
{
    char func=0;//function code
    int code=0, flag=1;
    books = (book*)malloc(sizeof(book)*INITIAL_SIZE);
    //code 0 for null, 1 for administrator, 2 for user
    //flag: situation of program

    code = Identify_UI();
    if(code!=1 || code!=2)
    {
        cout << "不存在此用户" << endl;
        exit(0);
    }//check login user for Second time for Account System

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
                Info_book(code);
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

            //exit
            default:
                cout << "感谢使用，再见！" << endl;
                exit(0);

        }

    }


    return 0;
}
