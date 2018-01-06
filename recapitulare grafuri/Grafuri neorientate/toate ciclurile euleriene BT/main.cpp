#include <fstream>
/// TOATE CICLURILE EULERIENE CU BACKTRACKING (toate muchiile)
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],x[100],i,j,k,n,m;

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

int valid(int k)
 {
     if(k>1)
        if(a[x[k-1]][x[k]]==0) return 0;
    return 1;
 }

void afis() /// afisarea ciclului
    {
        for(int i=1;i<=m+1;i++)
            g<<x[i]<<" ";
            g<<endl;
    }

void euler(int k)
     {
         for(int i=1;i<=n;i++)
          {
              x[k]=i;
              if(valid(k))
                {
                  a[x[k-1]][x[k]]=0;/// se sterg muchiile
                  a[x[k]][x[k-1]]=0;
                    if(k==m+1) afis();
                     else euler(k+1);
                  a[x[k-1]][x[k]]=1;/// se repun muchiile
                  a[x[k]][x[k-1]]=1;
                }
         }
     }

int main()
{
    citire(n,m);
    g<<"toate ciclurile euleriene cu backtracking"<<endl;
    euler(1);
    return 0;
}
