#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,c,k,s[100],ok[100];
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>j>>c,a[j][c]++;
    f>>k;
    for(i=1;i<=k;i++)
        f>>s[i],ok[i]=1;///vectorul ok retine valoarea 1 pt nodurile din submultmea A
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)///daca exista arc de la i la j si nodurile sunt in submultimi diferite, afisam i si j
            if(a[i][j]&&((!ok[j]&&ok[i])||(!ok[i]&&ok[j]))) g<<i<<" "<<j<<endl;
    /**for(i=1;i<=n;i++)
    {for(j=1;j<=n;j++)
    g<<a[i][j]<<" ";
    g<<endl;}*/
    return 0;
}
