#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
ifstream f("cmcm.in");
ofstream g("cmcm.out");
int l,r,m,i,x,y,z,cost[801][801],cap[801][801],t[801],rez,sum,viz[801],dist[801],flux[801][801],d,s,nr,much[801][801];
vector <int> a[801];
queue <int> q;
int bf()
{
    for(i=1;i<=d;i++) dist[i]=999999,viz[i]=0;
    dist[1]=0;
    viz[1]=1;
    q.push(1);
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(i=0;i<a[actual].size();i++)
            if(cap[actual][a[actual][i]]-flux[actual][a[actual][i]]>0&&dist[a[actual][i]]>dist[actual]+cost[actual][a[actual][i]])
        {
            dist[a[actual][i]]=dist[actual]+cost[actual][a[actual][i]];
            t[a[actual][i]]=actual;
            if(!viz[a[actual][i]])
            {
                viz[a[actual][i]]=1;
                q.push(a[actual][i]);
            }
        }
        viz[actual]=0;
    }
    if(dist[d]!=999999) return 1;
    return 0;
}
int main()
{
    f>>l>>r>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>z;
        x++;
        y+=l+1;
        a[x].push_back(y);
        a[y].push_back(x);
        cost[x][y]=z;
        cost[y][x]=-z;
        cap[x][y]=1;
        much[x][y]=i;
    }
    s=1;
    d=l+r+2;
    for(i=2;i<=l+1;i++)
    {
        cap[s][i]=1;
        a[s].push_back(i);
        a[i].push_back(s);
    }
    for(i=l+2;i<=l+r+1;i++)
    {
        cap[i][d]=1;
        a[d].push_back(i);
        a[i].push_back(d);
    }
    for(;bf();)
    {
        int sum=999999;
        for(i=d;i!=1;i=t[i])
            sum=min(sum,cap[t[i]][i]-flux[t[i]][i]);
        for(i=d;i!=1;i=t[i])
        {
            flux[t[i]][i]+=sum;
            flux[i][t[i]]-=sum;
        }
        if(sum) nr++;
        rez+=sum*dist[d];
    }
    g<<nr<<" "<<rez<<'\n';
    for(i=1;i<=l+1;i++)
        for(int j=l+2;j<=d;j++)
            if(cap[i][j]&&flux[i][j]) g<<much[i][j]<<" ";
    return 0;
}
