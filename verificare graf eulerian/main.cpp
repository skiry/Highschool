#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int x,y,a[100][100],i,viz[100],c[100],p1,p,u,n,m,ok,l[100];
void parc(int p1)
{
    while(p<=u)
    {for(i=1;i<=n;i++)
        if(a[c[p]][i]&&!viz[i])
            u++, c[u]=i, viz[i]++;
        p++;}

}
void ciclu(int k)
{
    int m=0,nmax=0;
    g<<k<<" ";
    for(i=1;i<=n;i++)
    {
        if(a[k][i])
            if(l[i]>m)
            m=l[i],nmax=i;
        if(nmax)
        {
            a[k][nmax]=a[nmax][k]=0;
            l[k]--;
            l[nmax]--;
            ciclu(nmax);
        }
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y, a[x][y]=1, a[y][x]=1;
    p=u=1;
    f>>p1;
    viz[p1]=1;
    c[1]=p1;
    parc(1);
    for(i=1;i<=n;i++)
        {
            int s=0;
        for(int j=1;j<=n;j++) s+=a[i][j];
        l[i]=s;
        }
for(i=1;i<=n;i++) if(!viz) ok=1;
if(!ok)
    for(i=1;i<=n;i++)
        if(l[i]%2) ok=1;

if(ok) g<<"Nu este graf eulerian";
else g<<"Este un graf eulerian"<<endl<<"Ciclu eulerian : ",ciclu(1);;
    return 0;
}
