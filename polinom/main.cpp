#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int a;
int b;
nod *urm;};
void creare(nod *&prim)
{
    nod *p,*ultim;
    int n;
    f>>n;
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

void afisare(nod *prim)
{
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
}
int main()
{nod *prim;
creare(prim);
f>>x;

afisare(prim);

    return 0;
}
