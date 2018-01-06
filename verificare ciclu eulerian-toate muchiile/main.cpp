#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,q,viz[100],ok;
int grad(int i)
{
    int nr=0;
    for(int j=1;j<=n;j++)
        if(a[i][j]) nr++;
    return nr;
}
void df(int i)
{
    viz[i]=1;
    for(int j=1;j<=n;j++)
        if(a[i][j]&&!viz[j])
            df(j);

}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>j>>q,a[q][j]=a[j][q]=1;
    for(i=1;i<=6;i++)
        if(grad(i)%2) ok=1;
    df(1);
    if(!ok)
    for(i=1;i<=n;i++)
        if(!viz[i]) ok=2;
    if(!ok) g<<"Graful este eulerian!";
    else g<<"Graful nu este eulerian!";
    return 0;
}
