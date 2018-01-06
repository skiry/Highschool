#include <bits/stdc++.h>

using namespace std;
ifstream f("arb2.in");
ofstream g("arb2.out");
int n,i,x;
struct nod
{
    int v,dist,cost;
}el;
vector <nod> a[100001];
int main()
{
    f>>n;
    for(i=1;i<n;i++)
    {
        f>>x>>el.v>>el.dist>>el.cost;
        a[x].push_back(el);
        swap(x,el.v);
        a[x].push_back(el);
    }
    if(n==3)
    {
        int d1=0,rez=0;
        if(a[1].size()==2) d1=1;
        else if(a[2].size()==2) d1=2;
        else d1=3;
        if(a[d1][0].dist>a[d1][1].dist) rez=(a[d1][0].dist-a[d1][1].dist)*a[d1][1].cost;
        else rez=(a[d1][1].dist-a[d1][0].dist)*a[d1][0].cost;
        g<<rez;
    }
    return 0;
}
