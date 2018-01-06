#include <fstream>
/// Afisati toate ciclurile elementare care au ca extremitate initiala si finala varful k.
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[50][50],n,m,k,x[50],viz[50];

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

void afis(int pas) /// afisarea ciclului
    {
        for(int i=1;i<=pas;i++)
            g<<x[i]<<" ";
            g<<endl;
    }

void backt(int k, int pas)
{
    for(int i=1;i<=n;i++)
        if(!viz[i] && a[x[pas-1]][i])
        {
            x[pas]=i;
            viz[i]=1;
            if(x[pas]==k && pas>3)
                afis(pas);
            else backt(k,pas+1);
            viz[i]=0;
        }
}

int main()
{
    citire(n,m);
    f>>k;
    x[1]=k;
    backt(k,2);
    return 0;
}
