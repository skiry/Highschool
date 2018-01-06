#include <fstream>

using namespace std;
ifstream f("gardul.in");
ofstream g("gardul.out");
int n,i,a[100005],nrr,nra,nrv,p,q;
int main()
{f>>n>>p>>q;
for(i=1;i<=n;i++)
a[i]=i;
for(i=1;i<=n;i++)
{if(a[i]%p==0&&a[i]%q!=0) a[i]=-1;
else
if(a[i]%p!=0&&a[i]%q==0) a[i]=-2;
else
if(a[i]%p==0&&a[i]%p==0) a[i]=-3;
if(a[i]==-1) nrr++;
else if(a[i]==-2) nra++;
else if(a[i]==-3) nrv++;}
g<<n-nra-nrv-nrr;
g<<endl;
g<<nrr<<endl;
g<<nra<<endl;
g<<nrv<<endl;

    return 0;
}
