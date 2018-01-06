#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,x,y,i,j,ok,v[100],a[100][100];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>v[i];
    for(i=1;i<=m;i++)
        f>>x>>y,a[x][y]=a[y][x]=1;
    for(i=1;i<=n;i++)
        if(v[i]==1)
            for(j=1;j<=n;j++)
                if(a[i][j]&&v[a[i][j]]!=1) ok=1;
    if(ok) g<<"Nu e bipartit";
    else g<<"E bipartit";
    return 0;
}
