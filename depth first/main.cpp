#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,n,p1,m,x,y,a[100][100],viz[100];
void parc(int p1)
{
    g<<p1<<" ";
    viz[p1]=1;
    for(int i=1;i<=n;i++)
        if(a[p1][i]&&viz[i]==0)
            parc(i);

}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y, a[x][y]=1, a[y][x]=1;
    f>>p1;
    parc(p1);

    return 0;
}
