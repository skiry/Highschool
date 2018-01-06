#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct muchii
{
    long nr,val,minim,init;
};
muchii a[100001];
bool cmp(const muchii b,const muchii c)
{
    return b.val<c.val;
}
bool cmp1(const muchii b,const muchii c)
{
    return b.init<c.init;
}
long n,i,viz[100000001];
long l,c;
int main()
{
    f>>n>>l>>c;
    for(i=1;i<=n;i++) f>>a[i].nr,a[i].init=i;
    for(i=1;i<=n;i++) f>>a[i].val;
    sort(a+1,a+n+1,cmp);
    a[1].minim=l-a[1].nr;
    for(i=2;i<=n;i++)
    {
        a[i].minim=a[i-1].minim;
        for(int j=l;j<=c;j++)
            if(a[i].minim<j-a[i].nr&&j-a[i].nr!=a[i-1].minim)
                {
                    a[i].minim=j-a[i].nr;
                    break;
                }
    }
    sort(a+1,a+n+1,cmp1);
    int ok=0;
    for(i=1;i<=n;i++)
    {
        viz[a[i].minim]++;
        if (viz[a[i].minim]>1)
        {
            g<<"-1";
            ok=1;
        }
    }
    if(!ok)
        for(i=1;i<=n;i++) g<<a[i].minim+a[i].nr<<" ";
    return 0;
}
