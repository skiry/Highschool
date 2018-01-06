#include <fstream>

using namespace std;
ifstream f("expresie.in");
ofstream g("expresie.out");
int n,a[1005],cmax,cmax1,mx,mx1,poz1,poz2,s,i;
int main()
{f>>n;
for(i=1;i<=n;i++)
   {f>>a[i];s+=a[i];}
for(i=1;i<=n;i++) {
    if(a[i]>=cmax1&&i!=poz1) {cmax1=a[i];poz2=i;}
    s+=a[i];
}g<<s<<" ";
a[n+1]=0;
a[0]=0;
if(a[poz1-1]>=a[poz1+1]) mx=a[poz1-1];
else if(a[poz1-1]<=a[poz1+1]) mx=a[poz1+1];
if(a[poz2-1]>=a[poz2+1]) mx1=a[poz2-1];
else if(a[poz2-1]<=a[poz2+1]) mx1=a[poz2+1];

s=s-cmax-cmax1-mx-mx1;
s=s+(cmax*mx)+(cmax1*mx1);
g<<s;


    return 0;
}
