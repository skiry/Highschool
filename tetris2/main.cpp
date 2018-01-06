#include <fstream>
#include <set>
using namespace std;
ifstream f("tetris2.in");
ofstream g("tetris2.out");
int n,m,a[505][505],b[101][101],i,j,nr;
set <int> v[10];
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        f>>a[i][j];
    f>>m;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        f>>b[i][j];
    for(i=1;i<=n-m+1;i++)
        for(j=1;j<=n-m+1;j++)
    {
        int ok=0,s=a[i][j]+b[i][j];
        for(int k=i;k<=i+m-1&&!ok;k++)
            for(int l=j;l<=j+m-1&&!ok;l++)
            if(a[k][l]+b[k-i+1][l-j+1]!=s) ok=1;
        if(!ok) nr++;
    }
    g<<nr;
    return 0;
}
