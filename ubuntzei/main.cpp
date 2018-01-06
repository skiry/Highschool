#include <fstream>

using namespace std;
ifstream f("ubuntzei.in");
ofstream g("ubuntzei.out");
int n,ma,i,j,k,a[2000][2000],viz[2000],x,y,z,nr=1,val[16],m[16],vmax=999999;
void parc(int b)
{
    viz[b]=2;
    if(k>1)
    {
        for(int i=1;i<=k;i++)
            if(viz[val[i]]==1)
                nr++,m[nr]=m[nr-1]+a[b][val[i]],parc(val[i]);
        if(nr==k)
            if(m[nr]+a[b][n]<vmax) vmax=m[nr]+a[b][n];//,g<<vmax<<" vmax"<<endl;

//g<<m[nr-1]<<" m "<<m[nr]<<" b:"<<b<<" nr:"<<nr<<endl;
    nr--;
    viz[b]=1;
    }
    else if(k==1)
        vmax=m[1]+a[b][n];
}
int main()
{
    f>>n>>ma;
    f>>k;
    for(i=1;i<=k;i++) f>>x,viz[x]=1,val[i]=x;
    for(i=1;i<=ma;i++)
            f>>x>>y>>z,a[x][y]=a[y][x]=z;
    for(int ki=1;ki<=n;ki++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if((a[i][j]>a[i][ki]+a[ki][j]||!a[i][j])&&a[i][ki]&&a[ki][j]&&i!=j)
                    a[i][j]=a[i][ki]+a[ki][j];
    if(!k) g<<a[1][n];
    if(k)
    {
        for(i=1;i<=k;i++)
            m[1]=a[1][val[i]],nr=1,parc(val[i]);
        //g<<"vmax "<<vmax<<endl;
        g<<vmax;
    }

//for(i=1;i<=n;i++){
      //      for(j=1;j<=n;j++)
         //       g<<a[i][j]<<" ";g<<endl;}

    return 0;
}
