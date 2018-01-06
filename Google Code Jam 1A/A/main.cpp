#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,n,u,i,j,k;
char a[1001],b[2002];
int main()
{
    f>>t;
    for(u = 1; u <= t ; u++)
    {
        f>>a;
        b[1000]=a[0];
        j=1001;
        k=999;
        g<<"Case #"<<u<<": ";
        for(i=1;i<strlen(a);i++)
            if(a[i]>b[j-1])
                    b[k]=a[i],k--;

            else if(a[i]<=b[j-1]) b[j]=a[i],j++;

        for(i=k+1;i<j;i++) g<<b[i];
        g<<endl;
    }
    return 0;
}
