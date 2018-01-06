#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("dicsi.in");
ofstream g("dicsi.out");
int n,a[100001],maxim;
int main()
{
    f>>n;
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!a[i]) a[i]=2;
        if(2*i<=n) for(int j=2*i;j<=n;j+=i)
            if(!a[j]) a[j]=3;
        else if(a[i]==a[j]) a[j]++;
    }
    maxim=*max_element(a+1,a+n+1);
    g<<maxim<<'\n';
    for(int i=1;i<=n;i++) g<<a[i]<<" ";
    return 0;
}
