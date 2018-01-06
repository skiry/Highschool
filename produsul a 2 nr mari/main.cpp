#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod
{
    char nr;
    nod *urm;
    nod *prec;
};
nod *p,*prim,*ultim,*prim1,*prim2,*q,*u;
char a[100],b[100];
int n,m,v,y,x,k,l=1,i;
int main()
{
    f.get(a,100);
    f.get();
    f.get(b,100);
    n=strlen(a)-1;
    m=strlen(b)-1;
    prim=new nod;
    prim->nr=a[n]-'0';
    prim->prec=0;
    prim->urm=0;
    ultim=prim;
    while(n)
    {
        n--;
        p=new nod;
        p->nr=a[n]-'0';
        p->prec=ultim;
        p->urm=0;
        ultim->urm=p;
        ultim=p;
    }
    prim1=new nod;
    prim1->nr=b[m]-'0';
    prim->prec=0;
    prim1->urm=0;
    ultim=prim1;
    while(m)
    {
        m--;
        p=new nod;
        p->nr=b[m]-'0';
        p->prec=ultim;
        p->urm=0;
        ultim->urm=p;
        ultim=p;
    }
/**
    p=prim;
    while(p) {g<<p->nr<<" "; p=p->urm;}
    p=prim1;g<<endl;
    while(p) {g<<p->nr<<" "; p=p->urm;}
*/
prim2=new nod;
prim2->nr=(prim->nr*prim1->nr)%10;
v=(prim->nr*prim1->nr)/10;
prim2->urm=0;
prim2->prec=0;
ultim=prim2;
x=2;

while(l<strlen(a)+strlen(b)-1)
{
    q=prim;
    p=prim1;
    u=new nod;
    u->nr=v;
    v=0;
    u->urm=0;
    u->prec=ultim;
    if(x>strlen(a))
        for(i=1;i<x-strlen(a);i++)
            p=p->urm;

    if(x<strlen(b))
    {
        if(x<=strlen(a))
            for(i=1;i<x;i++)
                q=q->urm;
            else
                for(i=1;i<strlen(a);i++)
                    q=q->urm;

        for(i=1;i<=x;i++)
        {
            u->nr=u->nr+p->nr*q->nr;
            v=v+u->nr/10;
            u->nr=u->nr%10;
            p=p->urm;
            q=q->prec;
        }
    }
    else
    {
        if(x<=strlen(a))
            for(i=1;i<x;i++)
                q=q->urm;
            else
                for(i=1;i<strlen(a);i++)
                    q=q->urm;

            for(i=1;i<=strlen(b);i++)
            {
                u->nr=u->nr+p->nr*q->nr;
                v=v+u->nr/10;
                u->nr=u->nr%10;
                p=p->urm;
                q=q->prec;
            }

    }g<<(int)u->nr<<" "<<v<<" "<<x<<endl;


    ultim->urm=u;
    ultim=u;
    l++;x++;
}
p=prim2;
while(p) g<<(int)p->nr, p=p->urm;

    return 0;
}
