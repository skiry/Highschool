#include <fstream>
#include <string.h>
using namespace std;
ifstream f("subsecvente2.in");
ofstream g("subsecvente2.out");
char a[5][50001];
int b[20001][20001],n,i,j,cmax,x,y;
int main()
{
    f>>n;
    for(i=1;i<=n;i++) f>>a[i];
    x=strlen(a[1]);
    y=strlen(a[2]);
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
                if(a[1][i]==a[2][j])
               {
                   b[i][j]=b[i-1][j-1]+1;
                   if(cmax<b[i][j])
                        cmax=b[i][j];
               }

    g<<cmax;
    return 0;
}
