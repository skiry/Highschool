#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod
{
    int nr,val,grad=0,viz=0;
    nod *urm;
};
nod *p,*q,*a[200001];
int n,m,b,i,j,x,y,z,maxim,c[200001],prim,ultim,nodul;
void pune(int x,int y,int z)
{
    p=new nod;
    p->nr=y;
    p->val=z;
    p->urm=0;
    if(!a[x])
        a[x]=p;
    else
    {
        q=a[x];
        while(q->urm)
            q=q->urm;
        q->urm=p;
    }
}
int main()
{
    f>>n>>m>>b;
    for(i=1;i<=m;i++)
        f>>x>>y>>z,pune(x,y,z),pune(y,x,z),a[x]->grad++,a[y]->grad++;
        if(a[b])
        {

    prim=ultim=1;
    c[1]=b;
    while(prim<=ultim)
    {
        p=a[c[prim]];
        p->viz=1;
        while(p)
        {
            if(!a[p->nr]->viz)
                c[++ultim]=p->nr;
            p=p->urm;
        }
        prim++;
    }
    for(i=1;i<=n;i++)
        if(a[i]->grad>maxim&&a[i]->viz) maxim=a[i]->grad,nodul=i;;
    p=a[b];
    while(p)
    {
        if(p->nr==nodul) maxim--;
        p=p->urm;
    }
    if(n==1) g<<"1";
    else
        g<<maxim;
        }
        else g<<"0";
    return 0;
}
