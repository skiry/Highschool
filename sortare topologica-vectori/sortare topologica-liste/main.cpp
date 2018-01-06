#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int a;
int b;
nod *urm;};

void creare(nod *&prim)
{nod *p,*ultim;
int n;
prim=new nod;
prim->a=0;
prim->b=0;
prim->urm=0;
ultim=prim;
for(int i=1;i<=n;i++)
    {
        p=new nod;
        p->a=0;
        p->b=0;
        p->urm=0;
        ultim->urm=p;
        ultim=p;
    }
}

void adaugare(int i,int j,nod *prim)
{int q;
nod *p,*c;
p=prim;
for(q=1;q<=j;q++)
    p=p->urm;
p->a++;
for(q=1;q<=i;q++)
    p=p->urm;
if((p->b)==0) {p->b=i; p->b->urm=0;}
    else
    {
        c=p;
        while(c->b->urm) c=c->urm;
        c->b=i;
        c->urm=0;
    }
}

void marc(int i, nod*prim)
{int q;
nod *p;
p=prim;
nod *c;
    for(q=1;q<=i;q++) p=p->urm;
    while(p->b)
        {
            c=prim;
            for(q=1;q<=p->b;q++)
               c=c->urm;
            c->a--;
            p->b=p->b->urm;
        }
}

int main()
{int n,m,k,ok,d[100],i,j;
  nod *prim,*p;
    creare(prim);
    f>>n;
for(int q=1;q<=n;q++)
    {f>>i>>j;
    adaugare(i,j,prim);
    }
m=n;
do
    {
        k=1;
        ok=0;
        p=prim;
        for(i=1;i<=n;i++)
            if(!p->a)
        {
            ok=1;
            d[k]=i;
            k++;
            m--;
            p->a=-1;
        }
            else p=p->urm;
        for(i=1;i<k;i++)
            {marc(d[i],prim); g<<d[i]<<endl;}

    }
  //  while(ok&&m);
    //    if(m) g<<"Relatii contradictorii.";
    //else g<<"Ordinea este cea de mai sus.";
    return 0;
}
