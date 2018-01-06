#include <fstream>
/// toate lanturile elementare care au ca extremitate initiala varful v si extremitate finala varful y.
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],x[100],i,n,m,viz[100],y,v;

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

void afis(int k) /// afisarea lantului
    {
        for(int i=1;i<=k;i++)
            g<<x[i]<<" ";
            g<<endl;
    }

void backt(int k)
{
    for(int i=1;i<=n;i++)
        if(!viz[i] && a[x[k-1]][i]==1)
        {
            x[k]=i;
            viz[i]=1;
            if(i==y) afis(k);
                else backt(k+1);
            viz[i]=0;
        }
}

int main()
{
    citire(n,m);
    f>>v>>y;
    x[1]=v;  ///primul nod din coada este v
    viz[v]=1;  ///vizitam nodul v
    backt(2);
 return 0;
}
