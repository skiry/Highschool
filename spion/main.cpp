#include <fstream>
#define MOD 100003
using namespace std;
ifstream f("spion.in");
ofstream g("spion.out");
int t,n,i,sol,rez,nr;
char c;
long long inversmodular(long long a)
{
    long long b=MOD,r=0,c=0,x=0,y=0,z=1;
    while(a)
    {
        r=b%a;
        c=b/a;
        b=a;
        a=r;
        x=y-c*z;
        y=z;
        z=x;
    }
    while(y<0) y+=MOD;
    return y;
}
int comb(int n, int k)
{
    int minim=min(k,n-k);
    int maxim=max(k,n-k);
    long long kfact,nkfact,nfact,nr=1;
    for(int i=2;i<=minim;i++)
        nr*=i,nr%=MOD;
    kfact=nr;
    for(i=minim+1;i<=maxim;i++)
        nr*=i,nr%=MOD;
    nkfact=nr;
    for(i=maxim+1;i<=n;i++)
        nr*=i,nr%=MOD;
    nfact=nr;
    return (nfact*inversmodular(kfact)%MOD)%MOD*(inversmodular(nkfact))%MOD;
}
int main()
{
    f>>t;
    while(f>>c) {if(c=='E') sol++; else rez++; nr++;}
    if(t==1) g<<sol+1;
    else g<<comb(nr,sol);
    return 0;
}
