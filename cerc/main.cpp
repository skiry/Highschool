/**#include <fstream>
#include <math.h>
using namespace std;
ifstream f("cerc.in");
ofstream g("cerc.out");
int n,a,b,c,i,j,nr=1,ok=1;
float v1,v2;
struct lista
{
    float x,y;
    lista *urm;
};
lista *l[2000],*p,*q;
void cautare(float a,float b)
{
    int ok1=1;
    for(int i=1;i<nr;i++)
        if(l[i]->x==a&&l[i]->y==b) ok1=0;
        if(ok1)
        {
            nr++;
            l[nr]=new lista;
            l[nr]->x=a;
            l[nr]->y=b;
            l[i]->urm=0;
            l[nr-1]->urm=l[nr];
        }
}
int main()
{
   f>>n;
   for(i=1;i<=n;i++)
   {
       f>>a>>b>>c;
       if(a>b) v1=1,v2=a,v2/=b;
    else if(a<b) v2=1,v1=b,v1/=a;
    else if(a==b) v1=1,v2=1;
    if(ok)
    {
        l[1]=new lista;
        l[1]->x=v1;
        l[1]->y=v2;
        l[1]->urm=0;
    }
    if(!ok) cautare(v1,v2);
    ok=0;
   }
   g<<nr;
    for(i=1;i<nr;i++) g<<l[i]->x<<" "<<l[i]->y<<endl;
    return 0;
}
*/
#include <fstream>
#include <math.h>
using namespace std;
ifstream f("cerc.in");
ofstream g("cerc.out");
int a,b,c,n,v1,v2;
struct lista
{
    float x,y,z;
    lista *urm;
};
lista *l,*p,*q;
void pune(int a,int b,int c,lista *&l,int v,int w)
{
    int ok=1;
    if(!l)
    {
        l=new lista;
        l->x=a;
        l->y=b;
        l->z=c;
        l->urm=0;
    }
    else
    {
        p=l;
        while(p&&ok)
        {
            if(p) if(p->x==a&&p->y==b) ok=0,g<<v<<" "<<w<<endl;;
            p=p->urm;
        }
        if(ok)
        {
        q=new lista;
        q->x=a;
        q->y=b;
        q->z=c;
        q->urm=0;
        p->urm=q;
        }
    }
}
int main()
{
    lista *l=0;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b>>c;
        if(a>b) v1=1,v2=a,v2/=b;
    else if(a<b) v2=1,v1=b,v1/=a;
    else if(a==b) v1=1,v2=1;
        pune(v1,v2,c,l,a,b);
    }
    p=l;
    while(p) g<<p->x<<" "<<p->y<<" "<<p->z<<endl,p=p->urm;
    return 0;
}
