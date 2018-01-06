#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("overdrive.in");
ofstream g("overdrive.out");
int n,i;
unsigned long long a[33],s,maxim;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i],s+=a[i];
    if(s%2) s=s/2+1;
    else s/=2;
    maxim=*max_element(a+1,a+n+1);
    g<<max(s,maxim);
    return 0;
}
