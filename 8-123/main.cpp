#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,ok;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>a[i][j];
for(i=1;i<=n;i++)
    if(i%2==0)
do{ok=1;
 for(j=1;j<m;j++)
 if(a[i][j]>a[i][j+1]&&a[i][j]%2==0&&a[i][j+1]%2==0) {swap(a[i][j],a[i][j+1]);ok=0;}
}while(ok==0);
for(i=1;i<=n;i++)
    {for(j=1;j<=m;j++)
    g<<a[i][j]<<" ";
g<<'\n';
    }




    return 0;
}
