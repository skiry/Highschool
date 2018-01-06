#include <fstream>
using namespace std;
ifstream f("inginer.in");
ofstream g("inginer.out");
int n,i,j,m,ch;
char a[75][75],c;
int main()
{f>>n>>m;

for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f.get(c,a);

  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) g<<a<<" ";





    return 0;
}
