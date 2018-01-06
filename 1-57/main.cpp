#include <iostream>

using namespace std;
int n,i,r=2,c;
int main()
{cout<<"Cate numere vreti sa cititi ? ";
cin>>n;
for (i=1;i<=n;i++)
{
    c=c+2;
    r=r*c;

}
    cout<<"Produsul primelor "<<n<<" numere pare este "<<r/2<<endl;
    return 0;
}
