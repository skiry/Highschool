#include <fstream>

using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
struct nod{
    int nr,val;
nod *urm;};
nod *a[50001],*p,*q;
int n,m,i,j,x,y,z,v,nr,vf,d[50001],viz[50001];
void pune(int x,int y,int z)
{
    p=new nod;
    p->nr=y;
    p->val=z;
    p->urm=0;
    if(!a[x])
        a[x]=p;
    else
    {
        q=a[x];
        while(q->urm)
            q=q->urm;
        q->urm=p;
    }
}
void cautaMin(int &vf)
{
        int m=99999;
        for(int i=1;i<=n;i++)
            if(d[i]<m&&!viz[i])
                m=d[i],vf=i;

}
void imbunatatireDrum(int vf)
{
    p=a[vf];
    while(p)
    {
        if(!viz[p->nr]&&d[vf]+p->val<d[p->nr])
                d[p->nr]=d[vf]+p->val;
        p=p->urm;
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>z;
        pune(x,y,z);
    }
    v=1;
    viz[1]=1;

    p=a[v];
    while(p)
    {
        d[p->nr]=p->val;
        p=p->urm;
    }
    for(i=2;i<=n;i++)
        if(!d[i]) d[i]=99999;

    for(i=1;i<n;i++)
        {
            cautaMin(vf);
            imbunatatireDrum(vf);
            viz[vf]=1;
        }

    for(i=2;i<=n;i++)
    if(d[i]==99999) g<<"0 ";
    else g<<d[i]<<" ";

        return 0;
}
