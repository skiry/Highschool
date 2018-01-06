#include <fstream>

using namespace std;
ifstream f("tren.in");
ofstream g("tren.out");
int s[100],a[100][100],i,m,n,v[100],j;
int main()
{
    f>>n;
    s[0]=0;
    for(i=1;i<=n;i++) f>>v[i],s[i]=s[i-1]+v[i],g<<s[i]<<" "
        ;
    g<<endl;

    f>>m;
    for(i=1;i<=m;i++)
        for(j=1;j<=3;j++)
            a[i][j]=s[i];
    for(i=m+1;i<=n;i++)
        for(j=1;j<=3;j++)
            {
                a[i][j]=a[i-1][j];
                if(a[i][j]<a[i-m][j-1]+s[i]-s[i-m])
                    a[i][j]=a[i-m][j-1]+s[i]-s[i-m];
            }
g<<a[n][3];
    return 0;
}
