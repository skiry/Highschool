#include <fstream>

using namespace std;
ifstream f("concurs3.in");
ofstream g("concurs3.out");
int n,i,x,a[100],ok,o,s,nr;
int main()
{f>>x>>n;
for(i=1;i<=n;i++)
{f>>a[i];if(a[i]==x) ok=1;}
if(ok) g<<"DA";
else g<<"NU";
g<<endl;
o=x/100;
s=x/10%10;
for(i=1;i<=n;i++)
    if(a[i]/100==o) nr++;
g<<nr<<endl;
nr=0;
for(i=1;i<=n;i++)
    if(a[i]/10%10==s) nr++;
g<<nr;

    return 0;
}
