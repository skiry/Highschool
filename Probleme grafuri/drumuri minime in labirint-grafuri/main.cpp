#include <fstream>
///nod=n*(y-1)+x;
///x=(i-1)%n+1;
///y=(i-1)/n+1;
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
///optimizare: graful cu alocare dinamica;
///optimizare2: fiecare nod poate avea maxim 4 vecini => nu va fi nevoie de vectorul graf[n*n][n*n], ci de graf[n][4];
int n,i,j,a[100][100],graf[10000][10000],xp,yp,xs,ys,viz[100],c[100],t[100],nr;
int bfs(int i)
{
    int prim,ultim;
    prim=ultim=1;
    c[1]=i;
    while(prim<=ultim)
    {
        int nod=c[prim];
        for(int j=1;j<=n*n;j++)
            if(graf[nod][j]&&!viz[j])
                {
                    if(j==(n*(ys-1)+xs))
            {
                return nod;
            }
                   else{
                        viz[j]++;
                        c[++ultim]=j;
                        t[j]=nod;
                   }
                }
        prim++;
    }
    return 0;
}
void drum(int i)
{
    if(t[i]!=(n*(yp-1)+xp)) drum(t[i]);
    nr++;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            f>>a[i][j];
    f>>xp>>yp>>xs>>ys;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j])
    {
        for(int k=0;k<4;k++)
            if(a[i+dx[k]][j+dy[k]])
                graf[n*(j-1)+i][n*(j+dy[k]-1)+i+dx[k]]=graf[n*(j+dy[k]-1)+i+dx[k]][n*(j-1)+i]=1;
    }
    drum(bfs(n*(yp-1)+xp));
    g<<nr+1<<endl;
    /**for(i=1;i<=n*n;i++){
        for(j=1;j<=n*n;j++)
        g<<graf[i][j]<<" ";g<<endl;}*/
    return 0;
}
