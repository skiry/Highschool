#include <fstream>
/// Se da un graf neorientat cu n varfuri si m muchii. Determinati numarul minim de culori cu care se pot colora varfurile
/// grafului astfel incat oricare doua varfuri adiacente sa aiba culori diferite. Numerotand apoi culorile necesare, realizati
/// o colorare a varfurilor grafului dat si afisati pentru fiecare culoare nodurile care se coloreaza cu ea.
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[50][50],n,m,viz[50],st,dr,i,x[50],j,c,maxx,t,gasit;

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

int culori(int s)
{
    int c=1;
    st=dr=1;
    viz[s]=1;
    x[1]=s;
    while(st<=dr)
    {
        for(i=1; i<=n; i++)
         {
            if(a[x[st]][i] && !viz[i]) ///vecinii nodului st nevizitati
                {
                    dr++;
                    x[dr]=i;
                    maxx=0; ///calculam culoarea de numar maxim pentru vecinii vizitati ai nodului i
                    for(int k=1; k<=n; k++)
                        if(a[i][k] && viz[k]>maxx) maxx=viz[k];
                    t=1; ///gasim numarul culorii pentru nodul i
                    do {
                            gasit=0;
                            for(int k=1; k<=n; k++)
                            if(a[i][k] && viz[k]==t) gasit=1;
                            if(gasit) t++;
                        } while(t<=maxx && gasit);
                    if(gasit) viz[i]=maxx+1;
                    else viz[i]=t;
                }
         }
         st++;
    }
    for(i=1;i<=dr;i++) if(viz[x[i]]>c) c=viz[x[i]];
    return c;
}

int main()
{
    citire(n,m);
    for(int i=1;i<=n;i++)
    if(!viz[i])
        {
            c=culori(i); ///numarul de culori pentru componenta conexa
            if(c>maxx) maxx=c;
        }
    g<<maxx<<"\n";
    ///afisare noduri pe culori
    for(int i=1;i<=maxx;i++)
    {
        g<<"culoarea "<<i<<": ";
        for(int j=1;j<=n;j++)
            if(viz[j]==i) g<<j<<" ";
        g<<endl;
    }
    return 0;
}
/**
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,x,y,cul[100],viz[100],nr,j;
int verif(int k)
{
    int ok=0,b=1;
    do
    {
        ok=0;
        for(int i=1;i<=n;i++)///se parcurg vecinii
            if(a[k][i]&&b==cul[i]) b++, ok=1;///daca este aceeasi culoare una langa alta, crestem numarul culorii prezente

    } while(ok);                            /// si repetam procesul
    return b;
}
int main()
{
    int i;
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y, a[x][y]=a[y][x]=1;
    cul[1]=1;
    viz[1]=1;
    for(i=1;i<=n;i++) if(a[1][i]) cul[i]=2;
    for(i=2;i<=n;i++)///parcurgem toate nodurile
    {
        int ok=0,cmax=0;
        if(cul[i]==0) cul[i]=1;
        for(j=1;j<=n;j++)///parcurgem toti vecinii nodurilor
            {
                if(a[i][j])///daca este muchie de la nodul i la nodul j
                    {
                        if(cul[j]==cul[i]&&!viz[j]) cul[j]++;///daca este aceeasi culoare una langa alta, dar nodul vecin nu este
                                                            /// inca vizitat, se mareste numarul culorii vecine
                        if(cul[j]==cul[i]&&viz[j]) ok=1;///daca nodul vecin este vizitat, se face ok=1, pentru a se pune ulterior
                                                        /// cea mai mica culoare care nu se gaseste in vecinii nodului prezent
                        if(cul[j]>nr) nr=cul[j]; ///se memoreaza numarul maxim de culori
                    }
            }
        if(ok) cul[i]=verif(i);///in cul[i] se pune cea mai mica culoare care nu se gaseste in vecinii nodului i
        if(cul[i]>nr) nr=cul[i];///se memoreaza numarul maxim de culori
        viz[i]=cul[i];///in viz[i] punem numarul culorii i
    }
    g<<"Numarul minim de culori este : "<<nr<<endl;
  for(i=1;i<=nr;i++)
    {
        g<<"Culoarea "<<i<<" : ";
        for(j=1;j<=n;j++)
        if(cul[j]==i) g<<j<<" ";
        g<<endl;
    }
    return 0;
}
**/
