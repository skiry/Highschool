#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *p,*ultim,*prim;
int n,i,ok=1;
int main()
{f>>n;
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

while(ok)
{p=prim;
ok=0;
while(p->urm)
    {if(p->nr<p->urm->nr)
        {swap(p->nr,p->urm->nr); ok=1;}p=p->urm;
    }}
p=prim;
while(p) {g<<p->nr<<" ";p=p->urm;}
    return 0;
}
