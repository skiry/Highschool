/** NORMAL

#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100],l[100],ant[100],n,i,x,k,max1,poz,lmax,pmax;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
    l[1]=1;
    ant[1]=0;
    for(k=2;k<=n;k++)
    {
        max1=poz=0;
        x=a[k];
        for(i=1;i<k;i++)
            if(x>a[i]&&l[i]>max1)
                max1=l[i],poz=i;
        l[k]=max1+1;
        ant[k]=poz;
        if(lmax<l[k]) lmax=l[k],pmax=k;
    }
    for(i=pmax;i;i=ant[i]) g<<a[i]<<" ";

    return 0;
}
**/



/// CU LISTE



#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;
nod *prec;};
nod *p;
int n,i,k,x,max1,poz,lmax,pmax;
nod *ant,*l,*a;
void apel(int pmax)
   {
       nod *p,*q;
       p=a,q=ant;
       for(i=1;i<pmax;i++)
        p=p->urm,q=q->urm;
        if(q->nr) apel(q->nr);
       g<<p->nr<<" ";
   }
void creare(nod *p,nod *&a,nod *ultim)
{
    a=new nod;
    f>>a->nr;
   // a->urm=a->prec=0;
    ultim=a;
    for(int i=2;i<=n;i++)
        p=new nod, f>>p->nr, ultim->urm=p, p->prec=ultim, ultim=p;

}
void creare1(nod *p,nod *&a,nod *ultim)
{
    a=new nod;
   // a->urm=a->prec=0;
    a->nr=0;
    ultim=a;
    for(int i=2;i<=n;i++)
        p=new nod, p->urm=0, p->prec=ultim, ultim->urm=p, p->nr=0, ultim=p;

}
int main()
{
    nod *p,*q,*ultiml,*ultimant,*ultim;
    f>>n;
    creare(p,a,ultim);
    creare1(p,l,ultiml);
    creare1(p,ant,ultimant);
    for(k=2;k<=n;k++)
    {
        max1=poz=0;
        p=a;
        for(int j=1;j<k;j++)
            p=p->urm;
        x=p->nr;
        for(i=1;i<k;i++)
        {
            p=a;
            q=l;
            for(int j=1;j<i;j++)
                p=p->urm,q=q->urm;
            if(x>p->nr&&q->nr>max1)
                max1=q->nr,poz=i;
        }
        l->nr=max1+1;
        l->prec=ultiml;
        ultiml->urm=l;
        ultiml=l;
        ant->nr=poz;
        ant->prec=ultimant;
        ultimant->urm=ant;
        ultimant=ant;
        if(max1>lmax) lmax=max1,pmax=k;
    }

apel(pmax);
    return 0;
}
