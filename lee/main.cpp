#include <fstream>
#include <queue>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100][100],n,m,xp,yp,xs,ys,i,j;
int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};
struct element
{
    int l,c;
};
element p,k;
queue <element> q;
int main()
{
    f>>n>>m>>xp>>yp>>xs>>ys;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {f>>a[i][j];if(a[i][j]) a[i][j]=-1;}
    a[xp][yp]=1;
    p.l=xp;
    p.c=yp;
    q.push(p);
    while(q.size()&&!a[xs][ys])
    {
        p=q.front();
        q.pop();
        for(i=0;i<4;i++)
            if(p.l+dl[i]<=n&&p.c+dc[i]<=m&&p.c+dc[i]>0&&p.l+dl[i]>0&&a[p.l+dl[i]][p.c+dc[i]]==0)
        {
            k.l=p.l+dl[i];
            k.c=p.c+dc[i];
            q.push(k);
            a[k.l][k.c]=a[p.l][p.c]+1;
        }
    }
    g<<"Drumul de la punctul "<<xp<<"."<<yp<<" pana la "<<xs<<"."<<ys<<" este de "<<a[xs][ys]<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)g<<a[i][j]<<" ";g<<endl;}
    return 0;
}
