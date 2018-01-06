#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,x,y,gr[100],a[100][100];
void ciclu(int k)
{
    int cmax=0,nmax=0;
    g<<k<<" ";
    for(int i=1;i<=n;i++)
    {
        if(a[k][i])
            if(gr[i]>cmax)
                cmax=gr[i],nmax=i;
    }
        if(nmax)
            {
                a[k][nmax]=a[nmax][k]=0;
                gr[k]--;
                gr[nmax]--;
                ciclu(nmax);
            }

}

int main()
{
    int i,j;
   f>>n>>m;
   for(i=1;i<=m;i++) f>>x>>y,a[x][y]=a[y][x]=1;
   for(i=1;i<=n;i++)
   {
       int s=0;
    for(j=1;j<=n;j++)
        s+=a[i][j];
        gr[i]=s;
        ///g<<s<<" ";
   }
    ciclu(1);
    return 0;
}
