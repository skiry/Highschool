#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,m,a[101],i,j,l[101],ant[101],lmax,loc;
void afis(int b)
{
    if(ant[b]) afis(ant[b]);
    g<<a[b]<<" ";
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
    f>>m;
    l[1]=1;
    ant[1]=0;
    for(i=2;i<=m;i++)
    {
        for(j=1;j<i;j++)
            if(a[j]<=a[i]&&l[j]>l[i])
                l[i]=l[j],ant[i]=j;
       l[i]++;
        if(l[i]>lmax) lmax=l[i],loc=i;
    }
    for(i=m+1;i<=n;i++)
    {
        for(j=i-m;j<i;j++)
            if(a[j]<=a[i]&&l[j]>l[i])
                l[i]=l[j],ant[i]=j;
        if(!ant[i]) l[i]=-300;
        else l[i]++;
        if(l[i]>lmax) lmax=l[i],loc=i;
    }

    if(l[n]>0) afis(loc);
    else g<<"Nu ajunge!";
    return 0;
}
