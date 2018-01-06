#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,a[100],i,j,nr1,nr;
int main()
{f>>n;
for(i=1;i<=n;i++)
f>>a[i];
for(i=1;i<=n;i++)
if(a[i]%2==0&&i!=1)
while(a[i-1]%2&&i!=1){swap(a[i-1],a[i]);i--; }
    for(i=1;i<=n;i++) g<<a[i]<<" ";




    return 0;
}
