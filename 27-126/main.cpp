#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,q;
char b[100];
int main()
{f>>n>>m;
for(i=1;i<=n*m;i++)
    f>>b[i];
    q=1;
    while(q<=n*m)
 for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
 {a[i][j]=b[q];
 q++;

 }
for(i=1;i<=m;i++)
        {

         for(j=1;j<=n;j++)
            g<<(char)a[i][j]<<" ";
            g<<'\n';}

    return 0;
}
