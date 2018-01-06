#include <iostream>

using namespace std;
int a,b,c;
int main()
{cout<<"a= "; cin>>a;
cout<<"b= "; cin>>b;
cout<<"c= "; cin>>c;
if (a>9&&b>9&&c>9) cout<<"Trebuie cifre,nu numere !"<<endl;
   else cout<<a<<b<<c<<endl;
   cout<<a<<c<<b<<endl;
   cout<<c<<b<<a<<endl;
   cout<<c<<a<<b<<endl;
   cout<<b<<a<<c<<endl;
    return 0;
}
