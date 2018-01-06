#include <fstream>

using namespace std;
ifstream f("immortal.in");
ofstream g("immortal.out");
int a[21][21],n,m,i,k,b,d,nr,mx;
int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};
struct rezultat
{
    int l1,c1,l2,c2,j,c;
};
rezultat r[16];
void backtracking(int x,int y,int h)
{
    //g<<x<<" "<<y<<" "<<h<<endl;
    for(int e=k;e>=1;e--)
    {
        for(int i=0;i<4;i++)
            if(a[x+dl[i]][y+dc[i]]==1)
            {
                //g<<x+dl[i]*2<<" "<<y+dc[i]*2<<" nr: "<<nr<<endl,
                nr++;
                //g<<"nr: "<<nr<<" "<<x<<" "<<y<<endl;
                r[nr].l1=x;
                r[nr].c1=y;
                r[nr].l2=x+dl[i]*2;
                r[nr].c2=y+dc[i]*2;
                a[x][y]=0;
                a[x+dl[i]][y+dc[i]]=0;
                r[h].j=r[nr].l2;
                r[h].c=r[nr].c2;
                if(mx!=k-1) //g<<r[nr].l1<<" "<<r[nr].c1<<" "<<r[nr].l2<<" "<<r[nr].c2<<endl,
                    backtracking(r[nr].l2,r[nr].c2,e);
                a[x+dl[i]][y+dc[i]]=1;
                //else g<<"se poate";
                r[h].j=x;
                r[h].c=y;
                if(nr>mx) mx=nr;
                nr--;
            }
    }
}
int main()
{
    f>>n>>m>>k;
    for(i=1;i<=k;i++)
            {
                f>>b>>d;
                a[b][d]=1;
                r[i].j=b;
                r[i].c=d;
            }
    for(int h=k;h>=1;h--)
        for(int i=0;i<4;i++)
            if(a[r[h].j+dl[i]][r[h].c+dc[i]]==1)
                backtracking(r[h].j,r[h].c,h);
    for(i=1;i<k;i++)
          g<<r[i].l1<<" "<<r[i].c1<<" "<<r[i].l2<<" "<<r[i].c2<<endl;
    return 0;
}
