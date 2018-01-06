#include <fstream>
#include <math.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int info;
nod *next;};
void pune(nod *&v,nod *&sf, int x)
{nod *c;
    if(!v){v=new nod;
           v->info=x;
           v->next=0;
           sf=v;}
    else {c=new nod;
          sf->next=c;
          c->info=x;
          sf=c;
          sf->next=0;}
}
void pp(nod*v)
{nod *c;
c=v;
    while(v)
{if(sqrt(c->info)==(int)sqrt(c->info)) g<<c->info<<" ";
v=v->next;
delete c;
c=v;
}}
int pal(int x)
{int k=x,j=0;
while(x){j=j*10+x%10; x=x/10;}
    if(k==j) return 1;
    return 0;
}
void palindrom(nod*v)
{nod *c;
c=v;
    while(v)
{if(pal(c->info)==1) g<<c->info<<" ";
v=v->next;
delete c;
c=v;
}}
int prim(int x)
{int ok=1;
for(int d=2;d<=x/2;d++)
    if(x%d==0) ok=0;
if(ok) return 1;
return 0;
}
void afisprim(nod*v)
{nod *c;
c=v;
    while(v)
{if(prim(c->info)==1) g<<c->info<<" ";
v=v->next;
delete c;
c=v;
}}
void par(nod *v)
{nod *c;
c=v;
    while(v)
{if(c->info%2==0) g<<c->info<<" ";
v=v->next;
delete c;
c=v;
}}
int main()
{nod *prim=NULL,*ultim=NULL;
int n,x;
f>>n;
for(int i=1;i<=n;i++)
{f>>x;
pune(prim,ultim,x);
}
///pp(prim);
///palindrom(prim);
afisprim(prim);
///par(prim);
    return 0;
}
