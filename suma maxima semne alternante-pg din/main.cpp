#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100],n,i,s[100];
int poz(int k)
{
    int maxim=0;
    for(int j=1;j<k;j++)
        if((s[j]+a[i]>maxim)&&a[j]<0)
            maxim=s[j]+a[i];
    if(!maxim) return a[k];
    return maxim;
}
int neg(int k)
{
    int maxim=0;
    for(int j=1;j<k;j++)
        if((s[j]+(a[i]*(-1))>maxim)&&a[j]>0)
            maxim=s[j]+(a[i]*(-1));
    if(!maxim) return a[k]*(-1);
    return maxim;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
    if(a[1]>0) s[1]=a[1];
        else s[1]=a[1]*(-1);
    for(i=2;i<=n;i++)
        if(a[i]>0) s[i]=poz(i);
        else s[i]=neg(i);
    for(i=1;i<=n;i++)
        g<<s[i]<<" ";
        g<<*max_element(s,s+n+1);
    return 0;
}
