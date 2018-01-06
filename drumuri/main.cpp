#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream f("drumuri5.in");
ofstream g("drumuri5.out");
int n,m,i,j,viz[10000],x,y,d[7001][7001],sol[7001],rez;
struct matrice
{
    int nod,aj;
};
matrice el;
vector <matrice> a[10001];
queue <int> q;
void dijkstra(int nodul)
{
    q.push(nodul);
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(int k=0;k<a[actual].size();k++)
        {
            if(viz[a[actual][k].nod]!=nodul)
                d[nodul][a[actual][k].nod]=1,q.push(a[actual][k].nod);
            viz[a[actual][k].nod]=nodul;
        }
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>y>>el.nod;
        a[y].push_back(el);
    }
    for(i=1;i<=n;i++)
        dijkstra(i);
    for(i=1;i<=n;i++)
    {
        int nr=0;
        for(j=1;j<=n;j++)
       {
           if(i!=j&&(d[i][j]||d[j][i])) nr++;
       }
       if(nr==n-1) sol[++rez]=i;
    }
    g<<rez<<'\n';
    for(i=1;i<=rez;i++) g<<sol[i]<<" ";
    return 0;
}
