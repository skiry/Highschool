#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("dlboss.in");
ofstream g("dlboss.out");
int n,timp,rez[100001];
struct fete
{
    int t,c,in;
};
fete a[100001];
inline bool cmp(const fete &b,const fete &c)
{
    return b.t<c.t;
}
int main()
{
    f>>n>>timp;
    for(int i=1;i<=n;i++) f>>a[i].t>>a[i].c,a[i].in=i;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        int maxf=a[i].c,timpact=timp,nr=0;
        for(int j=1;j<=n&&timpact>0;j++)
            if(j!=i&&a[j].c>maxf)
            {
                maxf=a[j].c,timpact-=a[j].t;
                if(timpact>=0) nr++;
            }
            else if(j!=i&&a[j].c<maxf&&a[j].c>a[i].c)
            {
                timpact-=a[j].t;
                if(timpact>=0) nr++;
            }
        rez[a[i].in]=nr;
    }
    for(int i=1;i<=n;i++) g<<rez[i]<<'\n';
    return 0;
}
