#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod {int nr;
nod*urm,*prec;};
void creare(nod*&prim)
{ int i,n;
nod*p,*ultim;
f>>n;
prim=new nod;
f>>prim->nr;
prim->urm=NULL;
prim->prec=NULL;
ultim=prim;
for(i=2; i<=n; i++) { p=new nod;
f>>p->nr;
p->urm=NULL;
p->prec=ultim;
ultim->urm=p;
ultim=p;}
}
int ordon(nod*prim)
{ nod*p;
p=prim;
while(p->urm)
    {if(p->nr>p->urm->nr)  return 0;
    p=p->urm;}
    return 1;
}

int main()
{ nod*prim,*ultim;
creare(prim);
if(ordon(prim)==1) g<<"da";
else g<<"nu";
return 0;
}
