#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *p,*prim,*ultim;
int n,m,c;
int main()
{f>>n;
while(n)
{c=n%10;
n/=10;
m=m*10+c;
}
prim=new nod;
prim->nr=m%10;
m/=10;
prim->urm=NULL;
ultim=prim;
while(m)
{p=new nod;
p->nr=m%10;
m/=10;
p->urm=NULL;
ultim->urm=p;
ultim=p;
}
p=prim;
while(p)
{g<<p->nr<<" ";
p=p->urm;
}
return 0;
}
