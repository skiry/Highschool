#include <fstream>
#include <string.h>
using namespace std;
ifstream f("lgdrum.in");
ofstream g("lgdrum.out");
int n,m,i,j,k,r[101][101],cp=1,cs=1,dist[101][101],prim,ultim,rez=999999;
struct ps
{
    int x,y;
};
ps vp[100],vs[100],c[10001];
int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};
char plecare[13],sosire[13],a[13];
int main()
{
    f>>n>>m;
    f.get();
    f>>plecare;
    f.get();
    f>>sosire;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        f>>a;
        if(!strcmp(plecare,a)) vp[cp].x=i,vp[cp++].y=j;
        if(!strcmp(sosire,a)) vs[cs].x=i,vs[cs++].y=j;
        for(k=0;k<strlen(a);k++)
           r[i][j]+=a[k];
    }
    for(i=1;i<cp;i++)
        for(j=1;j<cs;j++)
    {
        int minim=99999;
        for(int k=0;k<=n+1;k++)
            for(int h=0;h<=m+1;h++)
                if(k==0||k==n+1||h==0||h==m+1)
                    dist[k][h]=-1;
                else dist[k][h]=0;
        dist[vp[i].x][vp[i].y]=1;
        prim=ultim=0;
        c[1].x=vp[i].x;
        c[1].y=vp[i].y;
        while(prim<=ultim)
        {
            prim++;
            for(k=0;k<=3;k++)
                if(r[c[prim].x+dl[k]][c[prim].y+dc[k]]&&dist[c[prim].x+dl[k]][c[prim].y+dc[k]]==0&&(((r[c[prim].x][c[prim].y])^(r[c[prim].x+dl[k]][c[prim].y+dc[k]]))&r[c[prim].x][c[prim].y]))
            {
                if(c[prim].x+dl[k]==vs[j].x&&c[prim].y+dc[k]==vs[j].y)
                {
                    if(minim>r[c[prim].x][c[prim].y]+1)
                    minim=dist[c[prim].x][c[prim].y]+1;
                    break;
                }
                else
                    {
                        dist[c[prim].x+dl[k]][c[prim].y+dc[k]]=dist[c[prim].x][c[prim].y]+1;
                        ultim++;
                        c[ultim].x=c[prim].x+dl[k];
                        c[ultim].y=c[prim].y+dc[k];
                    }
            }
        }
        if(minim<rez) rez=minim;
    }
    g<<rez;

    return 0;
}
