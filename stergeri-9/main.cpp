#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *p,*ultim,*prim;
int n,i,val;
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
    ultim=p;}
p=prim;
ultim=prim;
while(p)
{if(p->nr==val)
ultim->urm=p->urm;
ultim=p;
p=p->urm;
}
p=prim;
while(p)
    {g<<p->nr<<" ";
p=p->urm;}

    return 0;
}
