#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,s1,s2,s,p,q,d[100],cmax;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>a[i][j];
 for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
 { d[a[i][j]]++;
 if(a[i][j]>cmax) cmax=a[i][j];
 }
    for(i=1;i<cmax;i++)
        for(j=i+1;j<=cmax;j++)
        if(d[i]>=d[j]) swap(d[i],d[j]);
    for(i=1;i<cmax;i++) if(d[i]) g<<d[i]<<" ";
    return 0;
}
