#include <fstream>
///Se da un graf orientat cu n vârfuri si m arce prin lista arcelor si un varf k.
///Afisati varfurile din componenta tare conexa in care se afla varful k.
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int k,l,m,n,a[100][100],pf[100],ps[100];

void citire(int &n, int &m)
{
    int l,c,v;
    f>>n>>m;
    for(int i=1;i<=m;i++)
        {
            f>>l>>c;
            a[l][c]=1;
        }
}
void dfsuc(int nod)
{
    int k;
    pf[nod]=1;
    for(k=1;k<=n;k++)
    if(a[nod][k]==1 && pf[k]==0)
    dfsuc(k);
}

void dfpred(int nod)
{
    int k;
    ps[nod]=1;
    for(k=1;k<=n;k++)
    if(a[k][nod]==1 && ps[k]==0)
    dfpred(k);
}

int main()
{
    citire(n,m);
    f>>k;
    dfsuc(k);
    dfpred(k);
    for(int i=1;i<=n;i++)
        if(pf[i]*ps[i]==0) pf[i]=ps[i]=0;
    int t=0;
    for(int i=1;i<=n;i++)
    if(pf[i]) g<<i<<" ";

    return 0;
}
