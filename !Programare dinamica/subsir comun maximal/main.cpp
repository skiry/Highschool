#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int x[100],y[100],a[100][100],i=1,j=1,n,m,z[100],k;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>x[i];
    for(j=1;j<=m;j++) f>>y[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
                else a[i][j]=a[i][j-1];

                i=n;j=m;
     for(k=1;a[i][j];)
                if(x[i]==y[j])
                    z[k]=x[i],k++,i--,j--;
     else if(a[i][j]==a[i-1][j]) i--;
     else if(a[i][j]==a[i][j-1]) j--;

     for(i=k-1;i;i--)
         g<<z[i]<<" ";

            return 0;
}
