#include <iostream>

using namespace std;
int n,i,a,OK,d;
int main()
{cout<<"Cate numere vreti sa cititi ? ";
cin>>n;
for(i=1;i<=n;i++)
{
    cout<<"Dati o valoare numarului : ";
    cin>>a;
    OK=1;
    for(d=2;d<=a/2&&OK==1;d++)
     {if(a%d==0) OK=0;}

if(OK==1) cout<<a<<" Este numar prim"<<endl;

}

    return 0;
}
