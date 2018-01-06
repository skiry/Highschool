#include <fstream>
///Sa se afiseze pe linii separate distantele minime de la varful k la celelalte varfuri ale grafului
///si lanturile de lungime minima corespunzatoare acestor distante.

///Distanta de la un varf la altul se considera a fi numarul de muchii din cel mai scurt lant care uneste cele doua noduri.
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],x[100],i,k,n,m,viz[100],d[100],t[100];

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

void bf(int k)
{
	int st,dr,j;
	st=dr=1;
	x[1]=k;
	viz[k]=1;
	d[k]=0;
	while(st<=dr)
	{
		for(j=1;j<=n;j++)
			if(a[x[st]][j]==1 && viz[j]==0)
			{
				dr++;
				x[dr]=j;
				viz[j]=1;
				d[j]=d[x[st]]+1; /// vectorul cu distantele
				t[j]=x[st]; /// tatal nodului j
			}
		st++;
	}
}

void lant(int k)
{
    if(t[k])
        lant(t[k]);
	g<<k<<" ";
}

int main()
{
    citire(n,m);
    f>>k;
    bf(k);
    for(i=1;i<=n;i++)
        if(i!=k&&d[i])
    {
        g<<"Drumul de la "<<k<<" la "<<i<<" este "<<d[i]<<" si este format din ";
        lant(i);
        g<<endl;
    }
    return 0;
}
