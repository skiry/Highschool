#include <fstream>

using namespace std;
ifstream f("taxi2.in");
ofstream g("taxi2.out");
int n,m,c,y,a[100][100],s,gr[100],x[100],p[100],max1,nr;
int suma(int k)
{
    int s0=0;
    for(int i=2;i<=k;i++)
       s0+=a[x[i]][x[i-1]];
    return s0;
}
void backt(int i,int j,int k)
{
    x[1]=i;
    p[i]=1;
    for(int o=1;o<=n;o++)
        if(!p[o]&&a[x[k-1]][o])
    {
        x[k]=o;
        p[o]=1;
        if(o==j) s=suma(o);
        else backt(i,j,k+1);
        p[o]=0;         ///p[i] nu functiona
    }

}
int main()
{
    int i,j;
   f>>n>>m;
   for(i=1;i<=m;i++)
    f>>c>>y>>s,a[c][y]=a[y][c]=s;
   for(i=1;i<=n;i++)
    {
        s=0;
        for (j=1;j<=n;j++)
            if(a[i][j]) s++;
        gr[i]=s;
    }
    for(i=1;i<=n;i++)
    {
        if(gr[i]==1)
        {
            for(j=i+1;j<=n;j++)
                if(gr[j]==1)
            {
                backt(i,j,2);
                if(s==max1) nr++;   ////grija la ifuri
                if(s>max1) max1=s,nr=1;


            }
        }

    }
    g<<(max1*nr*2)%1000000007;


    return 0;
}
