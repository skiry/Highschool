#include <iostream>

using namespace std;
int n,a,i,nr=0;
int main()
{cout<<"Cate numere vreti sa scrieti ? ";
cin>>n;
for(i=1;i<=n;i++)
{
    cout<<"Dati o valoare lui a : ";
    cin>>a;
    if (a<0) nr=nr+1;
    }
    cout << nr << "Numere sunt negative " <<endl;
    return 0;
}
