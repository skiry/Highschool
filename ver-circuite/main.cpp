#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,x,y,i,j,viz[100],ok=1,c[100],nr=1;
void df(int k)
{
    viz[k]++;
    for(j=1;j<=n;j++)
        if(a[k][j]&&!viz[j])
            df(j);
        else if(j==i&&a[k][j]) ok=0;

}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>x>>y,a[x][y]=1;
    for(i=1;i<=n&&ok;i++)
            {
                df(i);
                for(j=1;j<=n;j++) viz[j]=0;
            }


   if(!ok) g<<"Exista circuit";
   else g<<"Nu exista circuit";


    return 0;
}
