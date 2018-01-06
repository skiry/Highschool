#include <fstream>

using namespace std;
ifstream f("tv.in");
ofstream g("tv.out");
int n,m,c,a[6000][6000],i,j,pus[1000],fin[1000],v,val,rez[1000],rez1=1,rezultat;
long long cost[6000],cmax;
int main()
{
    f>>n>>m>>c;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            f>>a[i][j],pus[a[i][j]]=1;
    for(i=2;i<c;i++)
        f>>cost[i];
    pus[1]=0;
    pus[c]=0;
    v=0;
    for(i=1;i<=c;i++)
        if(pus[i])
            v++,fin[v]=i;
    for(i=1;i<=v;i++) pus[fin[i]]=1;
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
            if(a[i][j]!=1&&a[i][j]!=c)
        {
            cmax=9999999;
            val=0;
            int ok=0;
            if(a[i-1][j]&&a[i-1][j]!=a[i][j]) pus[a[i-1][j]]=0;
            if(a[i+1][j]&&a[i+1][j]!=a[i][j]) pus[a[i+1][j]]=0;
            if(a[i][j-1]&&a[i][j-1]!=a[i][j]) pus[a[i][j-1]]=0;
            if(a[i][j+1]&&a[i][j+1]!=a[i][j]) pus[a[i][j+1]]=0;
            for(int k=1;k<=v;k++) if(pus[fin[k]]&&cost[fin[k]]<=cmax) cmax=cost[fin[k]],val=fin[k];

            for(int q=1;q<=rez1;q++) if(rez[q]==val) ok=1;
            if(!ok) rez[rez1]=val,rez1++;
            for(int q=1;q<=v;q++) pus[fin[q]]=1;
        }
      for(i=1;i<=rez1;i++) rezultat+=cost[rez[i]];
      g<<rezultat;
    return 0;
}
