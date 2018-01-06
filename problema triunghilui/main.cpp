#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],c[100][100],i,j,n,b,d,cmax;
void afis(int k, int v)
{
    if(k!=2)
       if(c[k-1][v]>=c[k-1][v-1]) k--,afis(k,v);
    else k--,v--,afis(k,v);
    g<<a[k][v]<<" ";
}
int main()
{
   f>>n;
   for(i=1;i<=n;i++)
   {
        a[0][i]=0;
        for(j=1;j<=i;j++)
        f>>a[i][j];
   }
   c[1][1]=a[1][1];
   for(i=2;i<=n;i++)
       for(j=1;j<=i;j++)
            {
                if(c[i-1][j]>=c[i-1][j-1])
                        c[i][j]=a[i][j]+c[i-1][j];
                    else c[i][j]=a[i][j]+c[i-1][j-1];
                if(c[i][j]>cmax) cmax=c[i][j], b=i, d=j;
            }

   /* while(b)
    {
        g<<a[b][d]<<" ";
        if(c[b-1][d]>=c[b-1][d-1]) b--;
        else b--,d--;
    }*/
    afis(b,d);
    g<<a[b][d];
    return 0;
}
