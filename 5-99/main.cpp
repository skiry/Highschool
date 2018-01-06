#include <iostream>

using namespace std;
int a[100],n,i,nr;
int main()
{cout<<"Nr de elemente ";
cin>>n;
for(i=1;i<=n;i++) {cout<<"a["<<i<<"]=";
cin>>a[i];}
for(i=1;i<=n;i++) if(i%2!=0&&a[i]%2==0) nr=nr+a[i];
cout<<"Suma elementelor pare situate pe pozitii impare este "<<nr;

    return 0;
}
