#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,t;
unsigned long long i,r;
int main()
{
    f>>t;
    for(int u=1;u<=t;u++)
    {
        f>>n;
        r=1;
        for(int j=1;j<=n;j++)
            f>>i,r*=i%1000000007;
        g<<r%1000000007<<'\n';
    }
    return 0;
}
