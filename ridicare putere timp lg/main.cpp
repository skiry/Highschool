#include <fstream>
#define MOD 1999999973
using namespace std;
ifstream f("lgput.in");
ofstream g("lgput.out");
long long n,p;
long long int inmulteste()
{
    long long b=1;
    while(p)
    {
        if(p&1)
        {
            b=((b%MOD)*(n%MOD))%MOD;
            //p--;
        }
        n=((n%MOD)*(n%MOD))%MOD;
        p>>=1;
    }
    return b;
}
int main()
{
    f>>n>>p;
    g<<inmulteste();
    return 0;
}
