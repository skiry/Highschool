#include <iostream>

using namespace std;
int n,c,s=1;
int main()
{cout<<"! n>100 ! "<<endl;
cout<<"n=";
cin>>n;
while(n)
{c=n%10;
n=n/10;
if(s%2!=0) cout<<c<<" ";
s++;
}

    return 0;
}
