#include <fstream>
/// Graf eulerian = graf conex + toate nodurile au grade pare
/// Determinare ciclu eulerian
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,a[100][100],viz[100],k,gr[100];

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

int grad(int k) ///calculeaza gradul varfului k
{
    int s=0;
    for(int i=1;i<=n;i++)
        if(a[k][i]==1) s++;
    gr[k]=s;
    return s;
}
void DF(int s) ///parcurge graful din varful s si marcheaza varfurile accesibile
{
    viz[s]=1;
    for(int i=1;i<=n;i++)
        if(a[s][i]==1 && viz[i]==0)
            DF(i);
}
int conex()   ///verific conexitatea grafului
{
    DF(1);
    for(int i=1;i<=n;i++)
        if(viz[i]==0) return 0;
    return 1;
}
int euler() ///  verific daca este eulerian
{
    if(!conex()) return 0;     ///conex
    for(int i=1;i<=n;i++)
        if(gr[i]%2==1) return 0; ///si toate gradele pare
    return 1;
}

void ciclu_eulerian(int k) ///construieste un ciclu eulerian
{
    int maxx=0,nmax=0;
    g<<k<<" "; ///afiseaza varful curent
    for(int i=1;i<=n;i++) ///cauta varful urmator cu grad maxim
    {
        if(a[k][i]==1)
            if(gr[i]>maxx)
           	 {
           	     maxx=gr[i];
           	     nmax=i;
             }
    }
    if(nmax!=0)
        {
            a[k][nmax]=a[nmax][k]=0; ///sterge mughia
            gr[k]--; gr[nmax]--; ///scade gradele celor 2 noduri incidente cu muchia stearsa
            ciclu_eulerian(nmax); ///merge in varful urmator - recursiv
        }
}

int main()
{
    citire(n,m);
    if(euler) g<<"este eulerian";
        else g<<"nu este eulerian";
    g<<endl;

    for(int i=1;i<=n;i++) ///stabilim gradul fiecarui nod
        grad(i);

    ciclu_eulerian(1);
    return 0;
}
