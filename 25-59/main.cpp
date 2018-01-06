#include <iostream>

using namespace std;
int a,b=1,c,s,s1;
int main()
{cout<<"! a>100 !"<<endl;
cout<<"a=";
cin>>a;
while(a)
{c=a%10;
a=a/10;
b=b*10+c;
}
while(s1!=2)
{c=b%10;
b=b/10;
s=s+c;
s1++;
}
cout<<s;

    return 0;
}
