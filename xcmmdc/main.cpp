#include <fstream>

using namespace std;
ifstream f("xcmmdc.in");
ofstream g("xcmmdc.out");
int n,m,q,k,i,j,a[1003][1003],viz[1003],sol[50003],contor,el[50003],rezultat[1003],cmd;
int cememedece(int x,int y)
{
    int c;
    while(y)
    {
        c=x%y;
        x=y;
        y=c;
    }
    return x;
}
int cmmdc(int lin,int col,int nrcol)
{
    cmd=a[lin][col];
    for(int i=lin;i<=lin+nrcol-1;i++)
        for(int j=col;j<=col+nrcol-1;j++)
            cmd=cememedece(cmd,a[i][j]);
    return cmd;
}
int main()
{
    f>>m>>n>>k>>q;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) f>>a[i][j];
    for(i=1;i<=q;i++)
    {
        f>>el[i];
        if(!viz[el[i]]) sol[++contor]=el[i],++viz[el[i]];
    }
    for(i=1;i<=contor;i++)
    {
        for(j=1;j<=n-sol[i]+1;j++)
            for(int l=1;l<=m-sol[i]+1;l++)
              if(cmmdc(j,l,sol[i])==k) rezultat[sol[i]]++;
    }
    for(i=1;i<=q;i++)
        g<<rezultat[el[i]]<<'\n';
    return 0;
}
