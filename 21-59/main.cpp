#include <iostream>

using namespace std;
int a,c;
int main()
{cout<<"a=";
cin>>a;
while(a!=0)
{c=a%10;
a=a/10;
if(c%2==0) cout<<c<<",";
}

    return 0;
}
