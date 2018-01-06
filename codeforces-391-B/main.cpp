#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,n,a[100001],v[100001],maxim,j;
int gcd(int a,int b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
    sort(a,a+n+1);
     for(i=1;i<=n;i++)
     {
         int minim=0;
        for(j=i-1;j>=1;j--)
            if(gcd(a[i],a[j])!=1&&gcd(a[i],a[j])>minim)
            {
                v[i]=v[j]+1;
                minim=gcd(a[i],a[j]);
            }
        if(!v[i]) v[i]=1;
        if(v[i]>maxim) maxim=v[i];
    }
    g<<maxim;
    return 0;
}
