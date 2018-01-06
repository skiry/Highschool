#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("carnati.in");
ofstream g("carnati.out");
struct el
{
    int h,b;
};
el a[2001];
inline bool cmp(const el &d,const el &c)
{
    return d.h<c.h;
}
int n,c,i,j,sol[2001],rezultat;
int main()
{
    f>>n>>c;
    for(i=1;i<=n;i++) f>>a[i].h>>a[i].b;
    sort(a+1,a+n+1,cmp);
    a[0].h=a[1].h-1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            sol[j]=0;
            if(a[j].b>=a[i].b) sol[j]=max(sol[j-1]-(a[j].h-a[j-1].h)*c+a[i].b,a[i].b-c);
            else sol[j]=max(sol[j-1]-(a[j].h-a[j-1].h)*c,-c);
            rezultat=max(rezultat,sol[j]);
        }
    }
    g<<rezultat;
    return 0;
}
