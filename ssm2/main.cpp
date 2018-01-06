#include <fstream>

using namespace std;
ifstream f("ssm.in");
ofstream g("ssm.out");
int sum[6000001],n,i,best,maxim=-99999999,minim,inc,sf,el,ind;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>el,sum[i]=sum[i-1]+el;
    for(i=1;i<=n;i++)
    {
        best=sum[i]-minim;
        if(best>maxim) maxim=best,inc=ind+1,sf=i;
        if(minim>sum[i]) ind=i,minim=sum[i];
    }
    g<<maxim<<" "<<inc<<" "<<sf;
    return 0;
}
