#include <fstream>

using namespace std;
ifstream f("joc13.in");
ofstream g("joc13.out");
int n,k,i,j,l,m,s;
struct matrice
{
    int v,t;
};
matrice a[3][5001];
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++) f>>a[1][i].v;
    for(i=1;i<=n;i++) f>>a[2][i].v;
    a[1][1].t=a[1][1].v;
    a[2][1].t=0;
    for(i=2;i<=n;i++)
        for(j=1;j<=2;j++)
    {
        m=-1001;
        s=a[j][i].v;
        for(l=1;l<k&&l<i;l++)
        {
            s+=a[j][i-l].v;
            if(s+a[3-j][i-l].t>m) m=s+a[3-j][i-l].t;
        }
        a[j][i].t=m;

    }
    if(a[1][n].t+a[2][n].v>a[2][n].t) a[2][n].t=a[1][n].t+a[2][n].v;
    g<<a[2][n].t;
    return 0;
}

