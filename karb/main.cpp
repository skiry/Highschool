#include <bits/stdc++.h>

using namespace std;
ifstream f("karb2.in");
ofstream g("karb2.out");
int n,k,c[100001],viz[100001],i,j,nr=0,nods,posibil[100001],maxim,nodsuri,sol=6,vizt[100001];
vector <int> a[100001];
queue <int> q;
void bf(int nr,int s)
{
    q.push(nr);
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(int i=0;i<a[actual].size();i++)
            if(a[actual][i]!=c[s%2+1]&&viz[a[actual][i]]!=s) viz[a[actual][i]]=s,posibil[a[actual][i]]+=s,q.push(a[actual][i]);
    }
}
int bf2(int nr)
{
    for(int i=1;i<=maxim;i++) viz[i]=0;
    int rez=0;
    q.push(nr);
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(int i=0;i<a[actual].size();i++)
            if(!viz[a[actual][i]]&&posibil[a[actual][i]]==3&&!vizt[a[actual][i]]) viz[a[actual][i]]=1,rez++,q.push(a[actual][i]);
    }
    return rez;
}
void backt(int nod,int nr)
{
    if(bf2(c[2])==nodsuri-nods) sol++;
    for(int i=0;i<a[nod].size();i++)
        if(!vizt[a[nod][i]]&&posibil[a[nod][i]]==3)
    {
        nods++;
        vizt[a[nod][i]]=1;
        backt(a[nod][i],nr+1);
        vizt[a[nod][i]]=0;
        nods--;
    }
}
int main()
{
    int x,y;
    f>>n>>k;
    for(i=1;i<=k;i++) f>>c[i];
    for(i=1;i<n;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
        maxim=max(max(x,y),maxim);
    }
    for(i=1;i<=k;i++) bf(c[i],i);
    sol+=c[1]%2;
    for(i=1;i<=maxim;i++)
        if(posibil[i]==3) nodsuri++;
    backt(c[1],1);
    g<<sol;
    return 0;
}
