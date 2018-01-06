#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,c[100],i,j,nr,k;
int main()
{
   f>>n;
   for(i=1;i<=n;i++)
    f>>c[i];
   for(i=1;i<=n;i++)
   {
       f>>nr;
       for(j=1;j<=nr;j++)
       {
           f>>k;
           a[k][i]=c[k];
       }
   }
   for(k=1;k<=n;k++)
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]<a[i][k]+a[k][j]&&a[i][k]&&a[k][j]&&i!=j)
            a[i][j]=a[i][k]+a[k][j];
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(!a[i][j]&&i!=j) a[i][j]=-1;

for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        g<<a[i][j]<<" ";
   g<<endl;
   }

   int maxim=0;
   for(i=1;i<=n;i++)
    if(a[i][n]>maxim) maxim=a[i][n];
    g<<maxim+c[n]<<endl;
    for(i=1;i<=n;i++)
    {
        int minim,maxim1=0;
        for(j=1;j<=n;j++) if(a[j][i]>maxim1) maxim1=a[j][i];
        minim=maxim-a[i][n];
        g<<maxim1<<" "<<minim<<endl;
    }
    return 0;
}
