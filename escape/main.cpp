#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
ifstream f("escape.in");
ofstream g("escape.out");
int n,m,k,culoare[51],cul,d[51][51],viz[51],i,j,nr;
struct nod
{
    int v,c;
};
nod p;
vector <nod> a[51];
void df(int nd)
{
    for(int i=0;i<a[nd].size();i++)
        if(!viz[a[nd][i].v])
        {
            g<<nd<<" "<<a[nd][i].v<<endl;
            viz[a[nd][i].v]=1;
            if(!d[nd][a[nd][i].v]) d[nd][a[nd][i].v]=a[nd][i].c;
            df(a[nd][i].v);
        }
}
int main()
{
    f>>n>>m>>k;
    for(i=1;i<=m;i++) f>>cul,culoare[cul]=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=k;j++)
        {
            f>>p.v;
            p.c=j;
            a[i].push_back(p);
        }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) viz[j]=0;
        df(i);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        g<<d[i][j]<<" ";g<<endl;}
    return 0;
}
