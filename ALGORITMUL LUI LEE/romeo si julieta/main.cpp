#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
struct element
{int l,c;
unsigned d;} c[100],x,y;
int a[100][100],n,m,x0,y0,i,j,k,inc,sf,nr;
char s[100][100];
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
{for(j=1;j<=m;j++) f>>s[i][j];}

for(i=1;i<=n;i++){for(j=1;j<=m;j++) g<<s[i][j];g<<endl;}

x0=1;y0=1;
x.l=x0; x.c=y0; x.d=0; a[x0][y0]=0;
c[inc]=x;
while(inc<=sf)
{x=c[inc++];
for(k=0;k<4;k++)
{y.l=x.l+dx[k]; y.c=x.c+dy[k];
    if(a[y.l][y.c]==a[i][j]+1||a[y.l][y.c]==a[i][j]-3)
{
    c[++sf]=y;
}nr++;
}}
for(i=1;i<=n;i++)
{for(j=1;j<=m;j++) g<<a[i][j]<<" ";g<<endl;}


    return 0;
}
