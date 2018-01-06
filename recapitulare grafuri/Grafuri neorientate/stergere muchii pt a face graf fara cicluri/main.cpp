#include <fstream>
///Se da un graf neorientat conex cu n varfuri si m muchii.
///Eliminati un numar minim de muchii din graf astfel incat acesta sa nu mai contina nici un ciclu.
///Se vor afisa muchiile eliminate si matricea de adiacenta a grafului partial obtinut astfel.

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],x[100],i,j,y,n,m,viz[100];

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

void sterg(int s)
{
    int st,dr;
    st=dr=1;
    viz[s]=1;
    x[1]=s;
    while(st<=dr)
    {
        for(i=1; i<=n; i++)
            if(a[x[st]][i]==1)
                if(!viz[i])
                {
                    dr++;
                    x[dr]=i;
                    viz[i]=1;
                    a[i][x[st]]=0;/// sterg muchia pe care am parcurs-o
                }
                else
                {
                   g<<"["<<x[st]<<","<<i<<"]"<<endl;
                   a[x[st]][i]=a[i][x[st]]=0; /// sterg definitiv muchia
                }
                st++;
    }
}
int main()
{
        citire(n,m);
        sterg(1);
        for(i=1;i<=n;i++)
            for(j=1;j<i;j++)        ///repun muchiile sterse la parcurgere
                a[i][j]=a[j][i];
        g<<"Matrice adiacenta : "<<endl;
        for(i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                g<<a[i][j]<<" ";g<<endl;}
        return 0;
}
