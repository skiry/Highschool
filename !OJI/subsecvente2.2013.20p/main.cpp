#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream f("subsecvente2.in");
ofstream g("subsecvente2.out");
int n,i,j,h,maxim=0,d[160][160][160],m[6400][6400];
char a[5][20001];
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
     if(n==2)
       {
           for(i=0;i<strlen(a[1]);i++)
                for(j=0;j<strlen(a[2]);j++)
                    {
                        if(a[1][i]==a[2][j]) {
                                m[i+1][j+1]=m[i][j]+1;
                        if(m[i+1][j+1]>maxim) maxim=m[i+1][j+1];
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
        for(i=0;i<strlen(a[1]);i++)
            for(j=0;j<strlen(a[2]);j++)
                if(a[1][i]==a[2][j])
                    for(h=0;h<strlen(a[3]);h++)
                    {
                        if(a[2][j]==a[3][h]) {
                                d[i+1][j+1][h+1]=d[i][j][h]+1;
                        if(d[i+1][j+1][h+1]>maxim) maxim=d[i+1][j+1][h+1];
                        }
                        //else d[i][j]=max(d[i-1][j],d[i][j-1]);
                    }
            g<<maxim;
    }

    return 0;
}
