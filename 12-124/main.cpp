#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,s1,s2,s,p,q;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>a[i][j];
 for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
{s1=0;
s2=0;
s=0;
    for(p=1;p<=m;p++)
s1=s1+a[i][p];
for(q=1;q<=n;q++)
s2=s2+a[q][j];

if(s1==s2) g<<a[i][j]<<" ";
}
    return 0;
}
