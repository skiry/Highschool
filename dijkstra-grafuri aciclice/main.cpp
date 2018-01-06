#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod
{
    int nr,val;
};
nod p;
vector <nod> a[100];
queue <int> q,lista;
int n,m,x,in[100],d[100],i;
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>p.nr>>p.val;
        a[x].push_back(p);
        in[p.nr]++;
    }
    for(i=1;i<=n;i++)
    {
        d[i]=999999;
        if(!in[i]) q.push(i);
    }
    d[1]=0;
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        lista.push(actual);
        for(i=0;i<a[actual].size();i++)
            if(!--in[a[actual][i].nr]) q.push(a[actual][i].nr);
    }
    q.push(c.front());
    c.pop();
    while(q.size())
    {
        int actual=q.front();
    }
    return 0;
}
