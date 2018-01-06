#include <fstream>

using namespace std;
ifstream f("circuite.in");
ofstream g("circuite.out");
int i,a[32],el,ok=1,n,j;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        f>>el;
        if(el) a[i]=a[i]|(1<<j);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            if(a[j]&(1<<i)) a[j]=a[j]|a[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            if(!(a[i]&(1<<j))) ok=0;
    }

    if(ok) g<<"DA";
    else g<<"NU";
    g<<'\n';

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            if(a[i]&(1<<j)) g<<"1 ";
            else g<<"0 ";
        g<<'\n';
    }

    return 0;
}
