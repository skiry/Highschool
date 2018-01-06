#include <fstream>
///Se citeste un graf orientat cu n varfuri si m arce prin lista arcelor. Se citeste apoi un numar natural k mai mic decat n.

///a) Afisati toate subgrafurile cu k varfuri ale subgrafului dat.
///b) Afisati numarul maxim de arce ale unui subgraf cu k varfuri ale grafului dat.
///c) Afisati cate dintre subgrafurile cu k varfuri ale subgrafului dat sunt complete.

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100], x[100],k,n,m,maxa=0,cc=0;

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
void afis(int k)
{
    int i,j,c=0,ok=1;
    g<<"varfuri: ";
    for(i=1;i<=k;i++) g<<x[i]<<" ";
    g<<endl<<"arce: ";
    for(i=1;i<=k;i++)
        for(j=1;j<=k;j++)
            if(a[x[i]][x[j]])
            {
                g<<"("<<x[i]<<","<<x[j]<<") ";
                c++;
            }
    g<<endl;
    if(c>maxa) maxa=c;
    for(i=1;i<=k;i++)
        for(j=i+1;j<=k;j++)
            if(a[x[i]][x[j]]+a[x[j]][x[i]]==0) ok=0;
    if(ok) cc++;
}

void backt(int k, int pas)
{
    for(int i=x[pas-1]+1;i<=n;i++)
    {
        x[pas]=i;
        if(pas==k) afis(k);
        else backt(k,pas+1);
    }
}

int main()
{
    citire(n,m);
    f>>k;
    backt(k,1);
    g<<"maxim de arce: "<<maxa<<endl;
    g<<"numar de subgrafuri complete: "<<cc;

    return 0;
}
