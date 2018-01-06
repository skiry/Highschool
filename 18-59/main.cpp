#include <iostream>

using namespace std;
int n,i,m=0,a;
float x;
int main()
{cout<<"n=";
cin>>n;
for(i=1;i<=n;i++)
{cout<<"a=";
cin>>a;
m=m+(1/a);

}
x=n/m;
    cout<<"Media armonica a numerelor este"<<x;
    return 0;
}
