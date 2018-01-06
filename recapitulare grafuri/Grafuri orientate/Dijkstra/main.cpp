#include <fstream>
///algoritmul lui Djikstra
///Se citeste un graf orientat cu n noduri si m arce dat prin vectorul arcelor.
///Sa se calculeze lungimea minima de la k la restul nodurilor.

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,nrc,k,i,j,t[100],d[100],p[100];

void citire(int &n, int &m)
{
    int l,c,v;
    f>>n>>m;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) a[i][j]=0;
      else a[i][j]=99999;

    for(int i=1;i<=m;i++)
        {
            f>>l>>c>>v;
            a[l][c]=v;
        }
}
void dijkstra(int s)
{ int i,j,k,minim;
  for(i=1;i<=n;i++)
     { d[i]=a[s][i];
       if(i!=s && d[i]!=99999) t[i]=s;
     }
  p[s]=1;
  for(k=1;k<n;k++)
   { minim=99999;
     for(i=1;i<=n;i++)
       if(!p[i] && d[i]<minim) { minim=d[i]; j=i;
			     }
     for(i=1;i<=n;i++)
       if(!p[i])
       if(d[i]>d[j]+a[j][i])
	 { d[i]=d[j]+a[j][i];
	   t[i]=j;
	 }
     p[j]=1;
   }
}

void drum(int i)
{ if(t[i]) drum(t[i]);
  g<<i<<" ";
}


int main()
{
    citire(n,m);
    f>>k;
    dijkstra(k);
    for(int i=1;i<=n;i++)
        if(i!=k)
        {
            g<<k<<"->"<<i<<": ";
            drum(i);
            g<<"="<<d[i]<<endl;
        }
    return 0;
}
