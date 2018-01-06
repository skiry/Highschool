#include <fstream>
///algoritmul Roy-Floyd
///Se citeste un graf orientat cu n noduri si m arce dat prin vectorul arcelor.
///Sa se calculeze lungimea minima a drumului dintre oricare doua noduri din graf.

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,nrc,pf[100],ps[100],i,j;

void citire(int &n, int &m)
{
    int l,c,v;
    f>>n>>m;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) a[i][j]=0;
      else a[i][j]=99999;

    for(int i=1;i<=m;i++)
        {
            f>>l>>c>>v;
            a[l][c]=v;
        }
}
void rf()
{
    int i,j,k;
      for(k=1;k<=n;k++)
          for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
          if((a[i][j]>a[i][k]+a[k][j]||!a[i][j])&&i!=j&&a[i][k]&&a[k][j])
             a[i][j]=a[i][k]+a[k][j];
}

void afis()
{
    int i,j;
  for(i=1;i<=n;i++)
      {	 for(j=1;j<=n;j++)
	 if(a[i][j]==99999) g<<"- ";
	 else g<<a[i][j]<<" ";
	 g<<endl;
	  }
}


int main()
{
    citire(n,m);
    rf();
    afis();
    return 0;
}
