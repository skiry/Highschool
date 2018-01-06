#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("bellmanford.in");
ofstream g("bellmanford.out");
int n,m,x,curent,d[50001],viz[50001],ok,i;
struct nod
{
    int nr, val;
};
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
        d[i]=999999;
    c.push(1);
    while(c.size())
    {
        curent=c.front();
        c.pop();
        if(++viz[curent]==n)
        {
            g<<"Ciclu negativ!";
            ok=1;
            break;
        }
        for(i=0;i<v[curent].size();i++)
            if(d[v[curent][i].nr]>d[curent]+v[curent][i].val)
            {
                d[v[curent][i].nr]=d[curent]+v[curent][i].val;
                c.push(v[curent][i].nr);
            }
    }
    if(!ok)
       {
           for(i=2;i<=n;i++)
            if(d[i]==999999) g<<"0 ";
        else g<<d[i]<<" ";
       }
    return 0;
}
