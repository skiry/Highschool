#include <bits/stdc++.h>

using namespace std;
ifstream f("diff.in");
ofstream g("diff.out");
long b[200001],ft[200001],n,m,el,nrf,nrb,i,j,af[200001];
struct rez
{
    long st,dr;
}s[300001][2];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>el;
        if(el) b[i]=++nrb,ft[i]=ft[i-1];
        else ft[i]=++nrf,b[i]=b[i-1];
    }
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
        {
            el=b[j]-b[i-1]-ft[j]+ft[i-1];
            if(el>=-100001&&el<=100001)
            {
                if(el>=0) s[el][1].st=i,s[el][1].dr=j;
                else {el*=(-1); s[el][2].st=i,s[el][2].dr=j;}
            }
        }
    for(i=1;i<=m;i++)
    {
        f>>el;
        if(el>=-100001&&el<=100001)
        {
            int ok=1;
            if(el>=0&&s[el][1].st) g<<s[el][1].st<<" "<<s[el][1].dr<<'\n',ok=0;
            else if(el<0) {el*=(-1);if(s[el][2].st) g<<s[el][2].st<<" "<<s[el][2].dr<<'\n',ok=0;}
            if(ok) g<<"-1"<<'\n';
        }
        else g<<"-1"<<'\n';
    }
    return 0;
}
