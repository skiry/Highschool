#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};

void citire(nod *&prim)
{nod *p,*ultim;int n;
prim=new nod;
prim->nr=1;
prim->urm=NULL;
ultim=prim;
for(int i=1;i<=n;i++)
{p=new nod;
p->nr=i;
p->urm=NULL;
ultim->urm=p;
ultim=p;
}}

void stergere(nod *prim)
{nod *p;int k,n;
f>>k;
p=prim;
for(int i=1;i<n;i++)
{if(k%(i+1)==0||(i+1)%k==0)
    {g<<p->urm->nr<<endl;p->urm=p->urm->urm;
    }p=p->urm;
}
}
void afisare(nod *prim)
{nod *p;
p=prim;
while(p)
{g<<p->nr<<" ";
p=p->urm;
}
}
int main()
{nod *prim;
citire(prim);
//stergere(prim);
afisare(prim);

    return 0;
}
