#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int arb[1<<19],st,dr,m,em,n,i,poz,a,b,op,x;
void actualizare(int nod,int st,int dr)
{
    if(st>=poz&&dr<=poz)
    {
        arb[nod]=x;
        return;
    }
    int m=(st+dr)>>1;
    if(poz<=m) actualizare(nod<<1,st,m);
    else actualizare((nod<<1)+1,m+1,dr);
    arb[nod]=max(arb[nod<<1],arb[(nod<<1)+1]);
}
int interogare(int nod,int st,int dr)
{
    if(st>=a&&dr<=b) return arb[nod];
    int x1=0,x2=0,m;
    m=(st+dr)>>1;
    if(a<=m) x1=interogare(nod<<1,st,m);
    if(b>m) x2=interogare((nod<<1)+1,m+1,dr);
    return max(x1,x2);
}
int main()
{
    f>>n>>em;
    for(i=1;i<=n;i++)
    {
        f>>x;
        poz=i;
        actualizare(1,1,n);
    }
    for(i=1;i<=em;i++)
    {
        f>>op>>a>>b;
        if(!op) g<<interogare(1,1,n)<<'\n';
        else
        {
            poz=a;
            x=b;
            actualizare(1,1,n);
        }
    }
    return 0;
}
