#include <bits/stdc++.h>

using namespace std;
ifstream f("diff.in");
ofstream g("diff.out");
int b[100001],n,m,el,i,j;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>el;
        if(el) b[i]=b[i-1]+1;
        else b[i]=b[i-1]-1;
    }
    for(int k=1;k<=m;k++)
    {
        f>>el;
        int ok=0;
        for(i=1;i<n&&!ok;i++)
            for(j=i+1;j<=n&&!ok;j++)
                if(b[j]-b[i-1]==el) ok++,g<<i<<" "<<j<<endl;
        if(ok) ;
        else g<<"-1"<<'\n';
    }
    return 0;
}
