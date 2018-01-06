#include <fstream>
#include <vector>
using namespace std;
ifstream f("secv2.in");
ofstream g("secv2.out");
int n,k,i,el,poz=0,fin,maxim=-9999999,ind,a[500001];
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
        a[i]+=a[i-1];
    }
    for(i=k;i<=n;i++)
    {
        if(a[poz]>a[i-k]) poz=i-k;
        if(a[i]-a[poz]>maxim) maxim=a[i]-a[poz],ind=poz+1,fin=i;
    }
    g<<ind<<" "<<fin<<" "<<maxim;
    return 0;
}
