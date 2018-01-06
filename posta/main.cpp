#include <bits/stdc++.h>
using namespace std;
ifstream f("posta2.in");
ofstream g("posta2.out");
long long n,m,y,z,i,j,pret[100001],needed[100001],necesar[100001],viz[100001],vizitat[100001],sum,x,minim=99999999999;
struct nod
{
    long long v,cost;
}el;
vector <nod> a[100001];
vector <nod>::iterator it;
void df(int nodul)
{
    if(necesar[nodul]&&!vizitat[nodul]) ++viz[nodul];
    ++vizitat[nodul];
    for(int i=0;i<a[nodul].size();i++)
        if(!vizitat[a[nodul][i].v]) df(a[nodul][i].v),viz[nodul]+=viz[a[nodul][i].v];
}
int main()
{
    f.sync_with_stdio(false);
    f>>n>>m;
    for(i=1;i<n;i++)
    {
        f>>x>>el.v>>el.cost;
        a[x].push_back(el);
        swap(x,el.v);
        a[x].push_back(el);
    }
    for(i=1;i<=n;i++) f>>pret[i];
    for(i=1;i<=m;i++) f>>needed[i],++necesar[needed[i]];
    df(needed[1]);
    for(i=1;i<=n;i++) if(!viz[i])
    {
        for(j=0;j<a[i].size();j++)
        {
            int ok=0;
            for(int k=0;k<a[a[i][j].v].size()&&!ok;k++)
                if(a[a[i][j].v][k].v==i) a[a[i][j].v].erase(a[a[i][j].v].begin()+k),++ok;
        }
        a[i].clear();
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<a[i].size();j++)
            sum+=a[i][j].cost;
       if(a[i].size()) sum+=pret[i]*(a[i].size()-1);
    }
    for(i=1;i<=n;i++)
    {
        int value=a[i].size();
        --value;
        minim=min(minim,sum-pret[i]*value);
    }
    g<<minim;
    return 0;
}
