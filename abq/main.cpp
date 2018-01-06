#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i,m,q,j,b[100][100];
char a[100][100];
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) f>>a[i][j];
f>>q;
for(i=1;i<=q;i++)
for(j=1;j<=4;j++)
    f>>b[i][j];

for(i=1;i<=q;i++)
{if (a[b[i][1]][b[i+1][2]]=='b') g<<"-1";
else g<<"salut";





}


    return 0;
}
