#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int viz[100],c[100],n,m,i,j,p,u,p1,x,y,a[100][100];
void bf(int p1)
{
    p=u=1;
    viz[p1]=1;
    c[1]=p1;
    while(p<=u)
        {
            for(i=1;i<=n;i++)
        if(a[c[p]][i])
            if(!viz[i]&&a[i][p1])
                u++,c[u]=i,viz[i]++,a[c[p]][i]=a[i][c[p]]=0;


            p++;
        }

}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++) f>>x>>y,a[x][y]=a[y][x]=1;
    bf(2);
    for(i=1;i<=u;i++) g<<c[i]<<" ";g<<c[1];
    return 0;
}
