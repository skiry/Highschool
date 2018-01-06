#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main()
{
    while(1)
    {
        switch(getch()) {
        case KEY_UP:
            cout << endl << "sarpele se muta in sus" << endl;//key up
            break;
        case KEY_DOWN:
            cout << endl << "Down" << endl;   // key down
            break;
        case KEY_LEFT:
            cout << endl << "Left" << endl;  // key left
            break;
        case KEY_RIGHT:
            cout << endl << "Right" << endl;  // key right
            break;
        //default:
         //   cout << endl << "null" << endl;  // not arrow
            break;
        }

    }

    return 0;
}
