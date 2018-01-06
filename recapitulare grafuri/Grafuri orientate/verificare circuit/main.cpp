#include <fstream>
///Se citeste un graf orientat cu n noduri si m arce dat prin vectorul arcelor. Sa se determine daca graful contine circuite.
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,nrc,p[100],x[100],c;

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

int circuit(int k)
 {int s=1,d=1;
  x[1]=k;
  for(int i=1;i<=n;i++) p[i]=0;
   while(s<=d)
    {
        for(int i=1;i<=n;i++)
     if(a[x[s]][i]) {d++;
		     x[d]=i;
		     if(p[k]) return 1; ///am circuit
		     p[i]=1;
		    }
    s++;
    }  return 0; }

int main()
{
    citire(n,m);
    for(int i=1;i<=n;i++)
    if(circuit(i)) c=1;
    if(c==1) g<<"exista";
        else g<<"nu exista";

    return 0;
}
