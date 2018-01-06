#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("confuzie.in");
ofstream g("confuzie.out");
int n,m,i,j,op,x,y,cul[200001],t[200001],viz[200001];
vector <int> a[200001];
queue <int> q;
int main()
{
    f>>n>>m;
    for(i=1;i<n;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    q.push(1);
    viz[1]++;
    while(q.size())
    {
        int actual=q.front();
        q.pop();
        for(int i=0;i<a[actual].size();i++)
            if(!viz[a[actual][i]]) viz[a[actual][i]]++,q.push(a[actual][i]),t[a[actual][i]]=actual;
    }
    for(j=1;j<=m;j++)
    {
        f>>op>>x;
        if(!op) cul[x]++,cul[x]%=2;
        else
        {
            f>>y;
            int actual=y,poz=-1;
            while(actual!=x)
            {
                if(cul[actual]) poz=actual;
                actual=t[actual];
            }
            if(cul[actual]) poz=actual;
            g<<poz<<'\n';
        }
    }
    return 0;
}
