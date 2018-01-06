#include <bits/stdc++.h>

using namespace std;
ifstream f("submatrix.in");
ofstream g("submatrix.out");
int n,m,k,a[301][301],i,j,frecv[901],ok,contor;
vector <int> v;
vector <int>::iterator it;
queue <int> q;
int main()
{
    f>>n>>m>>k;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        f>>a[i][j],v.push_back(a[i][j]);
    sort(v.begin(),v.end());
    it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    for(int l=min(n,m);l>1&&!ok;l--)
    {
        for(i=1;i<=n-l+1&&!ok;i++)
            for(j=1;j<=m-l+1&&!ok;j++)
        {
            for(int o=i;o<=i+l-1;o++)
                for(int p=j;p<=j+l-1;p++)
            {
                it=lower_bound(v.begin(),v.end(),a[o][p]);
                if(!frecv[it-v.begin()+1]) ++contor,q.push(it-v.begin()+1);
                ++frecv[it-v.begin()+1];
            }
            if(contor<=k) ok=l;
            while(q.size())
                frecv[q.front()]=0,q.pop();
            contor=0;
        }
    }
    if(ok) g<<ok;
    else g<<"1";
    return 0;
}
