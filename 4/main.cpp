#include <iostream>
#include <math.h>
using namespace std;
struct nod(int nr;
nod *urm;);
nod *p,*ultim,*prim;
int n,i,s;
int main()
{cin>>n;
prim=new nod;
cin>>prim->nr;
prim->urm=NULL;
ultim=prim;
for(i=2;i<=n;i++)
{p=new nod;
cin>>p->nr;
p->urm=NULL;
ultim->urm=p;
ultim=p;
}
p=prim;
while(p)
{if(sqrt(p->nr)==(int)sqrt(p->nr))
s+=p->nr;
p=p->urm;
}
    cout<<s;
    return 0;
}
