#include <iostream>

using namespace std;
int n,s=0,p=1,OK=1,d1,d;
int main()
{cout<<"n=";
cin>>n;
for(d=2;d<=n/2;d++)
{for(d1=2;d1<=d/2&&OK==1;d++)
if(n%d==0) OK=0;
if(OK) {s=s+d;
p=p*d;}
OK=1;}
    cout<<s<<" "<<p;
    return 0;
}
