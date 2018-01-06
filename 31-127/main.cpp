#include <fstream>

using namespace std;
ifstream f("varut.jmt");
ofstream g("varut.lak");
int a[100][100],n,m,i,j,q,k,nr,p;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    {p=i;
    for(j=1;j<=m;j++)
    {a[i][j]=p;
    p++;}
    }
    for(i=1;i<=n;i++)
        {for(j=1;j<=m;j++)
        g<<a[i][j]<<" ";
    g<<'\n';}


    return 0;
}
