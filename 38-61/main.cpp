#include <iostream>

using namespace std;
int s,a,n,s1,b,c=1;
int main()
{cout<<"a=";
cin>>a;
cout<<"a=";
cin>>b;
s=a+b;
s1=s;
while(c!=s)
{cout<<"a=";
cin>>c;
s=b+c;
b=c;
s1=s1+c;
}
cout<<s1;
    return 0;
}
