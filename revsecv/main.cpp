#include <fstream>
#include <string.h>
using namespace std;
ifstream f("revsecv.in");
ofstream g("revsecv.out");
char a[100000];
int n,ok,i,nr;
int main()
{
    f.get(a,100000);
    n=strlen(a);
    for(int k=0;k<n;k++)
        for(i=0;i<n-k;i++)
            {
                ok=1;
                for(int j=n-k;j<n&&ok;j++)
                    {
                        if(a[i]!=a[j]) ok=0;
                    }
                if(ok) nr++;
            }
g<<nr;
    return 0;
}
