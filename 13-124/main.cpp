#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,s1,s2;
int main()
{f>>n;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    f>>a[i][j];
 for(i=1;i<n;i++)
 for(j=2;j<=n;j++)
    if(j-i==1) s1=s1+a[i][j];
     for(i=2;i<=n;i++)
 for(j=1;j<n;j++)
    if(i-j==1) s2=s2+a[i][j];
g<<s1+s2;


    return 0;
}
