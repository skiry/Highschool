#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};

void creare(nod *&prim,int &n)
{int i;
nod *p,*ultim;
f>>n;
prim=new nod;
f>>prim->nr;
prim->urm=NULL;
ultim=prim;
for(i=2;i<=n;i++)
{p=new nod;
f>>p->nr;
p->urm=NULL;
ultim->urm=p;
ultim=p;}
ultim->urm=prim;
}
void stergere(nod *prim,int n)
{int k,j=1,i=1,ok=1; nod *p;
f>>k;
p=prim;
while(i!=n+1)
{ok=1;
if((j+1)%k==0)
{g<<p->urm->nr<<endl;
p->urm=p->urm->urm;
i++;ok=0;}
j++;if(ok)p=p->urm;
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
{nod *prim; int n;
creare(prim,n);
stergere(prim,n);

    return 0;
}
