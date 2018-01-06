#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100],n,p,op[100][100],c[100][100],m[100][100],rez[100][100],vmin,vmax;
void afisare(int i,int j)
{
    if(i==m[j][i]) g<<a[i];
        else
            g<<"(", afisare(i,m[j][i]), g<<")";
        g<<"o";
    if(j==m[j][i]+1) g<<a[j];
        else
            g<<"(", afisare(m[j][i]+1,j), g<<")";

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

for(i=1;i<=p;i++)
    rez[i][i]=a[i];
for(i=n;i>=1;i--)
    for(j=i;j<=n;j++)
        {
            vmin=99999;
            for(int k=i;k<j;k++)
                if(vmin>m[i][k]+m[k+1][j]+c[rez[i][k]][rez[k+1][j]])
                vmin=m[i][k]+m[k+1][j]+c[rez[i][k]][rez[k+1][j]],vmax=k;
            m[i][j]=vmin;
            m[j][i]=vmax;
        }


   /** for(i=1;i<=p;i++)
        rez[i][i]=a[i];
    for(int nr=2;nr<=p;i++)
        for(i=1;i<=p-nr+1;i++)
    {
        j=i+nr-1;
        for(int k=i;k<j;k++)
        {
            vmin=999999;
            if(vmin>m[i][k]+m[k+1][j]+c[rez[i][k]][rez[k+1][j]])
                vmin=m[i][k]+m[k+1][j]+c[rez[i][k]][rez[k+1][j]],vmax=k;
        }
        m[i][j]=vmin;
        m[j][i]=vmax;
        rez[i][j]=op[rez[i][vmax]][rez[vmax+1][j]];
    }*/
afisare(1,p);
///for(i=1;i<=n;i++){
///for(j=1;j<=n;j++)
   /// g<<m[i][j]<<" ";g<<endl;}
    return 0;
}
