#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;
nod *urm1;};
void creare(nod *&prim, nod *ultim, int &n)
{
    nod *p;
    f>>n;
    prim=new nod;
    prim->urm1=0;
    prim->nr=0;
    ultim=prim;
    for(int i=2;i<=n;i++)
        {
            p=new nod;
            p->urm1=0;
            p->nr=0;
            ultim->urm1=p;
            ultim=p;
        }
}
void pune(int x,int y,nod *prim)
{
    nod *q,*p;
    q=new nod;
    q->nr=y;
    q->urm=0;
    p=prim;
    for(int i=1;i<x;i++)
        p=p->urm1;

    if(!p->nr)
        p=q;
    else
   {
      while(p->urm)
            p=p->urm;
        p->urm=q;
    }
}
int main()
{
    int x,y,n;
    nod *prim,*ultim,*p,*q;
    creare(prim, ultim, n);
    while(f>>x>>y)
        pune(x,y,prim), pune(y,x,prim);

    p=prim;
    while(p)
        {
            q=p;
            while(q)
                {
                    g<<q->nr<<" ";
                    q=q->urm;
                }
            p=p->urm1;
            g<<endl;
        }

    return 0;
}
