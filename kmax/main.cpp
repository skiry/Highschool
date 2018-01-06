#include <bits/stdc++.h>

using namespace std;
ifstream f("kmax.in");
ofstream g("kmax.out");
int n,m,r,viz[301],cresc[301],sol[301],rez;
void backt(int nr)
{
    if(nr==n) ++rez;
    else if(nr<n)
    {
        for(int i=1;i<=n;i++)
            if(!viz[i])
        {
            if(!nr) sol[nr]=i,++viz[i],cresc[nr]=1,backt(nr+1);
            else if(nr)
            {
                if(i<sol[nr-1]) sol[nr]=i,++viz[i],cresc[nr]=1,backt(nr+1);
                else if(i>sol[nr-1]&&cresc[nr-1]<=m-1) sol[nr]=i,++viz[i],cresc[nr]=cresc[nr-1]+1,backt(nr+1);
            }
            viz[i]=0;
        }
    }
}
int main()
{
    f>>n>>m>>r;
    backt(0);
    g<<rez%r;
    return 0;
}
