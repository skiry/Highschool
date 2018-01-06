#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,j,i,s;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) f>>a[i][j];
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) if(a[i][j]%2==0) s=s+a[i][j];
g<<s;

    return 0;
}
