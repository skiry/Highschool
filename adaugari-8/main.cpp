#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *p,*prim,*ultim,*q;
int n,val,i;
int main()
{f>>n>>val;
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
}
p=prim;
while(p)
{if(p->nr==val)
    {q=new nod;
    q->nr=-1;
    q->urm=p->urm;
    p->urm=q;
    }
 p=p->urm;
}
p=prim;
while(p)
{g<<p->nr<<" ";
p=p->urm;
}
    return 0;
}
