#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,x[100],k,viz[100];
void afis()
{
    for(int i=1;i<=n;i++)
        g<<x[i]<<" ";
        g<<x[1];
        g<<endl;
}
void circuit(int k)
{
    for(int i=1;i<=n;i++)
        if(!viz[i]&&(k==1||a[x[k-1]][i]))
    {
        x[k]=i;
        viz[i]=1;
        if(k==n&&a[x[k]][x[1]]) afis();
        else circuit(k+1);
        viz[i]=0;
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>j>>k,a[j][k]++;
    circuit(1);
    return 0;
}
