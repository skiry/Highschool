#include <bits/stdc++.h>

using namespace std;
ifstream f("amici2.in");
ofstream g("amici2.out");
int t,n,m,i,x,y,maxim,j,d[21001];
vector <int> a[21001];
queue <int> q;
int main()
{
    f>>t;
    for(i=1;i<=t;++i)
    {
        f>>n>>m;
        for(j=1;j<=n;++j) a[j].clear();
        for(j=1;j<=m;++j)
        {
            f>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        maxim=0;
        for(int sursa=1;sursa<=n;sursa+=n/4)
        {
            for(j=1;j<=n;++j) d[j]=999999;
            d[sursa]=0;
            q.push(sursa);
            while(q.size())
            {
                int actual=q.front();
                q.pop();
                for(int j=0;j<a[actual].size();j++)
                    if(d[a[actual][j]]==999999) d[a[actual][j]]=d[actual]+1,q.push(a[actual][j]),maxim=max(maxim,d[a[actual][j]]);
            }
        }
        for(j=0;(1<<j)<maxim;++j);
        g<<j<<'\n';
    }
    return 0;
}
