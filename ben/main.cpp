#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("ben.in");
ofstream g("ben.out");
int n,i,start,nr,maxim;
struct el
{
    int sos,plec;
}a[30001];
inline bool cmp(const el &b,const el &c)
{
    return b.sos<c.sos;
    return b.plec<c.plec;
};
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i].sos>>a[i].plec;
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;)
    {
        nr=0;
        start=i;
        while(a[i].sos<a[start].plec&&i<=n) i++,nr++;
        maxim=max(nr,maxim);
    }
    g<<maxim<<" "<<maxim*2;
    return 0;
}
