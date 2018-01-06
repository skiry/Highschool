#include <iostream>

using namespace std;
struct nod{int nr;
nod *urm;};
nod *p,*prim,*ultim;
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
  {if(p->nr>=0) s+=p->nr;
  p=p->urm;
  }
  cout<<s;
    return 0;
}
