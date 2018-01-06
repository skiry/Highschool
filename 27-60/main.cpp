#include <iostream>

using namespace std;
int a,b=1,c,s1=1,e=0;
int main()
{cout<<"a>1000 a=";
cin>>a;
while(a)
{c=a%10;
a=a/10;
b=b*10+c;
}
while(b)
{c=b%10;
b=b/10;
if(s1%2!=0)
{if(c%2==0) e=e*10+c;}
s1++;
}
cout<<e;


    return 0;
}
