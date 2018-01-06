#include <fstream>

using namespace std;
ifstream f("inginer.in");
ofstream g("inginer.out");
int n,m,j,i,b[100][100],q=1,z,ppl[20],ppc[20],pfl[20],pfc[20],ok,sf,inc,rf[100][100];
int dl[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
struct puncte{int l,c;} p,c[100];
char a[100];
int main()
{f>>n>>m;
while(!f.eof())
{i++;
f>>a[i];
}
z=i;
for(i=1;i<=n*m;i++) if(a[i]=='X') a[i]=-1;
else if(a[i]=='.') a[i]=0;
for(i=0;i<=n+1;i++)b[i][0]=b[i][n+1]=-1;
for(i=0;i<=m+1;i++)b[0][i]=b[m+1][i]=-1;
q=1;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++) {b[i][j]=rf[i][j]=a[q];q++;}
z=z-5-(n*m);
q=n*m+1;

for(j=1;j<=z/4;j++)
{ppl[j]=a[q];
q++;

ppc[j]=a[q];
q++;

pfl[j]=a[q];
q++;

pfl[j]=a[q];
q++;

}


       for(j=1;j<=z/4;j++)
{
 inc=0;
sf=0;
c[1].l=ppl[j]; c[1].c=ppc[j];
inc=1;
sf=1;
b[ppl[j]][ppc[j]]=1;ok=1;
while(inc<=sf&&ok==1)
{
    p=c[inc];inc++;
    for(i=0;i<4;i++)
    if(b[p.l+dl[i]][p.c+dc[i]]==0) {b[p.l+dl[i]][p.c+dc[i]]=1+b[p.l][p.c];

    sf++;
    c[sf].l=p.l+dl[i];
    c[sf].c=p.c+dc[i];
    if(c[sf].l==pfl[j]&&c[sf].c==pfc[j]) ok=0;}

}

for(i=1;i<=n;i++)
for(j=1;j<=m;j++) {b[i][j]=rf[i][j];}

}
for(i=1;i<=n;i++){
for(j=1;j<=m;j++) if(b[i][j]==-1) g<<b[i][j]<<" ";
else g<<" "<<b[i][j]<<" ";g<<endl;}
    return 0;
}
