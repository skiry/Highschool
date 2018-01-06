#include <fstream>

using namespace std;
ifstream f("interviu.in");
ofstream g("interviu.out");
int a[100],n,i,ok;
int main()
{f>>n;
for(i=1;i<=n;i++) f>>a[i];
for(i=4;i<=n&&ok!=1;i++) if(a[i]>a[i-1]&&a[i]>a[1]&&a[i]>a[2]&&a[i]>a[3]) {ok=1;g<<i;}
if(!ok) g<<n;

    return 0;
}
