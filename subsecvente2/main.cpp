#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream f("subsecvente2.in");
ofstream g("subsecvente2.out");
int n,i,j,h,maxim=0;
char a[5][20001];
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
    if(n==2)
       {
           int d[1000][1000];
           for(i=0;i<strlen(a[1]);i++)
                for(j=0;j<strlen(a[2]);j++)
                    {
                        if(a[1][i]==a[2][j]) {
                                if(i&&j) d[i][j]=d[i-1][j-1]+1;
                                else d[i][j]=1;
                        if(d[i][j]>maxim) maxim=d[i][j];
                        }
                        //else d[i][j]=max(d[i-1][j],d[i][j-1]);
                    }
            g<<maxim;
            /**for(i=0;i<strlen(a[1]);i++){
                for(j=0;j<strlen(a[2]);j++)
                    g<<d[i][j]<<" ";g<<endl;}*/
       }
    else if(n==3)
    {
        int d[100][100][100];
        for(i=0;i<strlen(a[1]);i++)
            for(j=0;j<strlen(a[2]);j++)
                {
                    if(a[1][i]==a[2][j])
                    for(h=0;h<strlen(a[3]);h++)
                    {
                        if(a[2][j]==a[3][h]) {
                                if(i&&j&&h) d[i][j][h]=d[i-1][j-1][h-1]+1;
                                else d[i][j][h]=1;
                        if(d[i][j][h]>maxim) maxim=d[i][j][h];
                        }
                        //else d[i][j]=max(d[i-1][j],d[i][j-1]);
                    }
                }
            g<<maxim;
    }

    return 0;
}
