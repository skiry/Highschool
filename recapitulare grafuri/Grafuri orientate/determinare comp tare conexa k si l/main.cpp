#include <fstream>
///Se da un graf orientat cu n vârfuri si m arce prin lista arcelor si doua varfuri distincte k si l.
///Determinati daca varfurile k si l se afla in aceeasi componenta tare conexa a grafului.

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int k,l,m,n,a[100][100],pf[100],ps[100],ok,x,y;

void citire(int &n, int &m)
{
    int l,c,v;
    f>>n>>m;
    for(int i=1;i<=m;i++)
        {
            f>>l>>c;
            a[l][c]=1;
        }
}
void df(int nod)
 {int k;
  pf[nod]=1;
  for(k=1;k<=n;k++)
   if(a[nod][k]==1 && pf[k]==0)
   df(k);
  }

int main()
{
    citire(n,m);
    f>>x>>y;
    df(x);
    if(pf[y]) ok++;
    for(int i=1;i<=n;i++)
        pf[i]=0;
    df(y);
    if(pf[x]) ok++;
    if(ok==2) g<<"DA";
    else g<<"NU";
    return 0;
}
