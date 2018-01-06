#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100],n,p,op[100][100],c[100][100],m[100][100],rez[100][100],vmin,vmax,d,s;
void afisare(int i,int j)
{
    if(i==m[j+1][i]) g<<a[i];
        else
            g<<"(", afisare(i,m[j+1][i]), g<<")";

        g<<"o";
    if(j==m[j+1][i+1]) g<<a[j];
        else
            g<<"(", afisare(m[j+1][i+1],j), g<<")";

}
int main()
{   int i,j;
    f>>n>>p;
    for(i=1;i<=p;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         f>>op[i][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         f>>c[i][j];

for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    rez[i][j]=i;

/**for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
        g<<rez[i][j]<<" ";g<<endl;}*/

for(i=n;i>=1;i--)
    for(j=i;j<=n;j++)
        {
            vmin=99999;
            for(int k=i;k<=j-1;k++)
                {
                    d=rez[i][k];
                    s=rez[k+1][j];

                    if(vmin>m[i][k]+m[k+1][j]+c[d][s])
                        vmin=m[i][k]+m[k+1][j]+c[d][s],vmax=k;
                    m[i][j]=vmin;
                    m[j][i]=vmax;

                    d=rez[i][vmax];
                    s=rez[vmax+1][j];
                    rez[i][j]=op[d][s];//g<<i<<" "<<vmax<<" "<<j<<endl;
                }
        }
g<<m[a[1]][a[p]];g<<endl;
afisare(1,p);g<<endl;


    /**for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            g<<m[i][j]<<" ";g<<endl;}
    g<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            g<<rez[i][j]<<" ";g<<endl;}*/


    return 0;
}
