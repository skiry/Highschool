#include <fstream>

using namespace std;
ifstream f("arme.in");
ofstream g("arme.out");
int a[99999],n,m,i,s,j;
int main()
{f>>n>>m;
for(i=1;i<=n+m;i++)f>>a[i];

for(i=1;i<n+m;i++)
    for(j=i+1;j<=n+m;j++)
    if(a[i]<a[j]) swap (a[i],a[j]);

    for(i=1;i<=n;i++) s+=a[i];
    g<<s;
    return 0;
}
