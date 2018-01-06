#include <fstream>
///Se da un graf orientat cu n varfuri si m arce, citit prin vectorul arcelor.
///Sa se afiseze toate circuitele euleriene pe care le are graful.
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,nrc,pf[100],x[100];

void citire(int &n, int &m)
{
    int l,c,v;
    f>>n>>m;
    for(int i=1;i<=m;i++)
        {
            f>>l>>c;
            a[l][c]=a[c][l]=1;
        }
}
void afis()
{
    for(int i=1;i<=m+1;i++)
        g<<x[i]<<" ";
    g<<endl;
}
void circuit(int k)
 {
     for(int i=1;i<=n;i++)
        {
            x[k]=i;
            if(k==1 ||a[x[k-1]][x[k]]==1)
            {
                a[x[k-1]][x[k]]=a[x[k]][x[k-1]]=0;
                if(k==m+1) afis();
                else circuit(k+1);
                a[x[k-1]][x[k]]=a[x[k]][x[k-1]]=1;
            }
        }
 }

int main()
{
    citire(n,m);
    circuit(1);
    return 0;
}
