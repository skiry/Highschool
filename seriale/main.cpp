#include <fstream>

using namespace std;
ifstream f("seriale.in");
ofstream g("seriale.out");
int n,k,i,j,a[1000],b[1000],ok=1,poz,min1,max1,v,ok1;
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++) f>>a[i];
    for(i=1;i<=k;i++) f>>b[i];
    for(i=1;i<=k;i++)
        for(j=i+1;j<=k;j++) if(b[i]>b[j]) swap(b[i],b[j]);
        v=n+k+1;
    for(i=1;i<=v-n-1&&ok;i++)
    {
        ok1=1;
        max1=0;
        min1=v;
        for(j=1;j<=n;j++)
            if(i%2)
                {
                    if(a[j]>max1) max1=a[j],poz=j;
                }
            else if(i%2==0)
                {
                    if(a[j]<min1) min1=a[j],poz=j;
                }
        for(j=poz;j<n;j++) a[j]=a[j+1];
        a[n]=b[i];
        k--;
        for(int o=1;o<=n;o++)
        for(int p=o+1;p<=n;p++) if(a[o]>a[p]) ok1=0;
        if(ok1==1) ok=0,g<<i;
    }
    if(ok) g<<"-1";
    return 0;
}
