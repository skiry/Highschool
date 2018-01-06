#include <fstream>

using namespace std;
ifstream f("snowball.in");
ofstream g("snowball.out");
int n,m,a[10001],b[500001],viz[10001],i,j,nr,maxim,nrviz;
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++) f>>a[i],viz[++nrviz]=a[i];
    for(i=1;i<=n;i++) f>>b[i];
    for(i=1;i<=n;i++)
    {
        int val=1;
        for(j=i;j<=n&&val<=nrviz;j++)
        {
            if(b[j]==viz[val]) val++;
            if(val<=nrviz) nr++;
        }
        maxim=max(maxim,j-i);
    }
    g<<maxim<<" "<<nr;
    return 0;
}
