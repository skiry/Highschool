#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{char x;
nod *urm;};

void citire(nod *&prim)
{nod *p,*ultim;
prim=new nod;
f>>prim->x;
prim->urm=NULL;
ultim=prim;
while((ultim->x)!='*')
{p=new nod;
f>>p->x;
p->urm=NULL;
ultim->urm=p;
ultim=p;
}}

void creare(nod *prim, nod *&prim1,nod *&prim2)
{nod *p,*q,*ultim1,*j,*ultim2;
p=prim;
while(p)
{if((p->x)>='A'&&(p->x)<='Z')
{if(prim1==NULL)
    {prim1=new nod;
    prim1->x=p->x;
     prim1->urm=NULL;
     ultim1=prim1;
    }
else {q=new nod;
q->x=p->x;
q->urm=NULL;
ultim1->urm=q;
ultim1=q;}
}
else if((p->x)>='a'&&(p->x)<='z')
{if(prim2==NULL)
    {prim2=new nod;
    prim2->x=p->x;
     prim2->urm=NULL;
     ultim2=prim2;
    }
else {j=new nod;
j->x=p->x;
j->urm=NULL;
ultim2->urm=j;
ultim2=j;}
}
p=p->urm;
}
}

void afisare(nod *prim)
{nod *p;
p=prim;
while(p)
{g<<p->x<<" ";
p=p->urm;
}
}
int main()
{nod *prim,*prim1=NULL,*prim2=NULL;
    citire(prim);
    afisare(prim);
    creare(prim,prim1,prim2);
    g<<endl;
    afisare(prim1);
    g<<endl;
    afisare(prim2);
    return 0;
}

