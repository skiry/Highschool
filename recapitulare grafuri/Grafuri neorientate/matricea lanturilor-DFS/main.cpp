#include <fstream>
/// Construiti matricea lanturilor folosind parcurgerea in adancime.
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[50][50],b[50][50],n,m,k,viz[50];

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

void df(int s,int k)
{
    viz[k]=1;
    if(k!=s) b[s][k]=b[k][s]=1;
    for(int i=1;i<=n;i++)
        if(!viz[i] && a[k][i])
            df(s,i);
}

int main()
{
    citire(n,m);
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)  /// eliberam fiecare nod pentru a putea vizita din nou
                viz[j]=0;
            df(i,i);
        }
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                g<<b[i][j]<<" ";
            g<<endl;
        }

    return 0;
}
