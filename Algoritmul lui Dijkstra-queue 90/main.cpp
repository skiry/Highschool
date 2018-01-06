#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
int n,m,x,i,d[50001],curent;
struct nod{
int nr,val;};
nod p;
vector <nod> v[50001];
queue <int> c;
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>p.nr>>p.val;
        v[x].push_back(p);
    }
    for(i=2;i<=n;i++)
        d[i]=9999999;
    c.push(1);
    while(c.size())
    {
        curent=c.front();
        c.pop();
        for(i=0;i<v[curent].size();i++)
            if(d[v[curent][i].nr]>d[curent]+v[curent][i].val)
            {
                d[v[curent][i].nr]=d[curent]+v[curent][i].val;
                c.push(v[curent][i].nr);
            }
    }
    for(i=2;i<=n;i++)
        if(d[i]==9999999) g<<"0 ";
    else g<<d[i]<<" ";
    return 0;
}
