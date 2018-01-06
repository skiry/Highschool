#include <fstream>
#include <algorithm>

using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int n,sum,nr,tillnow,i,ok,prodsum;
struct products
{
    int in,val;
};
products a[100001];
inline bool cmp(const products &b,const products &c)
{
    return b.val<c.val;
}
int main()
{
    cin>>n>>sum;
    for(i=1;i<=n;i++) cin>>a[i].val,a[i].in=i;
    sort(a+1,a+n+1,cmp);
    for(i=1;!ok&&i<=n;++i)
    {
        if(a[i].val+prodsum+(nr+1)*a[i].in+tillnow>sum) ok=1;
        else ++nr,tillnow+=a[i].val+prodsum+nr*a[i].in,prodsum+=a[i].in;
    }
    cout<<nr<<" "<<tillnow;
    return 0;
}
