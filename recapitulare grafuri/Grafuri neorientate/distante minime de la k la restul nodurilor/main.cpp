#include <fstream>
/// DISTANTELE MINIME DE LA VARFUL K LA CELELALTE VARFURI
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],x[100],i,j,k,n,m,viz[100],d[100];

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
	viz[k]=1; /// vizitam nodul k
	d[k]=0; /// vector distante minime
	while(st<=dr)
	{
		for(j=1;j<=n;j++)
			if(a[x[st]][j]==1 && viz[j]==0)
			{
				dr++;
				x[dr]=j; /// bagam in coada vecinul
				viz[j]=1; /// vizitam nodul adaugat
				d[j]=d[x[st]]+1; /// vectorul cu distantele
			}
		st++;
	}
}

int main()
{
    citire(n,m);
    f>>k;
    bf(k);
    for(i=1;i<=n;i++)
        if(i!=k)
            {
                if(d[i])
                    g<<"Distanta de la "<<k<<" la nodul "<<i<<" este "<<d[i]<<endl;
                else if(d[i]==0)
                    g<<"Nu exista drum de la "<<k<<" la "<<i<<endl;
            }
    return 0;
}
