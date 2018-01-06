#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *p,*q;
char n[100];
int i,k,m,a,x,mi=99999999;
void creare(nod *&prim, nod *ultim)
{
    f.get(n,100);
    k=strlen(n);
    if(strlen(n)>m) m=strlen(n);
    if(strlen(n)<mi) mi=strlen(n);
    prim=new nod;
    prim->nr=n[k]-'0';
    prim->urm=0;
    ultim=prim;
    for(i=1;i<=strlen(n);i++)
    {
        k--;
        p=new nod;
        p->nr=n[k]-'0';
        p->urm=0;
        ultim->urm=p;
        ultim=p;
    }
}
void pune(nod *&prim,nod *&ultim1, int x)
{
    nod *q;
    if(!prim)
    {
        prim=new nod;
        prim->nr=x;
        prim->urm=0;
        ultim1=prim;
    }
    else
    {
        q=new nod;
        q->nr=x;
        q->urm=0;
        ultim1->urm=q;
        ultim1=q;
    }
}
int main()
{
    nod *prim=0,*prim1=0, *ultim, *ultim1;
    creare(prim,ultim);
    f.get();
    creare(prim1,ultim);
   /** p=prim->urm;
    while(p) {g<<p->nr<<" ";p=p->urm;}
    g<<endl;
    p=prim1->urm;
    while(p) {g<<p->nr<<" ";p=p->urm;}*/
    p=prim->urm;
    q=prim1->urm;
    for(i=1;i<=mi;i++)
        {
            x=p->nr*q->nr+a;
            q->nr=x%10;
            a=x/10;
            if(p->urm) p=p->urm;
            q=q->urm;
        }
        if(q->urm)
            for(i=1;i<=m-mi;i++)
        {
            x=q->nr+a;
            q->nr=x%10;
            a=x/10;
            q=q->urm;
        }
        else x=q->nr+a, q->nr=x%10, a=x/10;


        if(a)
        {
            p=new nod;
            p->nr=a;
            p->urm=0;
            q->urm=p;
        }
q=prim1->urm;
while(q)
{
    g<<q->nr<<" ";
    q=q->urm;
}
    return 0;
}
