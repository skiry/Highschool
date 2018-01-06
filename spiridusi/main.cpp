#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("spiridusi.in");
ofstream g("spiridusi.out");
int n,c,s[100001],p[100001],i,x,y,d[100001],t[100001],profit[100001],rezultat;
vector <int> a[100001];
queue <int> q;
void bf(int nod)
{
    for(i=2;i<=n;i++) d[i]=99999;
    q.push(nod);
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(int j=0;j<a[actual].size();j++)
            if(d[a[actual][j]]>=d[actual]+s[a[actual][j]])
            {
                d[a[actual][j]]=d[actual]+s[a[actual][j]];
                profit[a[actual][j]]=profit[actual]+p[a[actual][j]];
                ///profit[a[actual][j]]=max(profit[a[actual][j]],profit[actual]+p[a[actual][j]]);
                q.push(a[actual][j]);
                t[a[actual][j]]=actual;
            }
    }
}
void reconst(int k,int i)
{
    if(t[k])
    {
        reconst(t[k],i);
        if(d[i]>c) d[i]-=s[k],profit[i]-=p[k];
    }
}
int main()
{
    f>>n>>c;
    for(i=1;i<=n;i++) f>>s[i];
    for(i=1;i<=n;i++) f>>p[i];
    for(i=1;i<n;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    d[1]=0;
    bf(1);
    for(i=1;i<=n;i++)
    {
        if(d[i]>c) reconst(i,i);
        rezultat=max(rezultat,profit[i]);
    }
    g<<rezultat;
    return 0;
}
