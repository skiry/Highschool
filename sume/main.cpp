#include <fstream>

using namespace std;
ifstream f("suma4.in");
ofstream g("suma4.out");
int n,c,i,j=1,nr=1,b[73][5185],viz[73][5185],a1,m=999999,r;
struct matrice
{
    int v,ind,ret;
};
matrice a[73][5185];
void afis(int h,int k)
{
    if(a[h][k].ret) afis(h-1,a[h][k].ret);
    g<<a[h][k].ind<<" ";
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>c;
        if(j<=nr*nr) a[nr][j].v=c,a[nr][j].ind=i,b[nr][j]=c,j++;
        if(j>nr*nr) j=1,nr++;
    }
    nr--;
    g<<nr<<" ";
    for(i=1;i<nr;i++)
    {
        for(j=1;j<=i*i;j++)
        {
            if(j%i==0) a1=j+j/i-1;
            else a1=j+j/i;
            //a1=j+j/(i+1);
            if(!viz[i+1][a1]&&a[i+1][a1].v) a[i+1][a1].v+=a[i][j].v,a[i+1][a1].ret=j,viz[i+1][a1]=1;
                else if(viz[i+1][a1]&&(a[i][j].v+b[i+1][a1]<a[i+1][a1].v))
                    a[i+1][a1].v=a[i][j].v+b[i+1][a1],a[i+1][a1].ret=j;
            if(i==nr-1) if(a[i+1][a1].v<m) m=a[i+1][a1].v,r=a1;
            a1++;
            if(!viz[i+1][a1]&&a[i+1][a1].v) a[i+1][a1].v+=a[i][j].v,a[i+1][a1].ret=j,viz[i+1][a1]=1;
                else if(viz[i+1][a1]&&(a[i][j].v+b[i+1][a1]<a[i+1][a1].v))
                    a[i+1][a1].v=a[i][j].v+b[i+1][a1],a[i+1][a1].ret=j;
            if(i==nr-1) if(a[i+1][a1].v<m) m=a[i+1][a1].v,r=a1;
            a1+=i;
            if(!viz[i+1][a1]&&a[i+1][a1].v) a[i+1][a1].v+=a[i][j].v,a[i+1][a1].ret=j,viz[i+1][a1]=1;
                else if(viz[i+1][a1]&&(a[i][j].v+b[i+1][a1]<a[i+1][a1].v))
                    a[i+1][a1].v=a[i][j].v+b[i+1][a1],a[i+1][a1].ret=j;
            if(i==nr-1) if(a[i+1][a1].v<m) m=a[i+1][a1].v,r=a1;
            a1++;
            if(!viz[i+1][a1]&&a[i+1][a1].v) a[i+1][a1].v+=a[i][j].v,a[i+1][a1].ret=j,viz[i+1][a1]=1;
                else if(viz[i+1][a1]&&(a[i][j].v+b[i+1][a1]<a[i+1][a1].v))
                    a[i+1][a1].v=a[i][j].v+b[i+1][a1],a[i+1][a1].ret=j;
            if(i==nr-1) if(a[i+1][a1].v<m) m=a[i+1][a1].v,r=a1;
         }
    }
    g<<m<<endl;
    afis(nr,r);
    //g<<a[nr][r].v<<a[nr][r].ind<<a[nr][r].ret<<endl;
    //g<<a[nr-1][a[nr][r].ret].v<<a[nr-1][a[nr][r].ret].ind<<a[nr-1][a[nr][r].ret].ret<<endl;
    //g<<a[nr-2][a[nr-1][a[nr][r].ret].ret].v<<a[nr-2][a[nr-1][a[nr][r].ret].ret].ind<<a[nr-2][a[nr-1][a[nr][r].ret].ret].ret<<endl;
    return 0;
}
