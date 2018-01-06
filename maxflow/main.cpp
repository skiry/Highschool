#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
ifstream f("maxflow.in");
ofstream g("maxflow.out");
int n,m,i,j,c[1001][1001],flux[1001][1001],x,y,z,viz[1001],t[1001],nr,sum,rez;
vector <int> a[1001];
queue <int> q;
int bf()
{
    while(q.size()) q.pop();
    q.push(1);
    for(int i=1;i<=n;i++) viz[i]=0;
    viz[1]=1;
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(int i=0;i<a[actual].size();i++)
        {
            if(c[actual][a[actual][i]]!=flux[actual][a[actual][i]]&&viz[a[actual][i]]!=1)
            {
                t[a[actual][i]]=actual;
                viz[a[actual][i]]=1;
                q.push(a[actual][i]);
                if(a[actual][i]==n) return 1;
            }
        }
    }
    return 0;
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>z;
        a[x].push_back(y);
        a[y].push_back(x);
        c[x][y]+=z;
    }
    for(rez=0;bf();)
    {
        int sum=999999;
        for(int i=n;i!=1;i=t[i])
            sum=min(sum,c[t[i]][i]-flux[t[i]][i]);
        for(int i=n;i!=1;i=t[i])
        {
            flux[t[i]][i]+=sum;
            flux[i][t[i]]-=sum;
        }
        rez+=sum;
    }
    g<<rez;
    return 0;
}
