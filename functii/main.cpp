#include <fstream>
#define MOD 30103
using namespace std;
ifstream f("functii.in");
ofstream g("functii.out");
long long n,m,rez,inv,rezultat=1;
int invmodular(long long n,long long m)
{
    long long x=0,y=0,z=1,init=m,c,r;
    while(n)
    {
        r=m%n;
        c=m/n;
        m=n;
        n=r;
        x=y-c*z;
        y=z;
        z=x;
    }
    while(y<0) y+=init;
    return y;
}
int comb(long long n,long long m)
{
    rez=1;
    inv=1;
    for(long long i=m+1;i<=n;i++)
        rez*=i,rez%=MOD;
    for(long long i=2;i<=n-m;i++)
        inv*=i,inv%=MOD;
    return rez*invmodular(inv,MOD);
}
int putere(long long n,long long m)
{
    for(int i=1;i<=m;i++)
        rezultat*=n,rezultat%=MOD;
    return rezultat;
}
int main()
{
    f>>n>>m;
    g<<((comb(n,m)%MOD)*((putere(2,m)-2)%MOD))%MOD;
    return 0;
}
