#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
int c[100],n,viz[100],prim,u,p1;
nod *l[100];
void parc()
{
    nod *p;
    if(prim<=u)
    {
        p=l[c[prim]];
        while(p)
        {
            if(!viz[p->nr])
                u++, c[u]=p->nr, viz[p->nr]++;
            p=p->urm;
        }
        prim++;
        parc();
    }
}
int main()
{
    nod *p,*q,*o;
    int i,j;
    f>>p1;
    f>>n;
    while(f>>i>>j)
    {
        p=new nod;
        p->nr=j;
        p->urm=l[i];
        o=l[i];
        while(o->urm) o=o->urm;
        o->urm=l[i];
        l[i]=p;

        q=new nod;
        q->nr=i;
        q->urm=l[j];
        l[j]=q;
    }

    c[1]=p1;
    viz[p1]=1;
    prim=u=1;
    parc();
    for(i=1;i<=u;i++) g<<c[i]<<" ";

    return 0;
}
