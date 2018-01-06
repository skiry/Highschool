#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
ifstream f("stalpi2.in");
ofstream g("stalpi2.out");
int n,e,i,a[50],maxim=99999999,s;
int main()
{
    f>>n>>e;--n;
    for(i=1;i<=n;i++)
        f>>a[i],s+=a[i]-a[i-1];
    if(n==2)
    {
        int s1=a[1],s2=a[2]-a[1];
        while(e)
        {
            --s1;
            ++s2;
            maxim=min(max(s1,s2),maxim);
            --e;
        }
        g<<maxim;
    }
    else g<<s/n+1;
    return 0;
}
