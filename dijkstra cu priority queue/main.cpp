#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
int n,m,i,j,z,y,x,dist[50001];
struct nod
{
    int v,l;
};
nod el;
struct cmp
{
    bool operator() (const nod &b, const nod &c)
    {
        return b.l<c.l;
    }
};
vector <nod> a[50001];
priority_queue <nod, vector <nod>, cmp> q;
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>el.v>>el.l;
        a[x].push_back(el);
    }
    for(i=2;i<=n;i++) dist[i]=999999;
    el.v=1;
    el.l=0;
    q.push(el);
    while(q.size())
    {
        nod actual=q.top();
        q.pop();
        for(i=0;i<a[actual.v].size();i++)
        {
            if(dist[actual.v]+a[actual.v][i].l<dist[a[actual.v][i].v])
            {
                dist[a[actual.v][i].v]=dist[actual.v]+a[actual.v][i].l;
                el.v=a[actual.v][i].v;
                q.push(el);
            }
        }
    }
    for(i=2;i<=n;i++)
        if(dist[i]!=999999) g<<dist[i]<<" ";
    else g<<"0 ";
    return 0;
}
