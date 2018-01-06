#include <fstream>

using namespace std;
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");
int a[101][101],n,m,i,j,k,x,y,z;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
               if(i!=j) a[i][j]=99999;
            else a[i][j]=0;
    for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                f>>a[i][j];
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if((a[i][j]>a[i][k]+a[k][j]||!a[i][j])&&a[i][k]&&a[k][j]&&i!=j)
                    a[i][j]=a[i][k]+a[k][j];
    for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
        g<<a[i][j]<<" ";g<<endl;}
    return 0;
}
