#include <fstream>
#include <vector>
using namespace std;
ifstream f("arbvalmax.in");
ofstream g("arbvalmax.out");
struct el
{
    int v,viz;
};
el p[300001];
int n,interogari,i,x,y,viz[300001],m;
vector <int> a[300001];
void df(int nr,int ok,int k)
{
   if(nr==y) ok=1;
   if(!ok)
    for(int r=0;r<a[nr].size();r++)
        if(viz[a[nr][r]]!=k) viz[a[nr][r]]=k,p[a[nr][r]].viz=k,df(a[nr][r],ok,k),p[a[nr][r]].viz=0;
}
int main()
{
    f>>n>>m;
    for(i=1;i<n;i++)
        f>>x,a[x][i+1]=a[i+1][x]=1;
    for(i=1;i<=n;i++)
        f>>p[i].v;
    for(int k=1;k<=m;k++)
    {
        f>>x>>y;
        df(x,0,k);
    }
    return 0;
}
