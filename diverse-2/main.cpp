#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod  *p,*ultim,*prim;
int n,m;
void citire()
{f>>n;
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
void creare()
{p=prim;
while(p)
{m=m*10+p->nr;
p=p->urm;
}}

int main()
{
citire();
   creare();
   g<<m;
    return 0;
}
