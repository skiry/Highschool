#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream f("euro3.in");
ofstream g("euro3.out");
int t,n,m,i,a[4001],viz[8001],s;
inline bool cmp(const int &rl,const int &rr)
{
    return rl<rr;
}
void backt(int nr,int val)
{
    s+=a[nr];g<<s<<" "<<a[nr]<<" "<<val<<" "<<viz[s]<<endl;
    viz[s]=min(viz[s],a[nr]-val);
    for(int o=nr+1;o<=n;o++)
        backt(o,val);
    s-=a[nr];
}
int main()
{
    f>>t;
    for(int h=1;h<=t;h++)
    {
        f>>n>>m;
        for(i=1;i<=n;i++) f>>a[i];
        s=0;
        for(i=1;i<=n;i++) viz[i]=9999;
        sort(a,a+n+1,cmp);
        for(i=1;i<=n;i++) s=0,backt(i,a[i]);
        for(i=1;i<=m;i++) if(viz[i]==9999) g<<"-1 ";
        else g<<viz[i]<<" ";
        g<<'\n';
    }
    return 0;
}
