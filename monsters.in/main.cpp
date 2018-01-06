#include <fstream>
#define MOD 1000000007
using namespace std;
ifstream f("monsters.in");
ofstream g("monsters.out");
int n,i;
long long nr,sum,partial,part1,partt1;
long long int inmulteste(long long n, long long p)
{
    long long b=1;
    while(p)
    {
        if(p&1) b=((b%MOD)*(n%MOD))%MOD;
        n=((n%MOD)*(n%MOD))%MOD;
        p>>=1;
    }
    return b;
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>nr;
        partial=0;
        if(nr>60)
        {
            partial=1;
            partial<<=60;
            partial%=MOD;

            partial=inmulteste(partial,nr/60);
            nr%=60;

            part1=1;
            part1<<=nr;
            part1%=MOD;

            partial*=part1;
            partial%=MOD;
        }
        if(!partial) partial=1,partial<<=nr,partial%=MOD;
        sum+=partial;
        sum%=MOD;
    }
    g<<sum;
    return 0;
}
