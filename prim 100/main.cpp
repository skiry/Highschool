#include <bits/stdc++.h>

using namespace std;

ifstream inf("apm.in");
ofstream outf("apm.out");

const int N=200010;
int n, m, i, j, t[N], x, y, c, cost, a, b, compr(int );
pair<int, pair<int,int> > M[2*N];
vector<pair<int,int> > sol;
int main()
{
    inf>>n>>m;

    for(i=1; i<=n; i++)
        t[i]=i;
    for(i=1;i<=m;i++)
    {
        inf>>x>>y>>c;
        M[i]={c,{x,y}};
    }
    sort(M+1, M+m+1);
    for(i=1,j=n-1; j; i++)
    {
        a=M[i].second.first;
        b=M[i].second.second;
        x=compr(a);
        y=compr(b);
        if(x!=y)
        {
            t[x]=y;
            cost+=M[i].first;
            sol.push_back({a,b});
            j--;
        }
    }
    outf<<cost<<'\n'<<n-1<<'\n';
    for(vector<pair<int,int> >:: iterator i=sol.begin();i!=sol.end();i++)
        outf<< i->first <<" "<<i->second<<'\n';
    return 0;
}
int compr(int v)
{
    if(t[v]==v)
        return v;
    t[v]=compr(t[v]);
    return t[v];
}
