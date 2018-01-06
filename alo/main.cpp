#include <fstream>

using namespace std;
ifstream f("alo.in");
ofstream g("alo.out");
int e,n,a[505],b[55],i;
int main()
{f>>e>>n;
for(i=1;i<=n;i++)
f>>a[i]>>b[i];

    for(i=1;i<=n;i++)
        if(a[i]%10==5&&a[i]/10000%10==1) e-=2*b[i];
   else if(a[i]%10==5&&a[i]/10000%10==2) e+=b[i];
    g<<e;


    return 0;
}
