#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],i,j,k,n;
int main()
{f>>n;
   for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        f>>a[i][j];
   for(k=1;k<=(n+1)/2;k++)
   {for(i=k;i<=n-k+1;i++) g<<a[i][k]<<" ";
   for(j=k;j<=n-k+1;j++) g<<a[n-k+1][j]<<" ";
   for(i=n-k+1;i>=k;i--) g<<a[i][n-k+1]<<" ";
   for(j=n-k+1;j>=k+1;j--) g<<a[k][j]<<" ";

   }
    return 0;
}
