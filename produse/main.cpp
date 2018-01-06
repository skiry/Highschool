#include <fstream>

using namespace std;
ifstream f("produse.in");
ofstream g("produse.out");
int n,d,a[4000],rez,nr,b[100][2000];
/**void apel(int k)
{
    pus[k]=1;
    for(int i=k;i<=n;i++)
        if(!pus[i]&&(rez*a[i]<d)) g<<i<<" ",nr++,rez=rez*a[i],apel(i);


    pus[k]=0;

}*/
int main()
{
    int i;
    f>>n>>d;
    for(i=1;i<=n;i++)
        f>>a[i];
b[1][a[1]]=a[1];
    for(i=1;i<=n;i++)
        for(int j=1;j<=d;j++)
            b[i][j]=b[i-1][j]+b[i-1][d/a[i]];

    for(i=1;i<=d;i++) nr+=b[n][i];
    g<<nr;
    return 0;
}
