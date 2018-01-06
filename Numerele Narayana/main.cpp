#include <fstream>
#define MOD PROCENT!!///
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,k;
int inversmodular(int a)
{
    int r,c,x=0,y=0,z=1,b=MOD;
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
int narayana(int n,int k)
{
    int minim=min(n-k-1,k-1),maxim=max(n-k-1,k-1);
    int nr=1;

    for(int i=2;i<=minim;i++) nr*=i;
    k1fact=nr;
    nr*=(minim+1);
    kfact=nr;

    for(i=minim+2;i<=maxim;i++) nr*=i;
    nk1fact=nr;
    nr*=(maxim+1);
    nkfact=nr;

    for(i=maxim+2;i<=n;i++) nr*=i;
    nfact=nr;

    return nfact*nfact*inversmodular(n)*inversmodular(kfact)*inversmodular(nkfact)*inversmodular(k1fact)*inversmodular(nk1fact);
}
int main()
{
    f>>n>>k;
    g<<narayana(n,k);
    return 0;
}
