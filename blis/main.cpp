#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
ifstream f("blis.in");
ofstream g("blis.out");
int k,i,n,v,m;
char a[100001];
int main()
{
    f>>k;
    f.get();
    f.get(a,1500);
    n=strlen(a);
    if(k>=n)
        for(i=0;i<n;i++)
            if(a[i]&1) v+=1<<(n-i-1);
    m=v;
    if(k<n)
    {
        for(i=0;i<k;i++)
            if(a[i]&1) v+=1<<(k-i-1);
        m=v;
        for(i=k;i<n;i++)
        {
            if(a[i-k]&1) v-=1<<(k-1);
            v<<=1;
            if(a[i]&1) v+=1;
            if(v>m) m=v;
        }
    }
    g<<m;

    return 0;
}
