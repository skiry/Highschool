#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,i,j,s1,s2,s3,s4;
int main()
{f>>n;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    f>>a[i][j];
  for(i=1;i<=n/2;i++)
    for(j=2;j<n;j++)
    s1=s1+a[i][j];

        for(i=2;i<n;i++)
    for(j=1;j<=n/2;j++)
s2=s2+a[i][j];
    for(i=2;i<n-1;i++)
    for(j=n/2;j<=n;j++)
s3=s3+a[i][j];
    for(i=n-1;i<=n;i++)
    for(j=2;j<n;j++)
        s4=s4+a[i][j];
    g<<s1<<" "<<s2<<" "<<s3<<" "<<s4;
    return 0;
}
