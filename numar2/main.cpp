#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("numar2.in");
ofstream g("numar2.out");
int n,m,i,j,a[101];
vector <int> b;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;b.size()<m;i++)
    {
        for(j=1;j<=n;j++)
            b.push_back(a[j]*i);
        sort(b.begin(),b.end());
        unique(b.begin(),b.end());
    }
    int ok=1;
    while(ok)
    {
        ok=0;
        for(j=1;j<=n;j++)
        {
            if(a[j]*i<=b[m-1]) ok=1;
            b.push_back(a[j]*i);
        }
        i++;
        sort(b.begin(),b.end());
        unique(b.begin(),b.end());
    }
    g<<b[m-1];
    return 0;
}
