#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,x,y,i,j,suc[100],prec[100],p,nr=1,nr1=1;
void dfsuc(int k)
{
    suc[k]=nr;
    for(int i=1;i<=n;i++)
        if(a[i][k]&&!suc[i])
            dfsuc(i);
}
void dfprec(int k)
{
    prec[k]=nr;
    for(int i=1;i<=n;i++)
        if(a[k][i]&&!prec[i])
            dfprec(i);
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y,a[x][y]=1;
    for(i=1;i<=n;i++)
    {
        if(!suc[i])
            dfsuc(i),dfprec(i);
        for(j=1;j<=n;j++)
            if(suc[j]!=prec[j])
                suc[j]=prec[j]=0;
nr++;
    }

    for(i=1;i<=n;i++)
        if(suc[i]==i)
  {g<<"componenta "<<nr1<<":"<<endl;
   for(int j=1;j<=n;j++)
    if(suc[j]==i) g<<j<<" ";
    g<<endl;
    nr1++;
  }
    return 0;
}
