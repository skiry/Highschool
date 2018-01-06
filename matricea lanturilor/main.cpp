#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,i,j,x,y,m,gr[100],s,l=1,c[100];
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++) f>>x>>y, a[x][y]=a[y][x]=1;
    for(int k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i!=j&&!a[i][j]) a[i][j]=a[i][k]*a[k][j];

        for(i=1;i<=n;i++)
            {
                s=0;
                for(j=1;j<=n;j++)
                    s+=a[i][j];
                gr[i]=s;
            }
        for(i=0;i<=n;i++)
        {
            int ok=1;
            for(j=1;j<=n;j++)
                if(gr[j]==i)
                    ok=0,g<<j<<" ";
            if(!ok) g<<endl;
        }
        for(i=1;i<=n;i++)
        {
            int ok=1;
            for(j=1;j<=l;j++)
                if(gr[i]!=c[j]) ok=0;

            if(!ok)
            {
                for(int p=i+1;p<=n;p++) if(gr[p]==gr[i]) g<<p<<" ";
                l++;
                c[l]=gr[i];
            }
if(!ok)g<<endl;
        }
            return 0;
}
