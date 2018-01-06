#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *a[100];
void pune(int x,int y)
{
    nod *q,*c;
    q=new nod;
    q->nr=y;
    q->urm=0;
    if(!a[x])
        a[x]=q;
    else
    {
        c=a[x];
        while(c->urm)
            c=c->urm;
        c->urm=q;
    }
}
int main()
{
    int n,x,y,i;
    f>>n;
    while(f>>x>>y)
        pune(x,y), pune(y,x);

    for(i=1;i<=n;i++)
        {
            while(a[i])
                {
                    g<<a[i]->nr<<" ";
                    a[i]=a[i]->urm;
                }
            g<<endl;
        }
    return 0;
}
