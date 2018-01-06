#include <iostream>

using namespace std;
int n,a,cmax,s=0,i;
int main()
{cout<<"Cate note?";
cin>>n;
for(i=1;i<=n;i++)
{cout<<"a=";
cin>>a;

if(a>cmax) {cmax=a;
s=0;}

if(cmax==a) s++;}
    cout<<"Nota "<<cmax<<" obtinuta la test de "<<s<<" elevi !";
    return 0;
}
