#include <iostream>

using namespace std;
int n,q,x=0,p,c,a,p1;
int main()
{cout<<"n=";
cin>>n;
cout<<"baza=";
cin>>q;
cout<<"baza in care vreti sa schimbati=";
cin>>p1;
a=n;
p=q;
while(a!=0)
{c=a%p1;
a=a/p1;
x=x+p*c;
p=p*q;


}
 cout<<"Reprezentarea numarului "<<n<<" din baza "<<q<<" in baza "<<p1<<" este "<<x;
    return 0;
}
