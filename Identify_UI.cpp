#include "used.h"

int Identify_UI()
{
    char user[11], password[18], word;
    int i;

    cout << "¨X===============================================¨[" << endl;
    cout << "¨U                                               ¨U" << endl;
    cout << "¨U          »¶Ó­Ê¹ÓÃÍ¼Êé¹ÝÐÅÏ¢¹ÜÀíÈí¼þ           ¨U" << endl;
    cout << "¨d-----------------------------------------------¨g" << endl;
    cout << "¨U                                               ¨U" << endl;
    cout << "¨U                                               ¨U" << endl;
    cout << "¨U                           ÇëµÇÂ¼...           ¨U" << endl;
    cout << "¨^===============================================¨a" << endl;

    while(1)
    {
        cout << "ÇëÊäÈëÕËºÅ£º";
        cin >> user;
        cout << "ÇëÊäÈëÃÜÂë£º";

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
                        cout << endl;
                        break;
                    }
                    else continue;
        }while(i<18);//hide the password

        if(i==18) cout << endl << endl;

        if(!strcmp(user,"admin")&&!strcmp(password,"root"))
            return 1;//if administrator, return 1
        else if(!strcmp(user,"user")&&!strcmp(password,"123456"))
            return 2;//if user, return 2
        cout << "ÕËºÅÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£¡" << endl;
    }

    return 0;//neither return 0

}
