#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],b[100][100],i,j,n,m,k,l,x,y,ok;
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y,a[x][y]=1;
    f>>k>>l;
    for(i=1;i<=l;i++)
        f>>x>>y,b[x][y]=1;
    for(i=1;i<=k;i++)
        for(j=1;j<=k;j++)
            if(b[i][j]&&!a[i][j]) ok=1;
    if(ok) g<<"Nu e subgraf";
    else g<<"E subgraf";
    return 0;
}
