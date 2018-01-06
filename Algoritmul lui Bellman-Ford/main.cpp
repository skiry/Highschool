/**#include <fstream>
 //////////////VARIANTA 1
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],viz[100],c[100],i,x,n,y,z,m;
int main()
{
    f>>n>>m;
     for(i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
            a[i][j]=a[j][i]=9999;
    for(i=1;i<=m;i++)
        f>>x>>y>>z,a[x][y]=z;
    for(i=1;i<=n;i++)
        viz[i]=9999;
    int prim=1,ultim=1;
    f>>x;
    int nodplecare=x;
    c[1]=x;
    viz[x]=0;
    while(prim<=ultim)
    {
        x=c[prim];
        for(i=1;i<=n;i++)
            if(viz[i]>viz[x]+a[x][i])
        {
            ultim++;
            c[ultim]=i;
            viz[i]=viz[x]+a[x][i];
        }

        prim++;
    }
    for(i=1;i<=n;i++)
        if(i!=nodplecare) g<<viz[i]<<" ";

    return 0;
}
*/
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,d[100][4],ok=1,r,i,j,x,y,z,t[100],e[100];
int main()
{
    f>>n>>m>>r;
    for(i=1;i<=m;i++)
        {
            f>>x>>y>>z,d[i][1]=x,d[i][2]=y,d[i][3]=z;
            if(x==r) e[y]=z,t[y]=x;
            else e[y]=9999;
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            ok=0;
            if(e[d[i][1]]>e[d[i][2]]+d[i][3])
                e[d[i][1]]=e[d[i][2]]+d[i][3],t[e[d[i][2]]]=e[d[i][1]],ok=1;
        }
    for(i=1;i<=n;i++)
        g<<e[i]<<" ";

    return 0;
}
