#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
ifstream f("fmcm.in");
ofstream g("fmcm.out");
int n,m,s,d,i,j,sum,viz[351],c[351][351],cost[351][351],flux[351][351],dist[351],t[351],w,x,y,z;
long long rez;
vector <int> a[351];
queue <int> q;
int bf()
{
    q.push(s);
    for(i=1;i<=n;i++) viz[i]=0,dist[i]=99999;
    viz[s]=1;
    dist[s]=0;
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(i=0;i<a[actual].size();i++)
            if(c[actual][a[actual][i]]-flux[actual][a[actual][i]]>0&&dist[a[actual][i]]>dist[actual]+cost[actual][a[actual][i]])
        {
            t[a[actual][i]]=actual;
            dist[a[actual][i]]=dist[actual]+cost[actual][a[actual][i]];
            if(!viz[a[actual][i]])
            {
                viz[a[actual][i]]=1;
                q.push(a[actual][i]);
            }
        }
        viz[actual]=0;
    }
    if(dist[d]!=99999) return 1;
    return 0;
}
int main()
{
    f>>n>>m>>s>>d;
    for(i=1;i<=m;i++)
    {
        f>>w>>x>>y>>z;
        a[w].push_back(x);
        a[x].push_back(w);
        c[w][x]=y;
        cost[w][x]=z;
        cost[x][w]=-z;
    }
    for(rez=0;bf();)
    {
        sum=99999;
        for(i=d;i!=s;i=t[i])
            sum=min(sum,c[t[i]][i]-flux[t[i]][i]);
        for(i=d;i!=s;i=t[i])
        {
            flux[t[i]][i]+=sum;
            flux[i][t[i]]-=sum;
        }
        rez+=sum*dist[d];
    }
    g<<rez;
    return 0;
}
