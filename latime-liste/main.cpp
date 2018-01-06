#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
int c[100],n,i,j,viz[100],u,p1,prim;
nod *l[100];
void parc()
{
    nod *p;
    if(prim<=u)
    {
        g<<prim<<" "<<u<<endl;
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
    nod *p=0,*q=0;
    f>>n;
    while(f>>i>>j)
    {
        p=new nod;
        p->nr=j;
        p->urm=l[i];
        l[i]=p;

        q=new nod;
        q->nr=i;
        q->urm=l[j];
        l[j]=p;
    }
    f>>p1;
    c[1]=p1;
    viz[p1]=1;
    u=1;
    prim=1;
    parc();
    for(i=1;i<=u;i++) g<<c[i]<<" ";

    return 0;
}
