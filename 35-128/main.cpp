#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,q,k,nr,p=1;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>a[i][j];
   i=1;
   j=1;
   p=a[i+1][j]*a[i-1][j]*a[i][j-1]*a[i][j+1];
   g<<p;



    return 0;
}
