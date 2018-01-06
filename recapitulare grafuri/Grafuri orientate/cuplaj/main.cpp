#include <fstream>
///Se dă un graf neorientat bipartit G = (V = (L, R), E). Un cuplaj în G este o submulţime de muchii M astfel încât pentru
///toate vârfurile v din V, există cel mult o muchie în M incidentă în v. Un cuplaj maxim este un cuplaj de cardinalitate maximă.
using namespace std;
ifstream f("date.in");
ofstream g("date.out");

struct muchie {int x,y;};
muchie S[10001]; ///solutia
int C[10001][10001]; ///matricea capacitatilor
int t1,t2,n; ///cardinalele si nr total de noduri
int T[10001],X[10001]; ///vector TATA din BFS, coada din BFS
int sk; ///lungimea solutiei

int BFS() //returneaza 1 daca gaseste drum de crestere de la 0 la n
{
    int s=1,d=1,j;
    for(int i=1;i<=10000;i++) T[i]=X[i]=0;
    X[1]=0;T[0]=-1;
    while(s<=d)
    {
        for(j=1;j<=n;j++)
            if(T[j]==0 && C[X[s]][j]>0)
            {
                X[++d]=j;
                T[j]=X[s];
                if(j==n)
                    return 1;
            }
        s++;
    }
    return 0;
}

void cuplaj_maxim()
{
    int j;
    while(BFS()) ///cat timp mai gaseste drumuri de crestere
      {
                j=n;
                while(j!=0) ///inverseaza arcele
                    {   C[T[j]][j]=0;
                        C[j][T[j]]=1;
                        j=T[j];
                    }
      }
}

int main()
{
    int i,x,y,m;
    f>>t1>>t2>>m;
    n=t1+t2;
    for(i=1;i<=m;++i)
    {
        f>>x>>y;
        C[x][t1+y]=1;
    }
    for(i=1;i<=t1;i++) C[0][i]=1;
    n++;
    for(i=1;i<=t2;i++) C[t1+i][n]=1;
    cuplaj_maxim();
    for(i=1;i<=n;i++)
        if(C[n][i]==1) S[++sk].y=i;
    for(i=1;i<=sk;i++)
            for(int j=1;j<=n;j++)
                 if(C[S[i].y][j]) S[i].x=j;
    g<<sk<<endl;
    for(i=1;i<=sk;i++) g<<S[i].x<<" "<<S[i].y-t1<<endl;

    return 0;
}
