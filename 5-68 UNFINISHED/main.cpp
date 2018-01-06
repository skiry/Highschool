#include <iostream>

using namespace std;
int n,d,a,i;
int main()
{cout<<"Cate numere vreti sa cititi ? ";
cin>>n;
for(i=1;i<=n;i++)
{
    cout<<"Dati o valoare numarului : ";
    cin>>a;
    for(d=2;d<=a/2;d++)
        if(a%d!=0&&d%2!=0) cout<<"Divizorii pari ai lui a sunt : "<<d;
    else if(a%d!=0) cout<<"Nu are divizori pari !";
}
    return 0;
}
