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
    for(i=1;i<=n;i++)
    {
        for(j=a[i];j<=a[i]*m;j+=a[i])
            b.push_back(j);
    }
    sort(b.begin(),b.end());
    unique(b.begin(),b.end());
    g<<b[m-1];
    return 0;
}
