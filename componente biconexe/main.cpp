#include <bits/stdc++.h>
#define e 100001
using namespace std;
ifstream f("biconex.in");
ofstream g("biconex.out");
int n,m,i,d[e],low[e],viz[e],st[e],t,s,k,nr,x,y,j;
vector <int> a[e];
vector <int> sol[e];
void dfs(int nod,int tata)
{
    ++t;d[nod]=t;low[nod]=t;viz[nod]=1;st[++k]=nod;
    for(int i=0;i<a[nod].size();i++)
        if(!d[a[nod][i]]) dfs(a[nod][i],nod),low[nod]=min(low[nod],low[a[nod][i]]);
    else if(a[nod][i]!=tata) low[nod]=min(low[nod],d[a[nod][i]]);
    if(low[nod]>=d[tata]&&tata)
    {sol[++nr].push_back(tata);
        do
        {
            x=st[k--];
            viz[x]=0;
            sol[nr].push_back(x);
        }while(x!=nod&&k>0);}
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y,a[x].push_back(y),a[y].push_back(x);
    for(i=1;i<=n;i++) if(!d[i]) dfs(i,0);
    g<<nr<<'\n';
    for(i=1;i<=nr;i++)
    {for(j=0;j<sol[i].size();j++) g<<sol[i][j]<<" ";g<<'\n';}
    return 0;
}
