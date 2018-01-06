#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,n,i,j,a[102][102],viz[102],k,aici,sol[51];
void sortare(int i,int j,int x)
{
    if(a[i][x]==a[j][x]) sortare(i,j,x+1);
    else if(a[i][x]>a[j][x])
    {
        for(int k=1;k<=n;k++)
            swap(a[i][k],a[j][k]);
    }
}
int main()
{
    f>>t;
    for(int u = 1; u <= t ; u++)
    {
        f>>n;
        for(j = 1; j <= 2*n - 1; j++)
            for(k = 1; k <= n; k++)
                    f>>a[j][k];
    for(i=1;i<2*n-1;i++)
        for(j=i+1;j<=2*n-1;j++)
                sortare(i,j,1);
    /**for(i=1;i<=cm;i++) if(viz[i]==1) aici=i;
    for(i=1;i<=2*n-1;i++)
        if(aici-a[i][1]<minim) minim=a[i][1];
    for(i=1;i<=2*n-1;i++)
        if(a[i][1]==minim)
    {
        for(j=1;j<=n;j++)
            if(!sol[j]) sol[j]=a[i][j]+1;
           else if(a[i][j]==sol[j]&&sol[j]) sol[j]=a[i][j]+1;
    }*/
    //for(j = 1; j <= 2*n - 1; j++){
          //  for(k = 1; k <= n; k++)
                //    g<<a[j][k]<<" ";g<<endl;}
    aici=0;
    if(a[1][1]!=a[2][1]) aici=1;
    else if(a[2*n-1][1]!=a[2*n][1]) aici=2*n-1;
    else{
    for(i=1;i<=2*n-1&&!aici;i++)
        {
            if(a[i+1]!=a[i]) aici=i;
            i++;
        }
    }
    for(i=1;i<=n;i++) sol[i]=a[aici-1][i]+1;
    g<<"Case #"<<u<<": ";for(i=1;i<=n;i++) g<<sol[i]<<" ";
    g<<endl;
    }
    return 0;
}
