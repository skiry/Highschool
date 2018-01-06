#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,a[100],b[100],i,j,m;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)f>>a[i];
for(i=1;i<=m;i++)f>>b[i];
for (i=1;i<=n;i++) for(j=1;j<=m;j++){g<<a[i]<<" "<<b[j]; g<<endl;}
    return 0;
}
