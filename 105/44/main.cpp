#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i,a[40000];
int main()
{f>>n;
a[1]=1;
for(i=2;i<=n;i++)
    {a[i]=i+a[i/2];
g<<a[i]<<" ";}

    return 0;
}
