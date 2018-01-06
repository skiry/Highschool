#include <iostream>

using namespace std;
int cmax,cmax1,n,a,i;
int main()
{cout<<"n=";
cin>>n;
cout<<"a=";
cin>>a;
cmax1=a;
for(i=2;i<=n;i++)
{cout<<"a=";
cin>>a;
if(a>cmax) cmax=a;
    if(a>cmax1&&a<cmax) cmax1=a;

}
   cout<<cmax<<" "<<cmax1;
    return 0;
}
