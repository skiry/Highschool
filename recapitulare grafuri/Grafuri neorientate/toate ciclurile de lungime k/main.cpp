#include <fstream>
/// TOATE CICLURILE DE LUNGIME K
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],x[100],i,j,k,n,m,viz[100];

void citire(int &n, int &m)
{
    int j,l;
    f>>n>>m; ///nr noduri, nr muchii
    for(i=1;i<=m;i++)
        {
            f>>j>>l;
            a[j][l]=a[l][j]=1; ///completare matrice de adiacenta
        }
}
    int valid(int j)
      {
          if(j>1)
             if(a[x[j-1]][x[j]]==0) return 0;
          if(j==k) if(a[x[j]][x[1]]==0) return 0;  /// nu exista muchie
             return 1;
      }
    void afis() /// afisarea ciclului
    {
        for(int i=1;i<=k;i++)
            g<<x[i]<<" ";
            g<<x[1]<<endl;
    }
    void backt(int j)
      {
          for(int i=1;i<=n;i++)
            if(!viz[i])
                {
                    x[j]=i;
                    viz[i]=1;
                   if(valid(j)) /// sunt indeplinite conditiile
                      if(j==k) afis();
                   else backt(j+1);
                    viz[i]=0;
                }
      }

int main()
{
    citire(n,m);
    f>>k;
    g<<"toate ciclurile de lungime k"<<endl;
    backt(1);
    return 0;
}



