#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *p,*q;
char n[100];
int i,k,x,l,a;
void creare(nod *&prim, nod *ultim)
{
    f.get(n,100);
    f>>l;
    k=strlen(n);
    prim=new nod;
    prim->nr=n[k]-'0';
    prim->urm=0;
    ultim=prim;
    for(i=1;i<=strlen(n);i++)
    {
        k--;
        p=new nod;
        p->nr=n[k]-'0';
        p->urm=0;
        ultim->urm=p;
        ultim=p;
    }
}
int main()
{
    nod *prim=0,*ultim;
    creare(prim,ultim);
   /** p=prim->urm;
    while(p) {g<<p->nr<<" ";p=p->urm;}
    g<<endl;*/
    p=prim->urm;
    while(p->urm)
    {
        x=p->nr*l+a;
        p->nr=x%10;
        a=x/10;
        p=p->urm;
    }
x=p->nr*l+a;
p->nr=x%10;
a=x/10;

        if(a)
        {
            q=new nod;
            q->nr=a;
            q->urm=0;
            p->urm=q;
        }
p=prim->urm;
while(p)
{
    g<<p->nr<<" ";
    p=p->urm;
}
    return 0;
}
