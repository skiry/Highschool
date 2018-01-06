#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,i,j,v,u;
char a[1001][501],b[1001][501];
int main()
{
    f>>n>>m;
    f.get();
    for(i=1;i<=n;i++)
        f.getline(a[i],501);
    for(i=1;i<=m;i++)
        f.getline(b[i],501);
    if(n<m) g<<"NO";
    else if(n>m) g<<"YES";
    else{
            v=n;
            u=m;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(!strcmp(a[i],b[j])) v--,u--;
        if((m-v)%2==0) g<<"NO";
        else g<<"YES";
    }
    return 0;
}
