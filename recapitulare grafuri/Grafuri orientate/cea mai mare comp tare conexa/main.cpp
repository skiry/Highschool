#include <fstream>
///Sa se afiseze varfurile care compun cea mai mare componenta tare conexa a grafului citit (cea care are cele mai multe varfuri)

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,nrc,pf[100],ps[100];

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

void dfsuc(int nod,int nrc)
{
    int k;
    pf[nod]=nrc;
    for(k=1;k<=n;k++)
    if(a[nod][k]==1 && pf[k]==0)
    dfsuc(k,nrc);
}

void dfpred(int nod,int nrc)
{
    int k;
    ps[nod]=nrc;
    for(k=1;k<=n;k++)
    if(a[k][nod]==1 && ps[k]==0)
    dfpred(k,nrc);
}


int main()
{
    citire(n,m);
    int k,mk=0,c,mc;
    nrc=1;
    for(int i=1;i<=n;i++)
    if(pf[i]==0)
    {
        dfsuc(i,nrc);
        dfpred(i,nrc);
        for(int j=1;j<=n;j++)
        if(pf[j]!=ps[j])
        pf[j]=ps[j]=0;
        nrc++;
    }

    for(int i=1;i<nrc;i++)
    {
        k=0;
        for(int j=1;j<=n;j++)
        if(pf[j]==i) k++;
        if(k>mk)
        {
            mk=k;
            mc=i;
        }
    }
    for(int j=1;j<=n;j++)
    if(pf[j]==mc)  g<<j<<" ";

    return 0;
}
