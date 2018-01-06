#include <fstream>

using namespace std;
ifstream f("joc.in");
ofstream g("joc.out");
int a[3][5001],rez[3][5001],n,maxim,i,j,k,l,s;
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++) f>>a[1][i];
    for(i=1;i<=n;i++) f>>a[2][i];

    rez[1][1]=a[1][1];
    rez[2][1]=0;

    for(i=2;i<=n;i++)
        for(j=1;j<=2;j++)
    {
        maxim=-1001;
        s=a[j][i];
        for(l=1;l<k&&l<i;l++) ///verific toate posibilatile de maxim k dati inainte, fara sa ies din matrice
        {
            s+=a[j][i-l];
            if(s+rez[3-j][i-l]>maxim) maxim=s+rez[3-j][i-l]; ///3-j semnifica linia opusa
        }
        rez[j][i]=maxim;
    }

    if(rez[1][n]+a[2][n]>rez[2][n]) rez[2][n]=rez[1][n]+a[2][n];
    g<<rez[2][n];
    return 0;
}
