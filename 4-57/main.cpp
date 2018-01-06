#include <iostream>

using namespace std;
int n,a,nr=0,d,p;
int main()
{cout<<"Dati o valoare numarului : ";
cin>>n;
cout<<"Dati o valoare lui p : ";
cin>>p;
for(d=n/2;nr!=p&&d!=1;d--)
if(n%d==0) {nr=nr+1;
cout<<"Unul din ultimii divizori proprii ai lui "<<n<<" este "<<d<<endl; }


    if(nr==0) cout<<"Numarul "<<n<<" este prim ";
    return 0;
}
