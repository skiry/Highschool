#include <iostream>

using namespace std;
int n,x,y,z,i;
int main()
{cout<<"Dati o valoare numarului  : ";
cin>>n;
for(i=1;i<=n;i++)
{x=i;
y=x+1;
z=n-x-y;
if(x!=0&&y!=0&&z!=0&&x!=y&&x!=z&&y!=z&&y>0&&z>0) cout<<n<<"="<<x<<"+"<<y<<"+"<<z<<endl;
}

    return 0;
}
