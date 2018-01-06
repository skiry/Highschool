#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,pi,pc,d,t,a[100][100],i,j,tr[100][100],ok=0,morc,nr,nr1,nrv,ok1;
int main()
{f>>n>>m>>pi>>pc>>d;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) f>>a[i][j];
f>>t;
if(t)
    for(i=1;i<=t;i++)
        for(j=1;j<=2;j++) f>>tr[i][j];
        i=pi;
        j=pc;
for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) if(a[i][j]==7) nrv++;

while(a[i][j]!=6||a[i][j]!=8||((i>0||i<=n)||(j>0||j<=m))||nr!=2||ok1==0)
{if(d==1) i--;
if(d==2) j--;
if(d==3) i++;
if(d==4) j++;
if(a[i][j]==1||a[i][j]==2||a[i][j]==3||a[i][j]==4) d=a[i][j];
if(a[i][j]==7) {morc++;a[i][j]=0;}
if(a[i][j]==5)
    {if(d==1) d=3;
if(d==3) d=1;
if(d==2) d=4;
if(d==4) d=2;}
if(a[i+1][j]==6||a[i-1][j]==6||a[i][j+1]==6||a[i][j-1]==6) nr++;

if(morc==nrv) ok1=1;
nr1++;
}
    if(a[i][j]==6||nr==2) g<<"INGERAS";
    if(((i<0||i>=n)||(j<0||j>=m))) g<<"RATACIT";
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) if(a[i][j]==7) ok=1;
    if(ok==0) g<<"FERICIT";
    g<<endl;
    g<<i<<" "<<j;
    g<<endl;
    g<<morc<<" "<<nr1;
    return 0;
}
