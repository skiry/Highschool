#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,x,y,z,e,v1,v2,v3,s[100],t[100],b[100][100],vf,rez[4];
void comut(int b[100][100],int a[100][100])
{
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        b[i][j]=a[i][j],b[j][i]=a[i][j];
}
void dijkstra(int p)
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
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>v1>>v2>>v3,a[v2][v1]=a[v1][v2]=v3;
    f>>x>>y>>z>>e;

    comut(b,a);
    for(i=1;i<=n;i++)
        t[i]=0,s[i]=0;
    dijkstra(x);
    rez[1]=a[x][e];
    comut(a,b);
    for(i=1;i<=n;i++)
        t[i]=0,s[i]=0;
    dijkstra(y);
    rez[2]=a[y][e];
    comut(a,b);
    for(i=1;i<=n;i++)
        t[i]=0,s[i]=0;
    dijkstra(z);
    rez[3]=a[z][e];

    g<<rez[1]<<" "<<rez[2]<<" "<<rez[3]<<endl;
    rez[1]=x;rez[2]=y;rez[3]=z;
    for(i=1;i<3;i++)
        for(j=i+1;j<=3;j++)
        if(a[i]>a[j]) swap(a[i],a[j]);
    for(i=1;i<=3;i++) g<<rez[i]<<" ";
}
