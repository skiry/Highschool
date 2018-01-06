#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int nrp[100],i,j,n;
char a[100];
int palindrom(int x, int y)
{
    int ok=1;
    for(int i=1;i<=(y-x)/2+1;i++)
    {
        if(a[x]!=a[y]) ok=0,i=y;
        else x++,y--;
    }
    return ok;
}
int main()
{
    f.get(a,100);
    n=strlen(a);
    for(i=0;i<n;i++)
        {if(palindrom(0,i)) nrp[i]=1;
        else
        {
            int nr=9999;
            for(j=0;j<i;j++)
                if(nrp[j]<nr&&palindrom(j+1,i)) nr=nrp[j];
            nrp[i]=nr+1;

        }


        }
        g<<nrp[n-1];
    return 0;
}
