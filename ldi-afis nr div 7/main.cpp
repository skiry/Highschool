#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm,*prec;};

void creare(nod *&prim)
{nod *p,*ultim;
int n;
f>>n;
prim=new nod;
f>>prim->nr;
prim->urm=0;
prim->prec=0;
ultim=prim;
for(int i=2;i<=n;i++)
    {p=new nod;
    f>>p->nr;
    p->urm=0;
    p->prec=ultim;
    ultim->urm=p;
    ultim=p;
    }
}

void afisare(nod *prim)
{nod *p;
p=prim;
while(p)
{if(p->nr%7==0) g<<p->nr<<" ";
p=p->urm;
}
}
int main()
{
    nod*prim;
    creare(prim);
    afisare(prim);

    return 0;
}
