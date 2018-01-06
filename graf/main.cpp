#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("graf.in");
ofstream g("graf.out");
int n,m,nx,ny,b,c,i,j,x[7501],y[7501],caractx[14001],caracty[14001],nr;
vector <int> a[7501];
queue <int> q;
void parcurgere(int nod,int x[7501])
{
    q.push(nod);
    x[nod]=1;
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(int i=0;i<a[actual].size();i++)
            if(x[a[actual][i]]>x[actual]+1||!x[a[actual][i]])
            {
                x[a[actual][i]]=x[actual]+1;
                q.push(a[actual][i]);
            }
    }
}
int main()
{
    f>>n>>m>>nx>>ny;
    for(i=1;i<=m;i++)
    {
        f>>b>>c;
        a[b].push_back(c);
        a[c].push_back(b);
    }
    parcurgere(nx,x);
    parcurgere(ny,y);
    for(i=1;i<=n;i++)
        if(x[i]+y[i]==x[ny]+1) caractx[x[i]]++,caracty[y[i]]++;
    for(i=1;i<=n;i++)
        if(x[i]+y[i]==x[ny]+1&&caractx[x[i]]==1&&caracty[y[i]]==1) nr++,q.push(i);
    g<<nr<<'\n';
    while(q.size())
    {
        g<<q.front()<<' ';
        q.pop();
    }
    return 0;
}
