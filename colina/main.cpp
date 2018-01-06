#include <fstream>

using namespace std;
ifstream f("colina.in");
ofstream g("colina.out");
int n,m,o,a[10000],b[80000],ok,j,i;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    f>>a[i];
for(i=1;i<=m;i++)
    f>>b[i];
for(i=1;i<=m;i++)
{ok=0;
for(j=1;j<=n;j++)
if(b[i]==a[j])
    { if(ok==0) {g<<"DA ";ok=1;}
g<<j<<" ";
}
if(ok==0) g<<"NU";
g<<endl;}
    return 0;
}
