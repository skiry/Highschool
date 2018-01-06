#include <iostream>

using namespace std;
int a,cmax,c,s;
int main()
{cout<<"a=";
cin>>a;
while(a)
    {c=a%10;
    a=a/10;
    if(c>cmax) {cmax=c;
    s=0;
    }
    if (cmax==c) s++;}
    cout<<"Cea mai mare cifra , "<<cmax<<" apare de "<<s<<" ori.";
    return 0;
}
