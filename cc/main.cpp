#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("cc.in");
ofstream g("cc.out");
int n,i,j,rez,c[300][300],cost[300][300],s,d,dist[300],flux[300][300],t[300],el;
vector <int> a[300];
queue <int> q;
int bf()
{
    for(i=s;i<=d;i++) dist[i]=9999;
    q.push(s);
    dist[s]=0;
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(i=0;i<a[actual].size();i++)
            if(c[actual][a[actual][i]]-flux[actual][a[actual][i]]>0&&dist[actual]+cost[actual][a[actual][i]]<dist[a[actual][i]])
        {
            dist[a[actual][i]]=dist[actual]+cost[actual][a[actual][i]];
            t[a[actual][i]]=actual;
            q.push(a[actual][i]);
        }
    }
    if(dist[d]!=9999) return 1;
    return 0;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            f>>el;
            a[i].push_back(n+j);
            a[n+j].push_back(i);
            c[i][n+j]=1;
            cost[i][n+j]=el;
            cost[n+j][i]=-el;
        }
    d=2*n+1;
    for(i=1;i<=n;i++)
    {
        a[s].push_back(i);
        c[s][i]=1;
        a[n+i].push_back(d);
        c[n+i][d]=1;
    }
    for(;bf();)
    {
        int sum=99999;
        for(i=d;i!=s;i=t[i])
            sum=min(sum,c[t[i]][i]-flux[t[i]][i]);
        if(sum)
            for(i=d;i!=s;i=t[i])
        {
            flux[t[i]][i]+=sum;
            flux[i][t[i]]-=sum;
            rez+=cost[t[i]][i];
        }
    }
    g<<rez;
    return 0;
}
