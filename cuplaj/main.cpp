#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("cuplaj.in");
ofstream g("cuplaj.out");
int n,m,l,i,x,y,t[10001],s,d,viz[10001];
struct element
{
    int v,c,f;
};
element p;
vector <element> a[10001];
queue <int> q;
int bf()
{
    while(q.size()) q.pop();
    for(i=1;i<=d;i++) viz[i]=0;
    viz[1]=1;
    q.push(1);
    while(q.size())
    {
        int actual=q.front();

        q.pop();
        for(i=0;i<a[actual].size();i++)
            if(a[actual][i].c!=a[actual][i].f&&!viz[a[actual][i].v])
        {
            t[a[actual][i].v]=actual;
            viz[a[actual][i].v]=1;
            q.push(a[actual][i].v);
            if(a[actual][i].v==d) return 1;
        }
    }
    return 0;
}
int main()
{
    f>>n>>m>>l;
    for(i=1;i<=l;i++)
    {
        f>>x>>y;
        x++;
        y+=n+1;
        p.v=y;
        p.c=1;
        a[x].push_back(p);
        p.v=x;
        a[y].push_back(p);
    }
    s=1;
    d=n+m+2;
    for(i=2;i<=n+1;i++)
    {
        p.c=1;
        p.v=i;
        a[s].push_back(p);
        p.v=s;
        a[i].push_back(p);
    }
    for(i=n+2;i<d;i++)
    {
        p.c=1;
        p.v=i;
        a[d].push_back(p);
        p.v=d;
        a[i].push_back(p);
    }
    bf();//for(;bf();)
    {
        int sum=999999;
        for(i=d;i!=s;i=t[i])
        {
            for(int j=0;j<a[t[i]].size();j++)
                if(a[t[i]][j].v==i)
                    {sum=min(sum,a[t[i]][j].c-a[t[i]][j].f);continue;}
        }
        for(i=d;i!=s;i=t[i])
        {
            a[t[i]][i].f+=sum;
            a[i][t[i]].f-=sum;
        }
        g<<min(n,m)*sum;
    }
    return 0;
}
