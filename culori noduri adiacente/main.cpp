/** NORMAL


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

/// CU LISTE


#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct nod{int nr;
nod *urm;};
nod *cul;
int a[100][100],n,m,x,y,viz[100],nr,j;
void creare(nod *cul)
{
    nod *p,*ultim;
    cul=new nod;
    cul->nr=1;
    cul->urm=0;
    ultim=cul;
    for(int i=2;i<=n;i++)
    {
        p=new nod;
        if(a[1][i]) p->nr=2;
        else p->nr=1;
        p->urm=0;
        ultim->urm=p;
        ultim=p;
    }

}
int verif(int k,nod *cul)
{
    int ok=0,b=1;
    nod *p;
    do
    {
        ok=0;
        p=cul;
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++) p=p->urm;
            if(a[k][i]&&b==p->nr) b++, ok=1;

    } while(ok);
    return b;
}
int main()
{
    int i;
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y, a[x][y]=a[y][x]=1;
    viz[1]=1;
    creare(cul);
    for(i=2;i<=n;i++)
    {
        p=cul;
        for(int k=1;k<i;k++)
            p=p->urm;
        int ok=0,cmax=0;
        for(j=1;j<=n;j++)
            {
                q=cul;
                for(int h=1;h<j;h++)
                    q=q->urm;
                if(a[i][j])
                    {
                        if(q->nr==p->nr&&!viz[j]) q->nr++;
                        if(q->nr==p->nr&&viz[j]) ok=1;
                        if(q->nr>nr) nr=q->nr;
                    }
            }
        if(ok) p->nr=verif(i,cul);
        if(p->nr>nr) nr=p->nr;
        viz[i]=p->nr;
    }
    g<<"Numarul minim de culori este : "<<nr<<endl;
  for(i=1;i<=nr;i++)
    {
        g<<"Culoarea "<<i<<" : ";
        q=cul;
        for(j=1;j<=n;j++)
        {
            for(int h=1;h<j;h++) q=q->urm;
            if(q->nr==i) g<<j<<" ";
        }
        g<<endl;
    }
    return 0;
}
