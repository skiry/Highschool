#include <fstream>
#include <string.h>
using namespace std;
ifstream f("gravity.in");
ofstream g("gravity.out");
char a[1751][1751];
int n,m,i,j,viz[1751],nr;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        //for(j=1;j<=m;j++)
        f>>a[i];
    for(i=n;i>=1;i--)
    {
        int ok=0;
        for(j=1;j<=m;j++)
            if(a[i][j]=='#') ok=1;
        if(!ok) viz[i]=-1,++nr;
        else viz[i]=nr;
    }
    for(i=n;i>=1;i--)
    {
       if(viz[i]&&viz[i]!=-1)
            strcpy(a[i+viz[i]],a[i]);
    }
    for(i=1;i<=n;i++){
        for(j=0;j<m;j++)
            g<<a[i][j];g<<endl;}
            g<<nr;
    return 0;
}
