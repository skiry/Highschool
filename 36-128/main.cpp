#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,i,j,q,k,nr,p,s,x,y,ok;
char b[100];
int main()
{f>>n>>m>>x>>y>>p;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>a[i][j];
    for(i=1;i<=p;i++)
        f>>b[i];
        i=1;
        s=s+a[x][y];
        while(i<=p)
    {if(b[i]=='N')
    {a[x][y]=a[x-1][y]; s+=a[x][y];i++;}

    if(b[i]=='S')
        {a[x][y]=a[x+1][y]; s+=a[x][y];i++;}

    if(b[i]=='E')
    {a[x][y]=a[x][y+1]; s+=a[x][y];i++;}

    if(b[i]=='V')
    {a[x][y]=a[x][y-1]; s+=a[x][y];i++;}

}
    g<<s;
    return 0;


}
