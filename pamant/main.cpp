#include <bits/stdc++.h>

using namespace std;
ifstream f("pamant.in");
ofstream g("pamant.out");
int n,m,i,viz[100001],x,y,afisat[100001],nr,nivel,d[100001],low[1000001],st[100001],k,aparitie[100001],j,t,vizitat[100001],compconexe;
vector <int> a[100001];
vector <int> sol[100001];
vector <int> rez;
vector <int>::iterator it;
void dfs(int nod,int tata,int completare)
{
    ++t;d[nod]=t;low[nod]=t;viz[nod]=1;st[++k]=nod;vizitat[nod]=completare;
    for(int i=0;i<a[nod].size();i++)
        if(!d[a[nod][i]]) dfs(a[nod][i],nod,completare),low[nod]=min(low[nod],low[a[nod][i]]);
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
    for(i=1;i<=n;i++)
        if(!vizitat[i]) ++compconexe,dfs(i,0,i);
    g<<compconexe<<'\n';
    for(i=1;i<=n;i++)
        if(!afisat[vizitat[i]]) ++afisat[vizitat[i]],g<<vizitat[i]<<" ";
    g<<'\n';
    for(i=1;i<=nr;i++)
    {
        for(j=0;j<sol[i].size();j++)
        {
            aparitie[sol[i][j]]++;
            if(aparitie[sol[i][j]]>1) rez.push_back(sol[i][j]);
        }
    }
    sort(rez.begin(),rez.end());
    it=unique(rez.begin(),rez.end());
    rez.resize(distance(rez.begin(),it));
    g<<rez.size()<<'\n';
    for(i=0;i<rez.size();i++) g<<rez[i]<<" ";

    return 0;
}
