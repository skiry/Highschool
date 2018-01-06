#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,i,j,a[100][100],ppl,ppc,pfl,pfc,inc,sf,ok;
struct punct{int l,c;} p,c[1000];
int dl[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) f>>a[i][j];
    f>>ppl>>ppc>>pfl>>pfc;
for(i=0;i<=n+1;i++) a[i][0]=a[n+1][i]=-1;
for(i=0;i<=m+1;i++) a[0][i]=a[i][m+1]=-1;
inc=0;
sf=0;
c[1].l=ppl;
c[1].c=ppc;
inc=1;
sf=1;
a[ppl][ppc]=1;ok=1;
while(inc<=sf&&ok==1)
{p=c[inc];inc++;
for(i=0;i<4;i++)
if(a[p.l+dl[i]][p.c+dc[i]]==0) {a[p.l+dl[i]][p.c+dc[i]]=1+a[p.l][p.c];
sf++;
c[sf].l=p.l+dl[i];
c[sf].c=p.c+dc[i];
if(c[sf].l==pfl&&c[sf].c==pfc) ok=0;
}
}
for(i=0;i<=n+1;i++)
{for(j=0;j<=m+1;j++)
if(a[i][j]==-1) g<<a[i][j]<<" ";
else g<<" "<<a[i][j]<<" ";g<<endl;}
    return 0;
}
