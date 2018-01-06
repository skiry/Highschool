/**#include <fstream>
#include<iomanip>
using namespace std;
ifstream f("alee.in");
ofstream g("alee.out");
struct punct
{
    int x,y,val;
};
punct c[180*180],w;
int a[180][180],i,j,n,m,x,y,l1,c1,l2,c2,poz,prim,ultim;
int dl[]={-1,0,1,0},dc[]={0,1,0,-1};
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        a[x][y]=-1;
    }
    f>>l1>>c1>>l2>>c2;
    a[l1][c1]=1; a[l2][c2]=1;
    for(i=0;i<=n+1;i++)
        a[i][0]=-1, a[0][i]=-1,a[n+1][i]=-1,a[i][n+1]=-1;
    /**
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=n+1;j++)
            g<<setw(3)<<a[i][j]<<" ";
        g<<'\n';
    }
    g<<'\n';

    c[1].x=l1; c[1].y=c1; c[1].val=1;
    prim=1; ultim=1;
    while(prim<=ultim)
    {
        w=c[prim];
        for(i=0;i<4;i++)
        if(a[w.x+dl[i]][w.y+dc[i]]==0||a[w.x+dl[i]][w.y+dc[i]]==1)
        {
            a[w.x+dl[i]][w.y+dc[i]]=a[w.x][w.y]+1;
            ultim++;
            c[ultim].x=w.x+dl[i];
            c[ultim].y=w.y+dc[i];
            c[ultim].val=a[w.x+dl[i]][w.y+dc[i]];
        }
        ///if(w.x+dl[i]==l1&&w.y+dc[i]==c1&&a[w.x][w.y]>1) poz=a[w.x][w.y]+1;
        prim++;
    }
    /**
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=n+1;j++)
            g<<setw(3)<<a[i][j]<<" ";
        g<<'\n';
    }

    g<<a[l2][c2];
    return 0;
}**/
#include <fstream>
#include<iomanip>
using namespace std;
ifstream f("alee.in");
ofstream g("alee.out");
struct punct
{
    int x,y,val;
};
struct nod
{
    punct nr;
    nod *urm;
};
punct z,w;
int a[180][180],i,j,n,m,x,y,l1,c1,l2,c2,poz,inc,sf;
int dl[]={-1,0,1,0},dc[]={0,1,0,-1};
nod *p,*prim,*ultim;
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        a[x][y]=-1;
    }
    f>>l1>>c1>>l2>>c2;
    a[l1][c1]=1; a[l2][c2]=1;
    for(i=0;i<=n+1;i++)
        a[i][0]=-1, a[0][i]=-1,a[n+1][i]=-1,a[i][n+1]=-1;
    /**
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=n+1;j++)
            g<<setw(3)<<a[i][j]<<" ";
        g<<'\n';
    }
    g<<'\n';
    **/
    z.x=l1; z.y=c1; z.val=1; inc=sf=1;
    prim=new nod;
    prim->nr=z;
    prim->urm=0;
    ultim=prim;
    while(inc<=sf)
    {
        w=prim->nr;
        if(prim->urm) prim=prim->urm;
        inc++;
        for(i=0;i<4;i++)
        if(a[w.x+dl[i]][w.y+dc[i]]==0||a[w.x+dl[i]][w.y+dc[i]]==1)
        {
            a[w.x+dl[i]][w.y+dc[i]]=a[w.x][w.y]+1;
            sf++;
            z.x=w.x+dl[i];
            z.y=w.y+dc[i];
            z.val=a[w.x+dl[i]][w.y+dc[i]];
            p=new nod;
            p->nr=z;
            p->urm=0;
            ultim->urm=p;
            ultim=p;
        }
        ///if(w.x+dl[i]==l1&&w.y+dc[i]==c1&&a[w.x][w.y]>1) poz=a[w.x][w.y]+1;

    }
/**
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=n+1;j++)
            g<<setw(3)<<a[i][j]<<" ";
        g<<'\n';
    }
*/
    g<<a[l2][c2];
    return 0;
}
