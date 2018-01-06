#include <fstream>
///Un sir de n numere.Se citeste k. Sa se stabileasca cel mai mic
///indice i pentru care media aritmetica a urmatoarelor k numere este maxima
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int main()
{int n,k,a[10000],i,suma,m,poz,j;
f>>n>>k;
for(i=1;i<=n;i++)
    f>>a[i];

for(i=1;i<=n-k+1;i++)
{
    suma=0;
    for(j=i;j<=i+k-1;j++)                                    ///sum pt fiecare k term cons
       suma+=a[j];
    if(suma>m)
    {
        m=suma;
        poz=i;
    }
}
g<<"Secventa cu suma cea mai mare este : ";
for(i=poz;i<=poz+k-1;i++) g<<a[i]<<" ";
g<<endl;
g<<"Pozitia la care incepe secventa cu suma cea mai mare : "<<poz;

    return 0;
}
