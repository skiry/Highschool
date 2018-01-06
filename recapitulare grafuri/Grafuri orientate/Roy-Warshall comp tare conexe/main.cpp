#include <fstream>
///Construiti matricea drumurilor folosind algoritmul Roy-Warshall.
///Folosind matricea drumurilor afisati componentele tare conexe.

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int k,m,n,x[100],a[100][100],viz[100],p[100];

void citire(int &n, int &m)
{
    int l,c,v;
    f>>n>>m;
    for(int i=1;i<=m;i++)
        {
            f>>l>>c;
            a[l][c]=1;
        }
}

void rw() /// ALGORITMUL LUI ROY WARSHALL=> matricea  drumurilor
 {
     int i, j, k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
        if(i!=j&&!a[i][j])
        a[i][j]=a[i][k]*a[k][j];
 }
 void afis()  /// afisare componemte tare conexe
  {
      for(int i=1;i<=n;i++)
        if(!viz[i])
        {
            g<<i<<" ";
            p[i]=1;
            for(int j=1;j<=n;j++)
                if(a[i][j]*a[j][i]==1)
                    {
                        g<<j<<" ";
                        viz[j]=1;
                    }
            g<<endl;
        }
  }


int main()
{
    citire(n,m);
    rw();
    afis();
    return 0;
}
