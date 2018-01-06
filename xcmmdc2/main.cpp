#include <fstream>

using namespace std;
ifstream f("xcmmdc.in");
ofstream g("xcmmdc.out");
int a[1001][1001],i,n,m,v[50003],k,q,j,ok,l,sol,el;
int cmmdc(int x,int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    f>>n>>m>>k>>q;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            f>>a[i][j];
            if(a[i][j]==k) ++v[1],ok=1;
        }
    for(i=2;i<=min(n,m)&&(!ok||v[i-1]>0);i++)
    {
        int linie=n-i+1,coloana=m-i+1;
        for(int j=1;j<=linie;j++)
            for(int l=1;l<=coloana;l++)
        {
            a[j][l]=cmmdc(cmmdc(a[j][l],a[j+1][l+1]),cmmdc(a[j+1][l],a[j][l+1]));
            if(a[j][l]==k) ++v[i],ok=1;
        }

    }
    for(i=1;i<=q;i++) f>>el,g<<v[el]<<'\n';
    return 0;
}
