#include <iostream>

using namespace std;
int n,a,media,nr=0,s=0,i;
int main()
{cout<<"Cate numere vreti sa cititi ? ";
cin>>n;
for (i=1;i<=n;i++)
{
    cout<<"Dati o valoare lui a : ";
    cin>>a;
    if (a%2==0)
        {nr=nr+1;
        s=s+a;
        }
    media=s/nr;
}cout<<"Media aritmetica a numerelor pare este"<<media<<endl;
    return 0;
}
