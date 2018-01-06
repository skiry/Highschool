#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,s1,b[100],ok,k,q;
int main()
{f>>n;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    f>>a[i][j];
    k=0;
 for(i=1;i<=n;i++)
{ok=1;
q=1;
for(j=1;j<=k&&ok==1;j++)
{


    if(a[i][q]==b[j])ok=0;q++;}
    if(ok==1) {k++;b[k]=a[i][q];}
}
    for(i=1;i<=k;i++) g<<b[k]<<" ";

    return 0;
}
