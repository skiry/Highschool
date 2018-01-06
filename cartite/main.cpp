#include <fstream>

using namespace std;
ifstream f("cartite.in");
ofstream g("cartite.out");
int p,n,m,i,j,k,gal,a[301][301],cl,q,cc,w,z,b[301][301],x[10000],y[10000],nr=1,d[301],u;
int dl[]={-1,0,1,0};
int dc[]={0,1,0,-1};
struct graf
{
    int l1,c1,l2,c2;
};
graf much[1000];
struct lee
{
    int l,s,d;
};
lee c[30000];
void ciclu(int k)
{
    int cmax=0,maxx=0;
    g<<x[k]<<" "<<y[k]<<endl;
    for(i=1;i<=nr;i++)
        if(b[k][i]&&d[i]>=cmax) cmax=d[i],maxx=i;
        if(maxx)
        {
            b[k][maxx]=b[maxx][k]=0;
            d[k]--;
            d[maxx]--;
            ciclu(maxx);
        }
}
int main()
{
    f>>p;
    f>>m>>n;
    f>>cl>>cc;
    a[cl][cc]=-2;
    f>>k;
    for(i=1;i<=k;i++)
    {
        f>>q>>w>>z;
        if(!z) a[q][w]=-1;
        if(z==1)
        {
            a[q][w]=-1;
            if(q+1<m) a[q+1][w]=-1;
            if(w+1<n) a[q][w+1]=-1;
            if(w-1>0) a[q][w-1]=-1;
            if(q-1>0) a[q-1][w]=-1;
        }
        if(z==2)
        {
            a[q][w]=-1;
            if(q+1<m) a[q+1][w]=-1;
            if(w+1<n) a[q][w+1]=-1;
            if(w-1>0) a[q][w-1]=-1;
            if(q-1>0) a[q-1][w]=-1;
            if(w+1<n&&q+1<m) a[q+1][w+1]=-1;
            if(q+1<n&&w-1>0) a[q+1][w-1]=-1;
            if(q-1>0&&w+1<n) a[q-1][w+1]=-1;
            if(q-1>0&&w-1>0) a[q-1][w-1]=-1;
            if(q+2<m) a[q+2][w]=-1;
            if(q-2>0) a[q-2][w]=-1;
            if(w+2<n) a[q][w+2]=-1;
            if(w-2>0) a[q][w-2]=-1;
        }

    }
    f>>gal;
    for(i=1;i<=gal;i++)
        {
            f>>much[i].l1>>much[i].c1>>much[i].l2>>much[i].c2;
            if(a[much[i].l1][much[i].c1]!=-1)
                a[much[i].l1][much[i].c1]=1;
            if(a[much[i].l2][much[i].c2]!=-1)
                a[much[i].l2][much[i].c2]=1;
            int ok=0;
            for(j=1;j<=nr;j++)
               {
                   if(x[j]==much[i].l1&&y[j]==much[i].c1) ok+=1;
                   if(x[j]==much[i].l2&&y[j]==much[i].c2) ok+=3;
               }
            if(!ok) x[nr]=much[i].l1,y[nr]=much[i].c1,nr++,x[nr]=much[i].l2,y[nr]=much[i].c2,nr++;
            if(ok==1) x[nr]=much[i].l2,y[nr]=much[i].c2,nr++;
            if(ok==3) x[nr]=much[i].l1,y[nr]=much[i].c1,nr++;
        }
        nr--;

    if(p==1)
    {
        c[1].l=cl;
        c[1].s=cc;
        c[1].d=1;
        p=u=1;
        if(a[cl][cc]==1) g<<cl<<" "<<cc<<" 0";
        else
        {
        while(p<=u)
            {
            for(i=0;i<4;i++)
                {
                    if(c[p].l+dl[i]>0&&c[p].l+dl[i]<=m&&c[p].s+dc[i]>0&&c[p].s+dc[i]<=n&&!a[c[p].l+dl[i]][c[p].s+dc[i]])
                        u++,c[u].l=c[p].l+dl[i],c[u].s=c[p].s+dc[i],c[u].d=c[p].d+1,a[c[p].l+dl[i]][c[p].s+dc[i]]=-2;
                    else if(a[c[p].l+dl[i]][c[p].s+dc[i]]==1) {g<<c[p].l+dl[i]<<" "<<c[p].s+dc[i]<<" "<<c[p].d;p=u+1;}
                }
            p++;
            }
        }
    }

    if(p==2)
    {
        int val1,val2,cmax=0,nmax=0;
        for(i=1;i<=gal;i++)
            {
                for(j=1;j<=nr;j++)
                {
                    if(much[i].l1==x[j]&&much[i].c1==y[j]) val1=j;
                    if(much[i].l2==x[j]&&much[i].c2==y[j]) val2=j;
                }

                    b[val1][val2]=b[val2][val1]=1;
                    d[val1]++;
                    d[val2]++;
                    if(d[val1]>cmax&&a[x[val1]][y[val1]]!=-1) cmax=d[val1],nmax=val1;
                    if(d[val2]>cmax&&a[x[val2]][y[val2]]!=-1) cmax=d[val2],nmax=val2;
            }
       ciclu(nmax);
    }
    float a,b;
    a=5.12;
    b=2.13;
    g<<a+b;

    return 0;
}
