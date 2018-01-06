#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,a[100],r=1,nr,cmin=9999,c,i,j;
int main()
{f>>n;
for(i=1;i<=n;i++){f>>a[i];r*=10;if(a[i]==0) nr++;if(a[i]<cmin&&a[i]) cmin=a[i];}
r/=10;
c=r;
for(i=1;i<=nr+1;i++) c=c/10;
r=r*cmin;
for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++) if(a[i]<a[j]) swap(a[i],a[j]);
for(i=n-nr-1;i>=1;i--) {r=r+(a[i]*c); c=c/10;}
g<<r;
    return 0;
}
