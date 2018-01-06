#include <fstream>

using namespace std;
ifstream f("ciur.in");
ofstream g("ciur.out");
int n,nr,i,j;
char a[2000001];
int main()
{
    f>>n;
    for(i=2;i<=n;i++)
    if(!a[i])
    {
        nr++;
        for(j=2*i;j<=n;j+=i)
            a[j]=1;
    }
    g<<nr;
    return 0;
}
