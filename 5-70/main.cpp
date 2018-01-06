#include <iostream>

using namespace std;
int n,q,x=0,p,c,a;
int main()
{cout<<"n=";
cin>>n;
cout<<"baza=";
cin>>q;
a=n;
p=q;
while(a!=0)
{c=a%10;
a=a/10;
x=x+p*c;
p=p*q;


}
 cout<<"Reprezentarea numarului "<<n<<" din baza "<<q<<" in baza 10 este "<<x;
    return 0;
}
