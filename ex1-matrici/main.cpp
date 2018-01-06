#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,a[100][100],j,i;
int main()
{f>>n;
f>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) f>>a[i][j];
    for(j=1;j<=m;j++)
    if(j%2) {i=1; while (i<=n) {g<<a[i][j]<<" ";i++;}}
    return 0;
}
