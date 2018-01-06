#include <fstream>

using namespace std;
ifstream f("betasah.in");
ofstream g("betasah.out");
int n,i,a[100][100],ds,k,j,nr,cmax;
struct dame{int l,c;} d[100];

struct obst{int l,c;} o[100];

int main()
{f>>n>>ds>>k;
for(i=1;i<=ds;i++) {f>>d[i].l>>d[i].c;a[d[i].l][d[i].c]=1;}
for(i=1;i<=k;i++) {f>>o[i].l>>o[i].c;a[o[i].l][o[i].c]=-1;}

for(i=1;i<=n;i++){nr=0;
for(j=1;j<=n;j++)
    if(i>=j&&a[i][j]==0) nr++;
    if(nr>cmax) cmax=nr;
}
g<<cmax;
for(i=1;i<=n;i++)
{if(a[d[i].l-1][d[i].c]==0)
{a[d[i].l-1][d[i].c]=3;
    if(a[d[i].l-2][d[i].c]==0)
   {
       a[d[i].l-2][d[i].c]=3;
       if(a[d[i].l-3][d[i].c]==0) a[d[i].l-3][d[i].c]=3;}}
if(a[d[i].l+1][d[i].c]==0)
{a[d[i].l+1][d[i].c]=3;
    if(a[d[i].l+2][d[i].c]==0)
   {
       a[d[i].l+2][d[i].c]=3;
       if(a[d[i].l+3][d[i].c]==0) a[d[i].l+3][d[i].c]=3;}}
if(a[d[i].l][d[i].c-1]==0)
{a[d[i].l][d[i].c-1]=3;
    if(a[d[i].l][d[i].c-2]==0)
    {a[d[i].l][d[i].c-2]=3;
    if(a[d[i].l][d[i].c-3]==0) a[d[i].l][d[i].c-3]=3;}

    }
   if(a[d[i].l][d[i].c+1]==0)
{a[d[i].l][d[i].c+1]=3;
    if(a[d[i].l][d[i].c+2]==0)
    {a[d[i].l][d[i].c+2]=3;
    if(a[d[i].l][d[i].c+3]==0) a[d[i].l][d[i].c+3]=3;}

    }
if(a[d[i].l-1][d[i].c-1]==0)
    {a[d[i].l-1][d[i].c-1]=3;
    if(a[d[i].l-2][d[i].c-2]==0)
    {
        a[d[i].l-2][d[i].c-2]=3;
        if(a[d[i].l-3][d[i].c-3]) a[d[i].l-3][d[i].c-3]=3;
}
    }
if(a[d[i].l+1][d[i].c+1]==0)
    {a[d[i].l+1][d[i].c+1]=3;
    if(a[d[i].l+2][d[i].c+2]==0)
    {
        a[d[i].l+2][d[i].c+2]=3;
        if(a[d[i].l+3][d[i].c+3]) a[d[i].l+3][d[i].c+3]=3;
}
    }
 if(a[d[i].l-1][d[i].c+1]==0)
    {a[d[i].l-1][d[i].c+1]=3;
    if(a[d[i].l-2][d[i].c+2]==0)
    {
        a[d[i].l-2][d[i].c+2]=3;
        if(a[d[i].l-3][d[i].c+3]) a[d[i].l-3][d[i].c+3]=3;
}
    }
    if(a[d[i].l+1][d[i].c-1]==0)
    {a[d[i].l+1][d[i].c-1]=3;
    if(a[d[i].l+2][d[i].c-2]==0)
    {
        a[d[i].l+2][d[i].c-2]=3;
        if(a[d[i].l+3][d[i].c-3]) a[d[i].l+3][d[i].c-3]=3;
}
    }


}
nr=0;
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
    if(i>=j) g<<a[i][j]<<" ";g<<endl;}
g<<nr;
    return 0;
}
