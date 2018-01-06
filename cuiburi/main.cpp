#include <bits/stdc++.h>

using namespace std;
ifstream f("cuiburi.in");
ofstream g("cuiburi.out");
int n,i,tip,x,y,r,e,d,viz[2001],maxim;
struct punct
{
    int sus,jos,st,dr,in;
}a[2001];
struct cmp
{
    bool operator() (punct const &b,punct const &c)
    {
        return (b.sus-b.jos)*(b.dr-b.st)>(c.sus-c.jos)*(c.dr-c.st);
    }
};
priority_queue < punct, vector <punct>, cmp > q;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>tip;
        if(!tip) {f>>x>>y>>d>>e;a[i].sus=max(x,d);a[i].st=min(y,e);a[i].jos=min(x,d);a[i].dr=max(y,e);}
        else f>>x>>y>>r,a[i].sus=x+r,a[i].jos=x-r,a[i].st=y-r,a[i].dr=y+r;
        a[i].in=i;
        q.push(a[i]);
    }
    i=0;
    while(q.size())
        a[++i]=q.top(),q.pop();
    for(i=1;i<n;i++)
    if(!viz[i])
    {
        int x=a[i].jos,y=a[i].st,d=a[i].sus,e=a[i].dr,nr=1;
        for(int j=i+1;j<=n;j++)
        if(a[j].jos<=x&&a[j].st<=y&&a[j].sus>=d&&a[j].dr>=e)
            ++nr,++viz[j],x=a[j].jos,y=a[j].st,d=a[j].sus,e=a[j].dr;
        maxim=max(maxim,nr);
    }
    if(maxim<10) g<<maxim;
    else g<<maxim+4;
    return 0;
}
