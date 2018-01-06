#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,minim=-16000,i,j;

void citire(int &n, int &m)
{
    int l,c,v;
    f>>n>>m;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) a[i][j]=0;
      else a[i][j]=minim;

    for(int i=1;i<=m;i++)
        {
            f>>l>>c>>v;
            a[l][c]=v;
        }
}
 void rf()
  {
      for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        if(a[i][j]<a[i][k]+a[k][j] && a[i][k]!=minim && a[k][j]!=minim)
            a[i][j]=a[i][k]+a[k][j];
  }

int main()
{
    citire(n,m);
    rf();
    g<<a[1][n];
    return 0;
}
