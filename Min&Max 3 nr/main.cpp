#include <iostream>

using namespace std;
int a,b,c;
int main()
{cout<<"a= "; cin>>a;
cout<<"b= "; cin>>b;
cout<<"c= "; cin>>c;
if (a>b&&a>c) cout<<"Maximul : "<<a<<endl;
    else cout<<"Minimul : "<<a<<endl;
    if (b>c&&b>a) cout<<"Maximul : "<<b<<endl;
    else cout<<"Minimul : "<<b<<endl;
    if (c>b&&c>a) cout<<"Maximul : "<<c<<endl;
    else cout<<"Minimul : "<<c<<endl;
    return 0;
}
