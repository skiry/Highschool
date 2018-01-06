#include <fstream>

using namespace std;
ifstream f("concurs.in");
ofstream g("concurs.out");
int a[505][104],b[1000],i,j,n,poz,q,ok,k,nr,h[1000];
int main()
{f>>n;
for(i=1;i<=n;i++)
    for(j=1;j<=2;j++)
        f>>a[i][j];

    k=0;
    for(i=1;i<=n;i++)
    {ok=1;
    for(j=1;j<=k&&ok;j++)
    if(a[i][1]==b[j]){ok=0;poz=j;}
    if(ok==1){k++;b[k]=a[i][1];h[k]=1;}
    else h[poz]++;
    }

    for(i=1;i<=n;i++) if(b[i]) nr++;
    g<<nr;
    g<<'\n';
    for(i=1;i<=n;i++) if(h[i]) g<<h[i]<<" ";
    g<<'\n';

    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++) if(a[i][2]>a[j][2]) {swap(a[i][2],a[j][2]);swap(a[i][1],a[j][1]);}

        for(i=1;i<n-1;i++)
            if(a[i+1][1]==a[i+2][1]) {swap(a[i][2],a[i+1][2]);swap(a[i][1],a[i+1][1]);}

    for(i=1;i<=n;i++)
        {for(j=1;j<=2;j++)
        g<<a[i][j]<<" ";
        g<<'\n';}

    return 0;
}
