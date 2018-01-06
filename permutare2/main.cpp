#include <bits/stdc++.h>

using namespace std;
ifstream f("permutare2.in");
ofstream g("permutare2.out");
long long n,m,a,s,i,rez,v[100001],minim=999999999999,j;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a;
    for(i=1;i<m;i++)
        f>>v[i];
    for(j=0;j<=n+20;j++)
    {
        rez=min(j,n-j);
        for(i=1;i<m;i++)
            rez+=min(abs(j-v[i]),abs(n-j+v[i]));
        minim=min(minim,rez);
    }
    g<<minim;
    return 0;
}
