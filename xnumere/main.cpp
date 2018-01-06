#include <fstream>

using namespace std;
ifstream f("xnumere.in");
ofstream g("xnumere.out");
int x,k,n,a[10],sol[10],viz[1000],rezultat;
void backt(int nr)
{
    if(nr==n+1)
    {
        int valoare=0;
        for(int l=1;l<=10;l++) if(viz[l]) valoare++;
        if(valoare==x) rezultat++;
    }
    if(nr<=n)
    for(int i=1;i<=k;i++)
    {
        sol[nr]=a[i];
        viz[a[i]]++;
        backt(nr+1);
        viz[a[i]]--;
    }
}
int main()
{
    f>>k>>x>>n;
    for(int i=1;i<=k;i++) a[i]=i;
    backt(1);
    g<<rezultat;
    return 0;
}
