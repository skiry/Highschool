#include <fstream>
#include <set>
using namespace std;
ifstream f("hashuri.in");
ofstream g("hashuri.out");
const int mod=666013;
int n,tip,x,m;
set <int> a[mod];
set <int>::iterator cauta;
int main()
{
    f>>n;
    while(n--)
    {
        f>>tip>>x;
        m=x%mod;
        cauta=a[m].find(x);
        if(tip==1&&cauta==a[m].end())
            a[m].insert(x);
        else if(tip==2&&cauta!=a[m].end())
            a[m].erase(cauta);
        else if(tip==3)
            g<<(cauta!=a[m].end())<<'\n';
    }
    return 0;
}
