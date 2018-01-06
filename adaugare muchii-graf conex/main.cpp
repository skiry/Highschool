#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,x,y,viz[100],v,rez[100];
void conex(int i,int v)
{
    viz[i]=v;
    for(int j=1;j<=n;j++)
        if(a[i][j]&&!viz[j]) conex(j,v);
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y,a[x][y]=a[y][x]=1;
    v=1;
    for(i=1;i<=n;i++)
        if(!viz[i]) conex(i,v),rez[v]=i,v++;
    g<<"Numar muchii necesare pt ca graful sa fie conex : "<<v-2<<endl;
    for(i=1;i<=v-2;i++)
        g<<rez[i]<<" "<<rez[i+1]<<endl;
    return 0;
}
