#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *v,*prim,*ultim;
int n,a[200001],i;
long long m;
int main()
{
    f>>n>>m;
    v=new nod;
    v->nr=1;
    v->urm=0;
    prim=v;
    ultim=v;
    i=1;
    while(i<=m)
    {
        i++;
        v=new nod;
        v->nr=i;
        v->urm=0;
        ultim->urm=v;
        ultim=v;
    }
    for(i=1;i<=n;i++)
        {
            f>>a[i];
            v=prim;
            while(v->nr!=a[i]||v)
            {
                if(v->nr==a[i]) v->nr=0;
                v=v->urm;
            }
        }
    return 0;
}
