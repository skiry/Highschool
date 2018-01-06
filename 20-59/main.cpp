#include <iostream>

using namespace std;
int a,d,s=0,ok,i;
int main()
{cout<<"a=";
cin>>a;
for(i=a-1;s!=2;i--)
{ok=1;
for(d=2;d<=i/2&&ok==1;d++)
if(i%d==0) ok=0;
if(ok==1) {s++;
cout<<i<<endl;
}
}
    return 0;
}
