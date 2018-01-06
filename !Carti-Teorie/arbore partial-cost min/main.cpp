#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],cost,m,s[100],t[100],i,j,x,y,z,v,nod,n,k;
int main()
{   f>>n>>m;
for(i=1;i<=m;i++)
    f>>x>>y>>z,a[x][y]=a[y][x]=z;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++) g<<a[i][j]<<" ";g<<endl;}
f>>v;
s[v]=0;
for(i=1;i<=n;i++)
    if(i!=v) s[i]=v;
for(k=1;k<n;k++)
{
    int m=9999;
    for(i=1;i<=n;i++)
        if(s[i]&&a[i][s[i]]&&a[i][s[i]]<m)
                                m=a[i][s[i]],nod=i;
    t[nod]=s[nod];
    cost+=m;
    s[nod]=0;
    for(i=1;i<=n;i++)
        if(s[i]&&a[i][nod]&&a[i][nod]<a[i][s[i]])
                                s[i]=nod;

}
g<<"Cost minim: "<<cost<<endl;
g<<"Vectorul de tati: ";
for(i=1;i<=n;i++) g<<t[i]<<" ";

    return 0;
}

