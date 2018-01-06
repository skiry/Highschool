#include <iostream>

using namespace std;
int i,a,pi,ip,c,ogl,p,ogli,ci;
int main()
{for (i=10;i<=99;i++)
cin>>a;

while (a!=0)
{ogl=0;
c=a%10;
a=a/10;
ogl=ogl*10+c;
}
p=a*a;
pi=ogl*ogl;
while (p!=0)
{
    ogli=0;
    ci=p%10;
    p=p/10;
    ogli=ogli*10+ci;
}
if(ip==pi) cout<<a<<endl;

    return 0;
}
