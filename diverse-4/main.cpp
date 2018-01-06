#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
int n,a[100],i;
nod *p,*ultim,*prim;
void citire()
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
ultim=p;
}}

int main()
{citire();
    p=prim;
i=1;
while(p)
{a[i]=p->nr;
p=p->urm;
i++;
}
for(i=1;i<=n;i++) g<<a[i]<<" ";

    return 0;
}
