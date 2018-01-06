#include <bits/stdc++.h>

using namespace std;

/**
int rapidConversions(fromBase,toBase,numberToConvert)
{
    char result[65];
    int index = 0,numberLoop=0,resIndex = 0;
    for ( int i = 0; i < len(numberToConvert); i++ )
        if ( numberToConvert[i] == "." || numberToConvert[i] == "," )
            index = i;

    if ( fromBase == 4 ) numberLoop = 2;
    else if ( fromBase == 8 ) numberLoop = 3;
    else if ( fromBase == 16 ) numberLoop = 4;
    resIndex = index * numberLoop
    if ( fromBase != 2 )
    {
        for ( int i = index; i >= 0; i--)
        {
            for ( int j = 0)
        }
    }
}
*/
void menu()
{
    cout << "1. Addition in base p" << endl;
    cout << "2. Subtraction in base p" << endl;
    cout << "3. Multiplication in base p" << endl;
    cout << "4. Division in base p" << endl;
    cout << "5. Conversion between 2 bases" << endl;
    cout << "6. Exit" << endl << endl;
}
int powerOf2(int a)
{
    if ( a == 2 || a == 4 || a == 8 || a== 16)
        return 1;
    return 0;
}
int num(int nr)
{
    if (nr < 10) return nr;
    else if (nr == 'a');
}
int addition(char a[100],char b[100], int base)
{
    int result = 0,partial,carry;
    cout<<strlen(a)<<" "<<strlen(b);
    /*while ( a > 0 && b > 0)
    {
        partial = num(a%10) + num(b%10);
        //carry = partial /
    }*/
    return 9;
}
int choose,fromBase,toBase;
char numberToConvert[100],number1[100],number2[100];
int main()
{
    int stop = 1;
    while ( stop )
    {
        choose = stop = 0;
        menu();
        cin >> choose;
        if ( choose >= 1 && choose <= 6 )
        {
            if ( choose == 6 ) stop = 0;
            /**
            else if ( choose == 5 )
            {
                cout << "From base : ";
                cin>>fromBase;
                cout << "To base : ";
                cin>>toBase;
                cout << "Number : ";
                cin.getline(numberToConvert,33);
                if ( powerOf2(fromBase) && powerOf2(toBase) )
                {
                    rapidConversions(fromBase,toBase,numberToConvert);
                }
                if ( fromBase < toBase )
                    substitution(fromBase,toBase,numberToconvert);
            }
            */
            else if ( choose == 1)
            {
                /// the first option : addition in an arbitrary base

                cout << "Base ";
                cin >> fromBase;
                cout << "Number 1 : " << endl;
                cin.get(number1, 10);
                cout << "Number 2 : ";
                cin.get(number2, 10);
                addition(number1,number2,fromBase);
                stop = 1;
            }
        }
        else
        {
            cout << "Please choose a valid option" << endl;
        }
    }
    return 0;
}
