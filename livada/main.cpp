#include <fstream>

using namespace std;
ifstream f("livada1.in");
ofstream g("livada1.out");
int n,i,p,m,nr,k,a[101][9000],nr1,j,val,l,poz,cmax;
int main()
{f>>n>>m>>p;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
f>>a[i][j];
for(i=1;i<=n;i++)
{val=0;
k=0;
nr=0;
for(j=1;j<=m;j++)
if(!k) {val=a[i][j];k=1;}
else if(a[i][j]==val) k++;
else k--;
for(j=1;j<=m;j++)
    if(a[i][j]==val) nr++;
if(nr>=((m+1)/2))
    {nr1++;
p=1;
j=2;
while(p<=m)
{while(a[i][j]==a[i][j-1]&&j<=m) j++;
l=j-p;
if(l>=cmax) cmax=l;
p=j;
j++;
}
}}
g<<nr1<<endl;
g<<cmax;
    return 0;
}
