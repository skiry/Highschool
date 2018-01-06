#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100],k[100],i,j,n,b[100];
int main()
{f>>n;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=n;i++) k[i]=0;
for(j=1;j<n;j++)
    for(i=j+1;i<=n;i++)
    if(a[i]<a[j]) k[j]++;
else k[i]++;
for(i=1;i<=n;i++) b[k[i]+1]=a[i];
for(i=1;i<=n;i++) g<<k[i]<<" ";

    return 0;
}
