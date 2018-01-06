#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("dragoni.in");
ofstream g("dragoni.out");
int v,n,m,c[801],i,j,x,viz[801],maxim,drum[801][801],cost;
struct nod
{
    int nr,val;
};
nod p;
vector <nod> a[801];
queue <int> q;
void bf(int nd)
{
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        viz[actual]=0;
        if(c[actual]>maxim) maxim=c[actual];
        for(int i=0;i<a[actual].size();i++)
            if(viz[a[actual][i].nr]) q.push(a[actual][i].nr);
    }
}
int main()
{
    f>>v>>n>>m;
    for(i=1;i<=n;i++)
        f>>c[i];
    if(v==1)
    {
        for(i=1;i<=m;i++)
        {
            f>>x>>p.nr>>p.val;
            if(p.val<=c[1])
                {
                    a[x].push_back(p);
                    swap(x,p.nr);
                    a[x].push_back(p);
                    viz[x]=viz[p.nr]=1;
                }
        }
        q.push(1);
        bf(1);
        g<<maxim;
    }
    else if(v==2)
    {
        for(i=1;i<=m;i++)
        {
            f>>x>>p.nr>>p.val;
            a[x].push_back(p);
            swap(x,p.nr);
            a[x].push_back(p);
        }
        for(j=1;j<=n;j++)
        {
            for(i=1;i<=n;i++) drum[j][i]=99999999;
            drum[j][j]=0;
            viz[j]=1;
            q.push(j);
            while(q.size())
            {
                int valoare=q.front();
                q.pop();
                viz[valoare]=0;
                for(i=0;i<a[valoare].size();i++)
                {
                    if(a[valoare][i].val<=c[j])
                        if(drum[j][a[valoare][i].nr]>drum[j][valoare]+a[valoare][i].val)
                        {
                            drum[j][a[valoare][i].nr]=drum[j][valoare]+a[valoare][i].val;
                            if(!viz[a[valoare][i].nr])
                            {
                                viz[a[valoare][i].nr]++;
                                q.push(a[valoare][i].nr);
                            }
                        }
                }
            }
        }
        for(int k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(i!=k&&i!=j&&k!=j&&drum[i][j]>drum[i][k]+drum[k][j])
                        drum[i][j]=drum[i][k]+drum[k][j];
        g<<drum[1][n];
    }
    return 0;
}
