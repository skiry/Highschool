#include <fstream>

using namespace std;
ifstream f("bancomat.in");
ofstream g("bancomat.out");
int n,i,a[1005],s;
int main()
{f>>s>>n;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=n;i++)
   if(a[i]%10==2) s+=a[i]/10;
else if(a[i]%10==3&&a[i]/10<=s) s-=a[i]/10;
g<<s;

    return 0;
}
