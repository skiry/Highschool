#include <iostream>
#include <algorithm>
using namespace std;
///ifstream cin("date.in");
///ofstream cout("date.out");
struct numar
{
    int s,j,nr;
};
numar a[200001];
inline bool cmp(const numar &b,const numar &c)
{
    return b.nr<c.nr;
}
int n,k,i,contor=1,ct;
long long suma;
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>a[i].s;
    for(i=1;i<=n;i++) cin>>a[i].j,a[i].nr=a[i].s-a[i].j;
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n&&a[i].nr<=0;i++) suma+=a[i].s,k--,a[i].s=-1,contor++;
    ct=contor;
    for(i=contor;i<=contor+k-1&&i<=n;)
        if(a[i].nr>0)
        {
            suma+=a[i].s;
            a[i].s=-1;
            i++;
            ct++;
        }

    for(i=ct;i<=n;i++)
        if(a[i].s!=-1) suma+=a[i].j;
    cout<<suma;
    return 0;
}
