#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,u=0,n,p1,m,x,y,a[100][100],coada[100],viz[100];
void parc(int p1)
{
    for(int i=1;i<=n;i++)
        if(a[coada[p1]][i]&&viz[i]==0)
            u++, coada[u]=i, viz[i]++;

    if(p1<=u) parc(p1+1);

}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y, a[x][y]=1, a[y][x]=1;
    f>>p1;
    viz[p1]=1;
    coada[1]=p1;
    u=1;
    parc(1);
    for(i=1;i<=n;i++) g<<coada[i]<<" ";

    return 0;
}
