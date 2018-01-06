#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i,j,b,c,v[100001];
struct nod
{
    int nr,init;
};
nod rez[100001];
bool cmp(const nod &b,const nod &c)
{
    return b.nr<c.nr;
}
vector <int> a[100001];
int main()
{
    f>>n;
    for(i=1;i<n;i++)
        f>>b>>c,a[b].push_back(c),a[c].push_back(b),rez[i].init=i;
    rez[n].init=n;
    for(i=1;i<=n;i++) f>>v[i];
    /**for(i=1;i<=n;i++){g<<v[i]<<" : ";
        for(j=0;j<a[i].size();j++)
        g<<v[a[i][j]]<<" ";g<<endl;}*/
    for(i=1;i<=n;i++)
    {
        for(j=0;j<a[i].size();j++)
            if(v[i]!=v[a[i][j]]) rez[i].nr++,rez[a[i][j]].nr++;
    }
    sort(rez+1,rez+n+1,cmp);
    if(rez[n-1].nr==rez[n].nr) g<<"NO";
    else
        {
            g<<"YES"<<endl;
            g<<rez[n].init;
        }
    return 0;
}
