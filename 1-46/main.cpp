#include <iostream>

using namespace std;
int m,n,r=1,i;
int main()
{cout<<"m=";
cin>>m;
cout<<"n=";
cin>>n;
for (i=1;i<=m;i++)
{
    r=r*n;
}
    cout<<" Numarul "<<n<<" la puterea a "<<m<<"a este egal cu "<<r<<endl;
    return 0;
}
