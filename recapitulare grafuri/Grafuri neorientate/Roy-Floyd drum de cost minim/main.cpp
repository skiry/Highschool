#include <fstream>
/// Roy Floyd drum de cost minim cu afisare drum
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],x,y,i,j,k,n,m,inf=99999;

void citire(int &n, int &m)
{
    int j,l,k;
    f>>n>>m; ///nr noduri, nr muchii
    for(int i=1;i<=m;i++)
        {
            f>>j>>l>>k;
            a[j][l]=a[l][j]=k; ///completare matrice de adiacenta
        }
}

void RoyFloyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if((a[i][j]>a[i][k]+a[k][j]||!a[i][j])&&i!=j&&a[i][k]&&a[k][j])
			       a[i][j]=a[i][k]+a[k][j];
}

void descompun_drum(int i, int j) /// descompunere drum de la i la j prin k
{
    int ok=0,k=1;
    while(k<=n&&!ok)
     {
         if(i!=k&&j!=k)
             if(a[i][j]==a[i][k]+a[k][j])
             {
                 descompun_drum(i,k);
                 descompun_drum(k,j);
                 ok=1; /// se poate realiza descompunerea
             }
         k++;
     }
     if(!ok&&j)
        g<<j<<" "; ///cand “drumul” nu mai poate fi descompus afisez extremitatea finala
}

void scriu_drum(int ni,int nf)
{
    if(a[ni][nf]<inf)
        descompun_drum(ni,nf);
    else g<<"nu exista lant";
}

int main()
{
    citire(n,m);
    f>>x>>y;
    RoyFloyd();
    g<<"Matricea de adiacenta cu drumurile de cost minim"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        g<<a[i][j]<<" ";g<<endl;}

    g<<"Drumul de la "<<x<<" la "<<y<<" este de "<<a[x][y]<<" si este compus din nodurile : "<<x<<" ";
    scriu_drum(x,y);
    return 0;
}
