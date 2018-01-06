#include <iostream>

using namespace std;
int a,x,y,OK,d;
int main()
{cout<<"Ce numar natural PAR , mai MARE decat 2 vreti sa fie descompus in suma de 2 nr. prime ? ";
cin>>a;
x=a-2;
OK=1;
for(d=2;d<=a/2&&OK==1;d++)
{
    if(a%d==0) OK=0;
}

if(OK==1)   y=a-x;
else do {x=x-1;}
    while(x%d!=0);
cout<<a<<" se poate scrie ca suma de "<<x<<"+"<<a-x<<endl;
    return 0;
}
