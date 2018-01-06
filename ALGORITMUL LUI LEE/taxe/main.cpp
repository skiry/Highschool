/**#include <fstream>

using namespace std;
ifstream f("taxe1.in");
ofstream g("taxe1.out");
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
struct element
{
    int l,c;
    unsigned d;} c[100],x,y;
    int a[100][100],n,ss,x0,o,i,j,k,inc,sf,b[100][100],s[100][100];
    int main()
{
    f>>ss>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            f>>b[i][j];
   for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            a[i][j]=-2;
    x0=1;o=1;
    for (i=1;i<=n;i++) a[i][0]=a[i][n+1]=-1;
    for (i=1;i<=n;i++) a[0][i]=a[n+1][i]=-1;
    x.l=x0; x.c=o; x.d=0; a[x0][o]=0; //aici:s-a[x0][y0]
    c[inc]=x;
    while(inc<=sf)
        {
            x=c[inc++];
            for(k=0;k<4;k++)
                {
                    y.l=x.l+dx[k];
                    y.c=x.c+dy[k];
                    if(a[y.l][y.c]==-2)
                        {
                            y.d=x.d+1;
                            a[y.l][y.c]=y.d;
                            c[++sf]=y;
                        }
                }
        }
    inc=sf=0;
    x0=1;o=1;
    x.l=x0; x.c=o; x.d=0; a[x0][o]=0;
    s[1][1]=ss-b[1][1];
    c[inc]=x;
    while(inc<=sf)
    {
        x=c[inc++];
        for(k=0;k<4;k++)
        {
            y.l=x.l+dx[k];
            y.c=x.c+dy[k];
            if(a[y.l][y.c]==a[x.l][x.c]+1)
                {
                    if (s[x.l][x.c]-b[y.l][y.c]>s[y.l][y.c])
                        s[y.l][y.c]=s[x.l][x.c]-b[y.l][y.c];
                        c[++sf]=y;
                }
        }
    }

/**for(i=1;i<=n;i++)
{for(j=1;j<=n;j++) {if(a[i][j]>=0) g<<" ";g<<a[i][j];}g<<endl;}
for(i=1;i<=n;i++)
  {for(j=1;j<=n;j++) g<<s[i][j]<<" ";g<<endl;}
  g<<s[n][n];
    return 0;
}*/
#include <fstream>

using namespace std;
ifstream f("taxe1.in");
ofstream g("taxe1.out");
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
struct element
{
    int l,c;
    unsigned d;
} x,y;
struct nod
{
    element nr;
    nod *urm;
};
nod *c,*ultim,*prim,*p;
    int a[103][103],n,ss,x0,o,i,j,k,inc,sf,b[100][100],s[100][100];
int main()
{
    f>>ss>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            f>>b[i][j];

    for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            if(j==1)
                a[i][j]=i-1;
            else a[i][j]=a[i][j-1]+1;
        }

    inc=sf=0;
    x0=1;o=1;
    x.l=x0; x.c=o; x.d=0; a[x0][o]=0;
    s[1][1]=ss-b[1][1];
    prim=new nod;
    prim->nr=x;
    prim->urm=0;
    ultim=prim;
    c=prim;
    while(inc<=sf)
    {
        x=c->nr;
       if(c->urm) c=c->urm;
        inc++;
        for(k=0;k<4;k++)
        {
            y.l=x.l+dx[k];
            y.c=x.c+dy[k];
            if(a[y.l][y.c]==a[x.l][x.c]+1)
                {
                    if (s[x.l][x.c]-b[y.l][y.c]>s[y.l][y.c])
                        s[y.l][y.c]=s[x.l][x.c]-b[y.l][y.c];
                        p=new nod;
                        p->nr=y;
                        p->urm=0;
                        ultim->urm=p;
                        ultim=p;
                        sf++;
                }
        }
    }
/**
for(i=1;i<=n;i++)
{for(j=1;j<=n;j++) {if(a[i][j]>=0) g<<" ";g<<a[i][j];}g<<endl;}
for(i=1;i<=n;i++)
  {for(j=1;j<=n;j++) g<<s[i][j]<<" ";g<<endl;}
*/

  g<<s[n][n];
    return 0;
}

