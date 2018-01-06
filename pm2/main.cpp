#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("pm2.in");
ofstream g("pm2.out");
int n,i,j,c[101],m,b,fin[101],vmax,ex[101],in[101],viz[101],nrr;
struct nod
{
    int nr,cost;
};
nod p;
queue <int> q;
vector <nod> a[101];
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>c[i];
    for(i=1;i<=n;i++)
    {
        f>>m;
        for(j=1;j<=m;j++)
        {
            f>>b;
            p.nr=i;
            p.cost=c[i];
            a[b].push_back(p); ///muchie de la nodul citit la nodul i
            ex[b]++;
            in[i]++;
        }
    }
    if(!n) g<<n;
    else{
    int ok=1;
    while(ok)
    {
        ok=0;
        for(i=1;i<=n;i++)
            if(!in[i]&&!viz[i])                     ///sortare topologica
            {
                ok=1;
                q.push(i);
                viz[i]++;
                for(j=0;j<a[i].size();j++)
                    in[a[i][j].nr]--;
            }
    }
    while(q.size())
    {
        i=q.front();
        q.pop();
        for(j=0;j<a[i].size();j++)                     ///actualizare distanta maxima
            if(fin[i]+c[i]>fin[a[i][j].nr]) fin[a[i][j].nr]=fin[i]+c[i];
    }
    for(i=1;i<=n;i++)
        if(!ex[i]) if(fin[i]+c[i]>vmax) vmax=fin[i]+c[i]; ///maximul fin[i]+cost[i] fiecarei frunze,pt a afla momentul cand se termina totul
    g<<vmax<<endl;
    for(i=1;i<=n;i++)
        g<<fin[i]<<" "<<fin[i]<<endl;
    }
    return 0;
}
