#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *p,*ultim,*prim;
int n,i,cmax,poz;
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
p=prim;
cmax=p->nr;
i=1;
while(p)
    {if(p->nr>=cmax)
        {cmax=p->nr;poz=i;}
    p=p->urm;i++;
    }
g<<cmax<<" "<<poz;
    return 0;
}
