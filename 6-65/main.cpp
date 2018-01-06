#include <iostream>

using namespace std;
int n,a=1,b,d,OK,OK1=0,d1,nr=0;
int main()
{cout<<"Cate perechi de numere prime gemene vreti sa se afiseze ? ";
cin>>n;
while(nr<n)
{
a=a+2;
OK=1;
for(d=2;d<=a/2&&OK==1;d++)
if(a%d==0) OK=0;
if(OK==1)
{    b=a+2;
OK1=1;
for(d1=2;d1<=b/2&&OK1==1;d1++)
    if(b%d1==0) OK1=0;
}

   if(OK1==1) {nr=nr+1;
   cout<<a<<" si " <<b<< " ";}
}

    return 0;
}
