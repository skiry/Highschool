#include <iostream>

using namespace std;
int a[100],n,nr,i;
int main()
{cout<<"Nr de elemente = ";
cin>>n;
for(i=1;i<=n;i++) {cout<<"a["<<i<<"]=";
cin>>a[i];}
for(i=1;i<=n-1;i++) if(a[i]%a[n]==0) nr++;
cout<<"Sunt "<<nr<<" numere ce se divid cu "<<a[n];

    return 0;
}
