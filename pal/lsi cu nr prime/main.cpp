#include <fstream>
#include <cmath>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod { int nr;
             nod *urm;
            };

int n;
void pune(nod *&prim, nod *&ultim, int x)
{
    nod *p;
    if(!prim)
    {
    prim = new nod;
    prim->nr = x;
    prim->urm = NULL;
    ultim = prim;
    }
    else
    {
        p = new nod;
        ultim -> urm = p;
        p->nr =x;
        ultim = p;
        ultim -> urm = NULL;
    }
}
int prime (int x)
{
    int a = x;
    for (int d = 2 ; d <= sqrt(a); d++)
        if(a%d == 0) return 0;
        return 1;
}
int palindrom (int x)
{
    int a = x; int pal = 0;
    while (a)
    {
        pal = pal*10+a%10;
        a = a/10;
    }
    if ( pal == x) return 1;
        return 0;
}
void afis(nod *prim)
{

   nod* p; p = prim;
    while (p)
    {
        g << p -> nr << " ";
        p = p ->urm;
    }
}

int main()
{
   nod *prim=NULL,*ultim;
   int n,i,x;
   f>>n;
   for(i=1;i<=n;i++)
   {
       f>>x;
       //if(prime(x)==1) pune(prim,last,x);
       if(palindrom(x)==1) pune(prim,ultim,x);
   }
   afis(prim);
    return 0;
}
