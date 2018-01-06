#include <fstream>

using namespace std;
ifstream f("steinsgate.in");
ofstream g("steinsgate.out");
int n,m,x,y,i,j;
long k,r[3][100000],vmax;
struct nod
{
    int nr;
    nod *urm;
};
nod *prim,*urm,*p,*q,*a[100000];
void pune(int x,int y)
{
    nod *p,*q;
    q=new nod;
    q->nr=y;
    q->urm=0;
    if(!a[x])
        a[x]=q;
    else
    {
        p=a[x];
        while(p->urm)
            p=p->urm;
        p->urm=q;
    }
}
int main()
{
    f>>n>>m>>k;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        pune(y,x);
    }
    for(i=1;i<=n;i++) f>>r[1][i];

    for(i=1;i<=k;i++)
    {
        for(j=1;j<=n;j++)
        {
            vmax=0;
            nod *p;
            p=a[j];
            while(p)
            {
                if(r[1][p->nr]>vmax) vmax=r[1][p->nr];
                p=p->urm;
            }
            r[2][j]=vmax;
        }
        for(j=1;j<=n;j++)
            r[1][j]=r[2][j];
    }
    for(i=1;i<=n;i++) g<<r[1][i]<<" ";
    return 0;
}
