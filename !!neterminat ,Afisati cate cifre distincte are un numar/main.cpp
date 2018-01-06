#include <iostream>

using namespace std;
int a,c,c1,nr;
int main()
{cout<<"a=";
cin>>a;
c1=a%10;
a=a/10;
while(a)
{c=a%10;
a=a/10;
if(c!=c1) nr++;
c1=c;
}
    cout<<"Numarul are "<<nr<<" cifre distincte !";
    return 0;
}
