#include <iostream>

using namespace std;
int n,i,p=1,a,x,b;
int main()
{cout<<"Cate numere vreti sa cititi ? ";
cin >>n;
for(i=1;i<=n;i++)
{cout<<"Dati o valoare numarului : ";
cin>>a;
    x=n;
    b=a;
    while(b!=x)
    if(b>x) b=b-x;
    else x=x-b;

    if(b==1)  p=p*a;


}
    cout<<"Produsul numerelor prime cu "<<n<<" este "<<p;
    return 0;
}
