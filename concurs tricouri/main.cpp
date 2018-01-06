#include <iostream>

using namespace std;
int a;
int main()
{cout<<"Numarul concurentului : "; cin>>a;
if (a%4==1) cout<<"Concurentul primeste tricou de culoare alba ! "<<endl;
if (a%4==2) cout<<"Concurentul primeste tricou de culoare rosie ! "<<endl;
if (a%4==3) cout<<"Concurentul primeste tricou de culoare albastra ! "<<endl;
if (a%4==0) cout<<"Concurentul primeste tricou de culoare neagra ! "<<endl;


    return 0;
}
