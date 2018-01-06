#include <iostream>

using namespace std;
int n,q,x=0,p,c,a,nr=0,c1;
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
while(x!=0)
{c1=x%10;
x=x/10;
nr++;

}
 cout<<"Numarul "<<n<<" din baza "<<q<<" in baza 10 are "<<nr<<" cifre";
    return 0;
}
