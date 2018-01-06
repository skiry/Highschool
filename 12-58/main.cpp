#include <iostream>

using namespace std;
int a,n,c,p=1,x=0,nr=1,i;
int main()
{cout<<"Cate numere cititi ? ";
cin>>n;
while(nr!=n)
{p=p*10;
nr++;

}
 for(i=1;i<=n;i++)
 {cout<<"Dati o valoare numarului : ";
 cin>>a;
 c=a%10;
 x=x+p*c;
 p=p/10;


 }cout<<x;
    return 0;
}
