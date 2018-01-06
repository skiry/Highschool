#include <iostream>

using namespace std;
int n,a,s=0,p=1,i;
int main()
{cout<<"Cate nr vreti sa cititi : ";
cin>>n;
for (i=1;i<=n;i++)
{
    cout<<"Dati o valoare lui a : ";
    cin>>a;
    if (a%2==0) s=s+a;
    if (a%2==1) p=p*a;
}
    cout << "Suma nr. pare este " <<s<<" Iar produsul nr. impare este "<<p<< endl;
    return 0;
}
