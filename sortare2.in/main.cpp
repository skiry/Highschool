#include <fstream>

using namespace std;
ifstream f("sortare2.in");
ofstream g("sortare2.out");
int n,a[100001],i,nr,viz[100001];
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
        viz[a[i]]++;
        if(a[i]!=1)
            if(viz[a[i]-1]==0) nr++;
    }
    g<<nr;
    return 0;
}
