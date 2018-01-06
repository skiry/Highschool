#include <iostream>

using namespace std;
int a,b,c;
int main()
{cout<<"a= "; cin>>a;
cout<<"b= "; cin>>b;
    c=b;
    b=a;
    a=c;
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}
