#include <fstream>
///Se citesc doua varfuri x si y. Afisati drumul de cost minim de la varful x la varful x trecand prin varful y si costul drumului
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,d[100],inf=99999,t[100],p[100],x,y,v;

void citire(int &n, int &m)
{
    int l,c,v;
    f>>n>>m;
    for(int i=1;i<=m;i++)
        {
            f>>l>>c>>v;
            a[l][c]=v;
        }
}

void dijkstra(int s)
{
    int i,j,k,minn;
    for(i=1;i<=n;i++)
     {
         d[i]=a[s][i];
         if(i!=s && d[i]!=inf) t[i]=s;
         else t[i]=0;
         p[i]=0;
     }

    p[s]=1;
    for(k=1;k<n;k++)
       {
           minn=inf;
            for(i=1;i<=n;i++)
                if(!p[i] && d[i]<minn)
                     {
                         minn=d[i];
                         j=i;
                     }
       }
     for(i=1;i<=n;i++)
       if(p[i] && d[i]>d[j]+a[j][i])
            {
                 d[i]=d[j]+a[j][i];
                 t[i]=j;
            }
     p[j]=1;
}

void drum(int i)
{
    if(t[i]) drum(t[i]);
    g<<i<<" ";
}

int main()
{
    citire(n,m);
    f>>x>>y;
    dijkstra(x);
    v=d[y];
    drum(t[y]);
    dijkstra(y);
    v=v+d[x];
    drum(x);
    g<<endl<<v;
    return 0;
}

/**
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,s[100],t[100],c,x,y,p,vf;

void citire(int &n, int &m)
{
    int l,c,v;
    f>>n>>m;
    for(int i=1;i<=m;i++)
        {
            f>>l>>c>>v;
            a[l][c]=v;
        }
}
void drum(int i)
{if(t[i])
	drum(t[i]);
 g<<i<<" ";
}
void djikstra(int p)
{
    for(i=1;i<=n;i++) if(i!=p) s[i]=1;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j&&!a[i][j])
                a[i][j]=99999;

   for(i=1;i<=n;i++)
    if(a[p][i]!=99999&&a[p][i]) t[i]=p;

   for(i=1;i<n;i++)
   {
       m=99999;
       for(j=1;j<=n;j++)
        if(s[j]&&a[p][j]<m) m=a[p][j],vf=j;
       s[vf]=0;
       for(j=1;j<=n;j++)
        if(s[j]&&a[p][j]>(a[p][vf]+a[vf][j]))
        a[p][j]=a[p][vf]+a[vf][j],t[j]=vf;
   }
}
int main()
{
   citire(n,m);
   f>>x>>y;
   djikstra(x);
    g<<"Drumul de la "<<x<<" la "<<x<<" care trece prin "<<y<<" este : ";
    drum(y);
    djikstra(y);
    drum(x);
    g<<" si are lungimea "<<a[x][i]<<endl;

    return 0;
}
**/
