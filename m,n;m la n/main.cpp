#include <iostream>

using namespace std;
int a,i,b,r=1;
int main()
{cout<<"Dati-i o valoare lui a : ";
cin>>a;
cout<<"Dati-i o valoare lui b : ";
cin>>b;
for(i=1;i<=b;i++)
{
    r=r*a;
}
    cout<<a<<" la puterea a "<<b<<"a este "<<r<<endl;
     return 0;

}
