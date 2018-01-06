#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("traseu.in");
ofstream g("traseu.out");
int n,m,i,t[61],dist[61],sum,rez,v[61],c[61][61],cost[61][61],ex[61],in[61],x,y,z;
vector <int> a[61];
queue <int> q;
int bf()
{
    for(i=1;i<=n+1;i++) dist[i]=999999,v[i]=0;
    dist[0]=0;
    q.push(0);
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(i=0;i<a[actual].size();i++)
            if(c[actual][a[actual][i]]>0&&dist[a[actual][i]]>dist[actual]+cost[actual][a[actual][i]])
        {
            dist[a[actual][i]]=dist[actual]+cost[actual][a[actual][i]];
            t[a[actual][i]]=actual;
            if(!v[a[actual][i]])
            {
                q.push(a[actual][i]);
                v[a[actual][i]]=0;
            }
        }
        v[actual]=0;
    }
    if(dist[n+1]==999999) return 0;
    return dist[n+1];
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>z;
        a[x].push_back(y);
        a[y].push_back(x);
        cost[x][y]=z;
        cost[y][x]=-z;
        c[x][y]=999999;
        ex[x]++;
        in[y]++;
        rez+=z;
    }
    for(i=1;i<=n;i++)
        if(ex[i]>in[i]) a[i].push_back(n+1),c[i][n+1]=ex[i]-in[i];
    else if(ex[i]<in[i]) a[0].push_back(i),c[0][i]=in[i]-ex[i];
    for(;bf();)
    {
        int sum=999999;
        for(i=n+1;i;i=t[i]) if(sum>c[t[i]][i]) sum=c[t[i]][i];
        for(i=n+1;i;i=t[i])
        {
            c[t[i]][i]-=sum;
            c[i][t[i]]+=sum;
        }
        rez+=sum*dist[n+1];
    }
    g<<rez;
    return 0;
}
