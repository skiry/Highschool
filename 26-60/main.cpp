#include <iostream>

using namespace std;
int a,b,c,d,ogl=1,e;
int main()
{cout<<"a=";
cin>>a;
e=a;
b=a;
c=a%10;
a=a/10;
d=c;
while(a)
{c=a%10;
a=a/10;
ogl=ogl*10+c;
}
    c=ogl%10;
    d=d+c*10;
    cout<<"Cel mai mic multiplu par al numarului format din prima si ultima cifra a lui "<<e<<" este "<<d*2;
    return 0;
}
