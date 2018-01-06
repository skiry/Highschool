#include <bits/stdc++.h>

using namespace std;
ifstream f("tarabe.in");
ofstream g("tarabe.out");
struct produs
{
    long long ratie,pret,initial;
}p[200001],el;
struct cmp
{
    bool operator() (const produs &a, const produs &b)
    {
        return a.pret>b.pret;
    }
};
long long n,k,s,i;
priority_queue <produs, vector < produs >, cmp> q;
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++)
    {
        f>>p[i].ratie>>p[i].pret;
        p[i].initial=i;
        q.push(p[i]);
    }
    for(i=1;i<=k;i++)
    {
        el=q.top();
        s+=el.pret;
        q.pop();
        el.pret+=el.ratie;
        q.push(el);
    }
    g<<s;
    return 0;
}
