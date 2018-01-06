#include <fstream>

using namespace std;
ifstream f("harta2.in");
ofstream g("harta2.out");
int n,k,m,i,j,s,p,s1[100],s2[100],f1[100],f2[100],cmax,x,nr,q,h,a[100][100],ok,ok1;
int main()
{f>>p;
if(p==1)
{f>>n>>m>>k;
for(i=1;i<=k;i++) f>>s1[i]>>s2[i]>>f1[i]>>f2[i];
for(i=1;i<=k;i++) if(((f1[i]-s1[i])==(f2[i]-s2[i]))&&(f1[i]-s1[i])>cmax) cmax=(f1[i]-s1[i])+1;
s=cmax*cmax;
g<<s<<" ";
cmax-=2;
for(i=1;i<=k;i++)
if(((f1[i]-s1[i]+1)<=cmax)&&((f2[i]-s2[i]+1)<=cmax)) nr++;
g<<nr;
}
if(p==2)
{f>>n>>m>>k;
for(i=1;i<=k;i++) f>>s1[i]>>s2[i]>>f1[i]>>f2[i];
for(i=1;i<=k;i++)
{q=s2[i];
for(j=s1[i];j<=f1[i];j++)
    a[j][q]=1;
for(j=s2[i];j<=f2[i];j++)
a[f1[i]][j]=1;
for(j=s1[i];j<=f1[i];j++)
    a[j][f2[i]]=1;
for(j=s2[i];j<=f2[i];j++)
a[s1[i]][j]=1;
}

ok1=0;
for(i=1;i<=n;i++)
{ok=1;
for(j=1;j<=m&&ok;j++)
    if(a[i][j]==1) ok=0;
if(ok&&ok1) for(j=1;j<=m;j++) a[i][j]=-1;
if(ok&&ok1==0) ok1=1;
if(ok==0&&ok1) ok1=0;

}
ok1=0;
for(i=1;i<=m;i++)
{ok=1;
for(j=1;j<=n&&ok;j++)
    if(a[j][i]==1) ok=0;
if(ok&&ok1) for(j=1;j<=n;j++) a[j][i]=-1;
if(ok&&ok1==0) ok1=1;
if(ok==0&&ok1) ok1=0;

}
for(h=1;h<=n;h++)
{ for(j=1;j<=m;j++) if(a[h][j]!=-1) g<<a[h][j]<<" ";g<<endl;}
}
    return 0;
}
