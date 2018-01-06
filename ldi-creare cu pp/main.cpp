#include <fstream>
#include <math.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm,*prec;};

void pune(nod *&prim,int x)
{nod *p;
if(!prim){prim=new nod;
prim->nr=x;
prim->urm=0;
         }
else {p=new nod;
p->nr=x;
p->urm=prim;
prim=p;
}
}
void afisare(nod *prim)
{nod *p;
p=prim;
while(prim)
{g<<prim->nr<<" ";
prim=prim->urm;
delete p;
p=prim;
}
}
int main()
{nod *prim=NULL;
int x;
do{f>>x;
if(sqrt(x)==(int)sqrt(x)&&x)
    pune(prim,x);
  }while(x);
 afisare(prim);


    return 0;
}
