#include <fstream>

using namespace std;
ifstream f("iepuri.in");
ofstream g("iepuri.out");
int n,i,x,y,k,v,c[100],u=1,pr=1;
long long s=1;
struct nod
{
    int nr,t,lv,gr,niv;
    nod *urm;
};
nod *l[101],*p,*q;
void creare(int n)
{
    for(int i=1;i<=n;i++)
    {
        p=new nod;
        p->nr=0;
        p->t=0;
        p->lv=0;
        p->gr=0;
        p->niv=0;
        p->urm=0;
        l[i]=p;
    }
}
void pune(int x,int y)
{
    if(!l[x]->nr)
      l[x]->nr=y;
    else
    {
        p=l[x];
        while(p->urm) p=p->urm;
        q=new nod;
        q->nr=y;
        q->urm=0;
        p->urm=q;
    }
    l[y]->t=x;
    l[x]->gr++;
}
void scadgrad(int b,int nr)
{
    if(l[b]->t)
        {if(l[b]->lv==k-nr+1) l[b]->lv--,nr++,scadgrad(l[b]->t,nr);}
    else if(!l[b]->t&&l[b]->lv==k-nr+1) l[b]->lv--;

}
void apel(int a)
{
    int nr=0;
    l[a]->lv=l[l[a]->t]->lv+1;
    if(l[a]->lv>k) scadgrad(a,nr);
}
int main()
{
    f>>n>>k;
    creare(n);
    for(i=1;i<n;i++)
    {
        f>>x>>y;
        pune(x,y);
    }
    for(i=1;i<=n;i++) if(!l[i]->t) v=i;
    l[v]->lv=k;
    l[v]->niv=1;
    for(p=l[v];p;p=p->urm)
        {
            l[p->nr]->niv=2;
            if(l[p->nr]->gr) c[u]=p->nr,u++;
            apel(p->nr);
        }
    while(pr<=u)
    {
        //g<<c[pr]<<" ";
            for(p=l[c[pr]];p;p=p->urm)
                {
                    l[p->nr]->niv=l[l[p->nr]->t]->niv+1;
                    if(l[p->nr]->gr)
                        c[u]=p->nr,u++;
                    apel(p->nr);
                }
        pr++;
    }
    //for(i=1;i<=n;i++) g<<i<<" ";g<<endl;
    //for(i=1;i<=n;i++) g<<l[i]->lv<<" ";g<<endl;
    //for(i=1;i<=n;i++) g<<l[i]->niv<<" ";
    for(i=1;i<=n;i++)
        s*=l[i]->lv-l[i]->niv+1,s%=30011;
    g<<s;
    g<<endl<<(1280000%30011)*(2458624&30011)*(314928%30011)%30011;
    return 0;
}
