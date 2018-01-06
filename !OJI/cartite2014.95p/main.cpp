#include <fstream>

using namespace std;
ifstream f("cartite.in");
ofstream g("cartite.out");
struct matrice
{
    int val,ind,viz;
};
matrice v[201][201];
struct lee
{
    int s,d,l;
};
lee x[30000];
struct afisare
{
    int st,dr;
};
afisare af[201];
int dx[]={0,1,-1,0,-2,-1,0,1,2,1,-1,0};
int dy[]={-1,0,0,1,0,1,2,1,0,-1,-1,-2};
int p,n,m,xp,yp,k,a,b,c,d,galerii,i,j,graf[201][201],nr,gx[201],maxx,poz,coada=1,q[30000],ok;
void ciclu(int i)
{
    ///g<<af[i].st<<" "<<af[i].dr<<endl;
    if(!ok)
    {//g<<i<<" ";
    q[coada++]=i;
    if(coada-1==galerii+1&&q[1]==q[coada-1])
    {
        for(int h=1;h<coada;h++) g<<af[q[h]].st<<" "<<af[q[h]].dr<<endl;
        ok=1;
    }
    else{
    for(int j=1;j<=nr;j++)
        if(graf[i][j])
            {
                graf[i][j]=graf[j][i]=0;
                gx[i]--;
                gx[j]--;
                ciclu(j);
                graf[i][j]=graf[j][i]=1;
                gx[i]++;
                gx[j]++;
            }
    }coada--;
    }

}
int main()
{
    f>>p;
    f>>n>>m;
    f>>xp>>yp;
    v[xp][yp].val=-1;
    f>>k;
    for(i=1;i<=k;i++)
    {
        f>>a>>b>>c;
        v[a][b].val=1;
        if(c==1)
        {
            if(a>=2) v[a-1][b].val=1;
            if(a<=n-1) v[a+1][b].val=1;
            if(b>=2) v[a][b-1].val=1;
            if(b<=m-1) v[a][b+1].val=1;
        }
        if(c==2)
        {
            for(j=0;j<12;j++)
                if(a+dx[j]>=1&&a+dx[j]<=n&&b+dy[j]>=1&&b+dy[j]<=m)
                    v[a+dx[j]][b+dy[j]].val=1;
        }
    }
    f>>galerii;
    for(i=1;i<=galerii;i++)
    {
        f>>a>>b>>c>>d;
        if(!v[a][b].ind) v[a][b].ind=++nr,af[nr].st=a,af[nr].dr=b;
        if(!v[c][d].ind) v[c][d].ind=++nr,af[nr].st=c,af[nr].dr=d;
        graf[v[a][b].ind][v[c][d].ind]=graf[v[c][d].ind][v[a][b].ind]=1;
        gx[v[a][b].ind]++;
        gx[v[c][d].ind]++;
        if(gx[v[a][b].ind]>maxx) maxx=gx[v[a][b].ind],poz=v[a][b].ind;
        //if(gy[v[c][d].ind]>maxx) maxx=gy[v[c][d].ind],poz=v[c][d].ind;
    }
    int nr1=0;
    if(p==1)
    {
            ///if(graf[i][j]==1&&v[a][b].val!=1) g<<a<<b<<nr,break;
            if(v[xp][yp].ind) g<<xp<<" "<<yp<<" 0";
            else
            {
                int prim=1;
                int ultim=1;
                int ok=0;
                x[1].s=xp;
                x[1].d=yp;
                x[1].l=0;
                v[xp][yp].viz=1;
                while(prim<=ultim&&!ok)
                {
                    for(i=0;i<4;i++)
                        if(v[x[prim].s+dx[i]][x[prim].d+dy[i]].ind&&v[x[prim].s+dx[i]][x[prim].d+dy[i]].val!=1&&!v[x[prim].s+dx[i]][x[prim].d+dy[i]].viz)
                            {
                                g<<x[prim].s+dx[i]<<" "<<x[prim].d+dy[i]<<" "<<x[prim].l+1;
                                ok=1;
                                break;
                            }
                        else if(v[x[prim].s+dx[i]][x[prim].d+dy[i]].val!=1&&!v[x[prim].s+dx[i]][x[prim].d+dy[i]].viz&&(x[prim].s+dx[i]>=1&&x[prim].s+dx[i]<=n)&&(x[prim].d+dy[i]>=1&&x[prim].d+dy[i]<=m))
                        {
                            x[++ultim].s=x[prim].s+dx[i];
                            x[ultim].d=x[prim].d+dy[i];
                            x[ultim].l=x[prim].l+1;
                            v[x[prim].s+dx[i]][x[prim].d+dy[i]].viz=1;
                        }
                    prim++;
                }

            }

    }
    else if(p==2)
        {//for(i=1;i<=nr;i++){
        //for(j=1;j<=nr;j++)
            //g<<graf[i][j]<<" ";g<<endl;}
            for(i=1;i<=n&&!ok;i++)
            {
                ok=0;
                coada=1;
                ciclu(i);
            }
            }///salveaza sol intr o coada si verifica nrsol==nr si apoi afisezi.
    //for(i=1;i<=nr;i++) g<<i<<": "<<af[i].st<<" "<<af[i].dr<<endl;
    return 0;
}
