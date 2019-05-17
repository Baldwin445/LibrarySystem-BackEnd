#include "used.h"

int Identify_UI()
{
    char user[11],password[18];

    cout << "¨X===============================================¨[" << endl;
    cout << "¨U                                               ¨U" << endl;
    cout << "¨U          »¶Ó­Ê¹ÓÃÍ¼Êé¹ÝÐÅÏ¢¹ÜÀíÈí¼þ           ¨U" << endl;
    cout << "¨d-----------------------------------------------¨g" << endl;
    cout << "¨U                                               ¨U" << endl;
    cout << "¨U                                               ¨U" << endl;
    cout << "¨U                                               ¨U" << endl;
    cout << "¨^===============================================¨a" << endl;

    while(1)
    {
        cout << "ÇëÊäÈëÕËºÅ£º";
        cin >> user;
        cout << "ÇëÊäÈëÃÜÂë£º";
        cin >> password;
        if(!strcmp(user,"admin")&&!strcmp(password,"root"))
            return 1;//if administrator, return 1
        else if(!strcmp(user,"user")&&!strcmp(password,"123456"))
            return 2;//if user, return 2
        cout << "ÕËºÅÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£¡" << endl;
    }

    return 0;//neither return 0

}
