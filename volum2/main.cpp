#include <fstream>

using namespace std;
ifstream f("volum.in");
ofstream g("volum.out");
int n,m,i,j;
unsigned long long a[753][753],b[753][753];
int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int main()
{
    unsigned long long maxim,rezultat;
    f>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        f>>a[i][j],maxim=max(maxim,a[i][j]);
    for(i=1;i<=n;i++)
        {for(j=1;j<=m;j++)
    {
        if(i==1||j==1||i==n||j==m) b[i][j]=0;
        else b[i][j]=maxim-a[i][j];
        };
    }
    int ok=1;
    while(ok)
    {
        ok=0;
        rezultat=0;
        for(i=2;i<n;i++)
            for(j=2;j<m;j++)
            if(b[i][j])
        {
            unsigned long long maxx=0;
            for(int k=0;k<4;k++)
                if(a[i+dl[k]][j+dc[k]]+b[i+dl[k]][j+dc[k]]<a[i][j]+b[i][j])
                    maxx=max(maxx,a[i+dl[k]][j+dc[k]]+b[i+dl[k]][j+dc[k]]);
            if(maxx)
            {
                maxx=max(maxx,a[i][j]);
                b[i][j]=maxx-a[i][j],ok=1;
            }
            rezultat+=b[i][j];
        }
    }

    g<<rezultat;
    return 0;
}
