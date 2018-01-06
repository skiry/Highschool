#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,k;
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++) f>>k>>j,a[k][j]=1;
       for(i=1;i<=n;i++){
            for(j=1;j<=n;j++) g<<a[i][j]<<" ";g<<endl;}g<<endl;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i!=j&&!a[i][j])
                    a[i][j]=a[i][k]*a[k][j];
    for(i=1;i<=n;i++){
            for(j=1;j<=n;j++) g<<a[i][j]<<" ";g<<endl;}
    return 0;
}
