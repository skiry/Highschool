#include <iostream>

using namespace std;
int a[100],n,i,nr=1,cmax;
int main()
{cout<<"Numarul de numere naturale = ";
cin>>n;
for(i=1;i<=n;i++) {cout<<"a["<<i<<"]=";
cin>>a[i];}
cmax=a[1];
for(i=1;i<=n;i++) if(a[i]>cmax) {nr=1;
cmax=a[i];
}
else if (a[i]==cmax) nr++;
cout<<"Cel mai mare numar este "<<cmax<<" si apare de "<<nr<<" ori !";

    return 0;
}
