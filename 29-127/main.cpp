#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,q,k,nr;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>a[i][j];



for(i=1;i<=n;i++)
    for(j=1;j<m;j++)
    for(k=j+1;k<=m;k++)
    if (a[i][j]>a[i][k])

            swap(a[i][j],a[i][k]);
    for(i=1;i<=m;i++)
        for(j=1;j<n;j++)
        for(k=j+1;k<=n;k++)
        if (a[j][i]>a[k][i])
         swap(a[j][i],a[k][i]);


for(i=1;i<=n;i++)
    {for(j=1;j<=m;j++)
    g<<a[i][j]<<" ";
    g<<'\n';}






    return 0;
}
