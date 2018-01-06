#include <fstream>
#include <math.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *vf,*p;
int n,i;
void creare()
{f>>n;
vf=new nod;
f>>vf->nr;
vf->urm=NULL;
for(i=2;i<=n;i++)
{p=new nod;
f>>p->nr;
p->urm=vf;
vf=p;
}}
void pp()
{while(vf)
{p=vf;
if(sqrt(vf->nr)==(int)sqrt(vf->nr)) g<<vf->nr<<" ";
vf=vf->urm;
delete p;
}}
int pal(int x)
{int k=x,j=0;
while(x){j=j*10+x%10; x=x/10;}
    if(k==j) return 1;
    return 0;
}
void palindrom()
{while(vf)
{p=vf;
if(pal(vf->nr)==1) g<<vf->nr<<" ";
vf=vf->urm;
delete p;
}}
int prim(int x)
{int ok=1;
for(int d=2;d<=x/2;d++)
    if(x%d==0) ok=0;
if(ok) return 1;
return 0;
}
void afisprim()
{while(vf)
{p=vf;
if(prim(vf->nr)==1) g<<vf->nr<<" ";
vf=vf->urm;
delete p;
}}
void par()
{while(vf)
{p=vf;
if(vf->nr%2==0) g<<vf->nr<<" ";
vf=vf->urm;
delete p;
}}
int main()
{
    creare();
//pp();
//palindrom();
afisprim();
//par();
    return 0;
}
