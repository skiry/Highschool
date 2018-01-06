#include <fstream>

using namespace std;
ifstream f("deal.in");
ofstream g("deal.out");
int a[10000],i,j,b[10000],n,s;
int main()
{f>>n;
   for(i=1;i<=n;i++)
        f>>a[i];
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
            if(a[i]<a[j]) swap (a[i],a[j]);

    for(i=1;i<=n/2;i++) s+=a[i];
    g<<s;




    return 0;
}
