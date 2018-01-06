#include <iostream>

using namespace std;
int a=2,n,s=2;
int main()
{cout<<"n=";
cin>>n;
cout<<"2 ";
while(s<n)
{a=a+2;
s=s+a;
if(s<n) cout<<a<<" ";
}

    return 0;
}
