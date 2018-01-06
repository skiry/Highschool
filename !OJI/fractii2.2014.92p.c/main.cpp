#include <fstream>

using namespace std;
ifstream f("fractii2.in");
ofstream g("fractii2.out");
int p,n,i,j,v[2001][1000],a,b;
int main()
{
    f>>p>>n;
    if(p==1)
    {
        for(i=1;i<n;i++)
            g<<i<<" ";
        g<<i-1;
    }
    else if(p==2)
    {
        v[2][1]=1;///prin 2 fractii pot forma doar printr o singura metoda 1 (1/2+1/2)
        for(i=3;i<=n;i++)
            for(j=1;j<=i/2;j++)
        {
            a=(j+1)/2-1;
            b=(i-j)/2;
            v[i][j]=v[i][j-1]+v[i-j][b]-v[i-j][a];
            v[i][j]%=100003;
        }
        g<<v[n][n/2];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)g<<v[i][j]<<" ";g<<endl;}
    return 0;
}
