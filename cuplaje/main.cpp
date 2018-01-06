#include <fstream>

using namespace std;
ifstream f("cuplaje.in");
ofstream g("cuplaje.out");
int n,m,a[200001],b[200001],i,nr;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
        {
            int cmin=99999;
            int val=0;
            for(int j=1;j<=a[i];j++)
                {
                    if(b[j]>0&&b[j]>=i&&b[j]<cmin) cmin=b[j],val=j;
                }
            if(val) b[val]=-1,nr++;
        }
    g<<nr;
    return 0;
}
