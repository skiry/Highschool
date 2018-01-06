#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,q,d,nr,p,ok;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>a[i][j];

    for(i=1;i<=n;i++)
    {{ok=1;
for(d=2;d<=a[i][1]/2&&ok==1;d++)
    if(a[i][1]%d==0) ok=0;}
    if(ok==1) for(j=1;j<=m/2;j++) swap(a[i][j],a[i][m+1-j]);}

for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    g<<a[i][j]<<" ";
return 0;
}
