#include <fstream>

using namespace std;
ifstream f("amici2.in");
ofstream g("amici2.out");
unsigned short int n,m,p,a[1500][1500],t[1500][1500],nrvec[1500],nr;
int numara(int nod)
{
    short int ok=1,nr=1;
    while(ok)
    {
        ok=0;//g<<ok<<endl;//g<<nr<<endl;
        for(int i=1;i<=n;i++)
        if(nrvec[i]<n)
        {
            for(int h=1;h<=n;h++)
                if(t[i][h]<nr)
            {
                for(int y=1;y<=n;y++)
                    if(y!=i&&t[h][y]<nr&&!a[i][y]) a[i][y]=1,a[y][i]=1,t[i][y]=nr,t[y][i]=nr,ok=1,nrvec[i]++,nrvec[y]++;
            }
        }
        if(ok) nr++;//g<<ok<<endl;
    }
    return nr-1;
}
int main()
{
    unsigned short int x,y;
    f>>p;
    for(int k=1;k<=p;k++)
    {
        f>>n>>m;
        for(int e=1;e<=m;e++)
        {
            f>>x>>y;
            a[x][y]=1;
            a[y][x]=1;
            nrvec[x]++;
            nrvec[y]++;
        }
        g<<numara(1)<<'\n';
        for(int e=1;e<=n;e++)
        {nrvec[e]=0;for(int j=1;j<=n;j++) a[e][j]=t[e][j]=0;}
    }
    return 0;
}
