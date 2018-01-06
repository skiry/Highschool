#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
void creare(nod *&prim)
{nod *p,*ultim;
int n;
f>>n;
prim=new nod;
f>>prim->nr;
prim->urm=NULL;
ultim=prim;
for(int i=2;i<=n;i++)
{p=new nod;
f>>p->nr;
p->urm=NULL;
ultim->urm=p;
ultim=p;
}}

int prim1(int x)
{int ok=1;
for(int i=2;i<=x/2&&ok;i++)
    if(x%i==0) {ok=0;return 0;}
    return 1;}

void inlocuire(nod *prim)
{nod *p;
p=prim;
while(p)
{if(prim1(p->nr)) p->nr=p->nr+1;
p=p->urm;
}}

void afisare(nod *prim)
{nod *p;
p=prim;
while(p)
{g<<p->nr<<" ";
p=p->urm;}
}

int main()
{nod *prim;
creare(prim);
inlocuire(prim);
afisare(prim);

    return 0;
}
