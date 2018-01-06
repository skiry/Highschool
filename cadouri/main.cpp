#include <fstream>

using namespace std;
ifstream f("cadouri.in");
ofstream g("cadouri.out");
int d,b,n,a[100],nr1,nr2,i;
int main()
{f>>d>>b>>n;
for(i=1;i<=n;i++)
    f>>a[i];
   for(i=1;i<=n;i++) if(a[i]%2) nr1++;
else nr2++;
if(nr2>d) g<<"0";
else g<<d-nr2;
g<<'\n';
if(nr1>b) g<<"0";
else g<<b-nr1;
    return 0;
}
