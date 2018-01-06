#include <fstream>
///Se citeste un graf orientat cu n varfuri si m arce, dat prin vectorul arcelor.
///Se citeste apoi un numar natural k mai mic decat n. Sa se afiseze nodurile care se afla la distanta k se nodul 1.

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],x[100],s,p[100],d,niv[100],n,m,k;

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
void bf(int r)
 {int s,d,i;
  s=1;d=1;
  p[r]=1;
  x[1]=r;
  niv[r]=0;
  while(s<=d)
   {for(i=1;i<=n;i++)
    if(!p[i] && a[x[s]][i])
     {d++;
      x[d]=i;
      p[i]=1;
      niv[i]=niv[x[s]]+1;
     }
    s++;
   }
 }

int main()
{
    citire(n,m);
    f>>k;
    bf(1);
    for(int i=1;i<=n;i++)
        if(niv[i]==k) g<<i<<" ";

    return 0;
}
