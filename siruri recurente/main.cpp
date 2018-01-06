#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *p,*prim,*ultim,*ultim1;
int n,i;
int main()
{f>>n;
prim=new nod;
prim->nr=1;
p=new nod;
prim->urm=p;
p->nr=2;
p->urm=NULL;
ultim=p;
ultim1=prim;
i=3;g<<"1 2 ";
while(i<=n)
{p=new nod;
p->nr=(ultim->nr)*2+ultim1->nr;
p->urm=NULL;
ultim1=ultim;
ultim=p;
g<<p->nr<<" ";i++;
}

    return 0;
}
