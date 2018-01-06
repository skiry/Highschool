#include <bits/stdc++.h>
using namespace std;
ifstream f("autostrazi.in");
ofstream g("autostrazi.out");
int n,i,smax,b,c,d,viz[201],viz1[201],muchii=1,nr,ok=1;
struct punct
{
    int plecare,x,y,cost,in;
};
punct el;
vector <punct> a[201];
struct cmp
{
    bool operator() (punct const &b, punct const &c)
    {
        return b.cost>c.cost;
    }
};
priority_queue< punct, vector <punct> , cmp >q;
int main()
{
    f>>n>>smax;
    while(f>>b>>c>>d)
    {
        el.y=c;
        el.cost=d;
        el.in=++i;
        el.plecare=b;
        a[b].push_back(el);
        el.plecare=c;
        swap(b,el.y);
        a[b].push_back(el);
    }
    for(i=0;i<a[1].size();i++)
        q.push(a[1][i]);
    int suma=0;
    viz[1]=1;
    while(suma<=smax&&ok)
    {
        punct actual=q.top();
        q.pop();
        if(!viz1[actual.in]&&!viz[actual.y])
        {
            ok=0;
            for(i=0;i<a[actual.y].size();i++)
                if(!viz[a[actual.y][i].y]) q.push(a[actual.y][i]);
            if(suma+actual.cost<=smax)
            {
                if(!viz[actual.y]) muchii++;
                suma+=actual.cost;
                nr++;
                ok=1;
                g<<actual.plecare<<" "<<actual.y<<" "<<actual.cost<<'\n';
            }
            viz[actual.y]++;
            viz1[actual.in]++;
        }
    }
    g<<muchii<<" "<<nr<<" "<<suma;
    return 0;
}
