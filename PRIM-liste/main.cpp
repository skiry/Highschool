#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
int val;
nod *urm;};
nod *a[100],*p,*q;
int n,m,i,x,y,z,viz[100],nr,s[100],t[100],k,l,v,j,cost,minim;
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
void afisare()
{
    for(i=1;i<=n;i++)
        g<<s[i]<<" ";
    g<<endl;
    for(i=1;i<=n;i++)
        g<<t[i]<<" ";
    g<<endl;

    for(i=1;i<=n;i++)
    {
        p=a[i];
        while(p)
        {
            g<<p->nr<<" "<<p->val<<endl;
            p=p->urm;
        }
        g<<endl;
    }
}
int cauta_nod(int &nod)
{
    int minim=99999;
    for(int i=1;i<=n;i++)
       if(s[i]!=0)
         {
             p=a[i];
             while(p)
             {
                 if(p->nr==s[i]&&p->val<minim)
                 {
                     minim=p->val;
                     nod=i;
                     break;
                 }
                 p=p->urm;
             }
         }
return minim;
}
void actualizeaza(int nod)
{
    for(int i=1;i<=n;i++)
        if(s[i])
        {
            p=a[i];
            while(p)
            {
                if(p->nr==s[i]) k=p->val;
                if(p->nr==nod) l=p->val;
                p=p->urm;
            }
            if(k>l) s[i]=nod;
        }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        {
            f>>x>>y>>z;
            pune(x,y,z);
            pune(y,x,z);
        }
    f>>v;
    for(i=1;i<=n;i++)
    {
        p=a[i];
        while(p)
        {
            viz[p->nr]=1; ///pentru a verifica nodurile catre care nu exista muchie directa
            nr++;
            if(p->urm) p=p->urm;
            else break;
        }
        if(nr!=n)
        {
            for(j=1;j<=n;j++)
                if(!viz[j]&&j!=i) ///adaugam nodurile nevizitate, diferite de nodul i
                {
                    q=new nod;
                    q->nr=j; ///introducem nodul j cu lungimea drumului=99999
                    q->val=99999;
                    q->urm=0;
                    p->urm=q;
                    p=q;
                }
        }
        for(j=1;j<=n;j++)
            viz[j]=0;
        nr=0;
    }

    for(i=1;i<=n;i++)
        if(i!=v) s[i]=v;
    s[v]=0;

    int nod;
    for(k=1;k<=n;k++)
    {
        minim=cauta_nod(nod);
        t[nod]=s[nod];
        cost=cost+minim;
        s[nod]=0;
        actualizeaza(nod);
   }
   g<<"Costul : "<<cost<<endl;
   for(i=1;i<=n;i++)
    g<<t[i]<<" ";
    g<<endl;
    return 0;
}
