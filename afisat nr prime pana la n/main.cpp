#include <iostream>

using namespace std;
int n,a,i,d,OK;
int main()
{cout<<"Dati o valoare lui n : ";
cin>>n;
for(i=2;i<=n;i++)
{a=i;
OK=1;
    for(d=2;d<=a/2&&OK==1;d++)
        if(a%d==0) OK=0;
    if(OK==1) cout<<a<<" ";
}

    return 0;
}
