#include <fstream>

using namespace std;
ifstream f("foto.in");
ofstream g("foto.out");
int n,m,l,cmax,a[100][100],j,k,i;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>a[i][j];

for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
{if(a[i][j]==0)
{k++;
l=0;
a[i][j]=k;
l++;
fill(i-1,j,k);
fill(i+1,j,k);
fill(i,j-1,k);
fill(i,j+1,k);
if(l>cmax) cmax=l;
}
}
 g<<cmax;
    return 0;
}
