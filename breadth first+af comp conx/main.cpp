#include <fstream>
///PROGRAM PENTRU AFISARE COMPONENTE CONEXE
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,u=1,n,p,m,x,y,a[100][100],coada[100],viz[100],nr,pp,el,j;
void parc(int p1)
{
    for(int i=1;i<=n;i++)
        if(a[coada[p1]][i]&&viz[i]==0)
            u++, coada[u]=i, viz[i]++;
    if(p1<=u) parc(p1+1);

}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y, a[x][y]=1, a[y][x]=1;
    i=p=1;
    do
        {
            u=p;
    pp=i;
    nr++;
    viz[pp]=nr;
    coada[p]=pp;
    while(p<=u)
    {
        el=coada[p];
        for(j=1;j<=n;j++)
            if(a[el][j]&&!viz[j])
        {
            u++;
            coada[u]=j;
            viz[j]=nr;
        }
        p++;
    }
        i=1;
        while(i<=n&&viz[i]) i++;

        }
while(i<=n);
//for(i=1;i<=n;i++) g<<viz[i]<<" ";
for(i=1;i<=nr;i++)
{for(j=1;j<=n;j++) if(viz[j]==i) g<<j<<" ";g<<endl;}
    return 0;
}
/**
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,u=1,n,p1,m,x,y,a[100][100],coada[100],viz[100];
void parc(int p1)
{
    for(int i=1;i<=n;i++)
        if(a[coada[p1]][i]&&viz[i]==0)
            u++, coada[u]=i, viz[i]++;
    if(p1<=u) parc(p1+1);

}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y, a[x][y]=1, a[y][x]=1;
    for(i=1;i<=n;i++)
    {
    for(int j=1;j<=n;j++) viz[j]=0,coada[j]=0;

    viz[i]=1;
    coada[1]=i;
    u=1;
    parc(i);
    for(int j=1;j<=u;j++) g<<coada[j]<<" ";g<<endl;
    }
    return 0;
}
*/
