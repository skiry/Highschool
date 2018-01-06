#include <fstream>
/// Construiti MATRICEA LANTURILOR folosind algoritmul Roy-Warshall.
/// Folosind matricea lanturilor afisati componentele conexe.

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int k,m,n,x[100],a[100][100],viz[100];

void citire(int &n, int &m)
{
    int j,l;
    f>>n>>m; ///nr noduri, nr muchii
    for(int i=1;i<=m;i++)
        {
            f>>j>>l;
            a[j][l]=a[l][j]=1; ///completare matrice de adiacenta
        }
}

void rw()
 {
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
    if(!a[i][j]&&i!=j)
        a[i][j]=a[i][k]*a[k][j];
 }
 void afis()
  {
    for(int i=1;i<=n;i++)/// afisare componenta  pornind din nod i
    if(!viz[i])
    {
        g<<i<<" ";
        viz[i]=1;
        for(int j=1;j<=n;j++)
           if(a[i][j])
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
    g<<"Matricea lanturilor"<<endl;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                g<<a[i][j]<<" ";g<<endl;}
    g<<"Componente conexe"<<endl;
    afis();
    return 0;
}
