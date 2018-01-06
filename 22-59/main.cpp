#include <iostream>

using namespace std;
int a,c,p=1,p1=1,nr1=0,nr2=0;
int main()
{cout<<"a=";
cin>>a;
while(a!=0)
{c=a%10;
a=a/10;
if(c%2==0) {nr1=nr1+p*c;
p=p*10;}
else if(c%2!=0) {nr2=nr2+p1*c;
p1=p1*10;}

}
    cout<<nr1<<" "<<nr2;

    return 0;
}
