#include <fstream>
#include <math.h>
using namespace std;
ifstream f("date.in");
ofstream g("af.out");
struct nod{int a;
int b;
nod *urm;};
void creare(nod *&prim,int &x)
{
    nod *p,*ultim;
    int n;
    f>>n>>x;
    prim=new nod;
    f>>prim->a>>prim->b;
    prim->urm=0;
    ultim=prim;
    for(int i=2;i<=n;i++)
        {
            p=new nod;
            f>>p->a>>p->b;
            p->urm=0;
            ultim->urm=p;
            ultim=p;
        }
}

void afisare(nod *prim,int x)
{int z=0;
    nod *p;
    g<<"P(x)=";
    p=prim;
    while(p)
    {
       if(p->a>0) g<<"+";
        else g<<"-";
       g<<p->a<<"X^"<<p->b;
       p=p->urm;
    }
    g<<endl;
    p=prim;
    while(p)
    {
        g<<(p->a)*pow(x,p->b);
        if(p->urm) g<<"+";
        else g<<"=";
        z=z+(p->a)*pow(x,p->b);
        p=p->urm;
    }
    g<<z;
}
int main()
{nod *prim;
int x;
creare(prim,x);
afisare(prim,x);
g<<endl<<prim->a*pow(x,prim->b);
    return 0;
}
