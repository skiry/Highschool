#include <fstream>
#include <math.h>
using namespace std;
ifstream f("meteo.in");
ofstream g("meteo.out");
int a[100],i,n,p,nr,s,j,mp,mn,k,b[100],ok;

int main()
{f>>n>>p>>nr;
for(i=1;i<=nr;i++) f>>a[i];
for(i=1;i<nr;i++)
    for(j=i+1;j<=nr;j++) if(a[i]>a[j]) swap (a[i],a[j]);
    for(i=1;i<=nr;i++)
    {
        ok=1;
        for(j=1;j<=k&&ok==1;j++)
        if(a[i]==a[j]) ok=0;
        if(ok==1) {k++;b[k]=a[i];}
    }


for(i=1;i<=n;i++)
    s=s+b[i];
mn=s/n;
s=0;
for(i=nr;i>k-p;i--)
    s=s+b[i];
mp=s/p;
g<<floor(mn)<<" "<<floor(mp);

    return 0;
}
