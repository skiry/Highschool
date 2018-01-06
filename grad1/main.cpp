#include <fstream>

using namespace std;
ifstream f("grad1.in");
ofstream g("grad1.out");
int n,k,a[10006],b[10007],i,nr,cmax=0,j,poz;
int main()
{f>>n>>k;
for(i=1;i<=n;i++)
    f>>a[i];
for(i=1;i<=n;i++)
    b[i]=a[i];

for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    if(b[i]>b[j]) swap(b[i],b[j]);
for(i=1;i<=n;i++)
    if(b[i]==a[i]) nr++;
g<<nr;
g<<'\n';
nr=0;
for(j=1;j<=n-k+1;j++)
{for(i=j;i<=k+j-1;i++)
    if(b[i]==a[i]) nr++;
if(nr>cmax) {cmax=nr;poz=j;}
nr=0;
}

g<<poz<<" "<<cmax;
    return 0;
}
