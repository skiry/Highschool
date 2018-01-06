#include <fstream>
///Se citeste un graf orientat cu n varfuri si m arce prin lista arcelor. Se da numar natural k mai mic decat n si k varfuri
///ale grafului. Afisati toate drumurile elementare care au ca extremitate initiala varful 1, ca extremitate finala varful n
///si care trec prin cele k varfuri citite in ordinea in care au fost citite.
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[50][50],n,m,k,x[50],p[50],viz[50],b[50];


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
void afis(int n)
{
    for(int i=1;i<=n;i++) g<<x[i]<<" ";
    g<<endl;
}

int bun(int pas)
{
    if(p[x[pas]]>=2)
        for(int i=1;i<=k;i++)
            if(p[b[i]]>0 && p[b[i]]<p[x[pas]] && !viz[b[i]]) return 0;
    return 1;
}

int sol(int pas)
{
    for(int i=1;i<=k;i++)
        if(!viz[b[i]]) return 0;
    return 1;
}

void backt(int k, int pas)
{
    for(int i=1;i<=n;i++)
    if(!viz[i] && a[x[pas-1]][i])
    {
        x[pas]=i;
        viz[i]=1;
        if(bun(pas))
            if(x[pas]==n && sol(pas)) afis(pas);
                else backt(k,pas+1);
        viz[i]=0;
    }
}


int main()
{
    citire(n,m);
    f>>k;
    for(int i=1;i<=k;i++)
        f>>b[i],p[b[i]]=i;

    x[1]=1;
    viz[1]=1;
    backt(k,2);


    return 0;
}
