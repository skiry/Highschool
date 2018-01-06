#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("sushi2.in");
ofstream g("sushi2.out");
int n,m,i,j,k,nr,d,viz[100001],timp[100001],x,y,t,actual11,el,h;
vector <int> a[100001];
struct sushiii
{
    int act,dus,timpp;
};
sushiii comb,actual;
queue <sushiii> q;
void dijkstra(int d)
{
    while(q.size()) q.pop();
    comb.act=x;
    comb.dus=y;
    comb.timpp=t;
    q.push(comb);
    while(nr<n)
    {
        actual=q.front();
        //g<<actual.act<<" "<<actual.dus<<" "<<actual.timpp<<" "<<nr<<endl;
        q.pop();
        if(viz[actual.act]!=d)
        {
            timp[actual.act]=max(timp[actual.act],actual.timpp);
            viz[actual.act]=d;
            nr++;
        }
        int maducpe=a[actual.act][actual.dus-1];
        for(int i=0;i<a[maducpe].size();i++)
            if(a[maducpe][i]==actual.act)
        {
            actual11=i;
            break;
        }
        if(actual11+1<a[maducpe].size()) comb.act=maducpe,comb.dus=actual11+2,comb.timpp=actual.timpp+1,q.push(comb);
        else comb.act=maducpe,comb.dus=1,comb.timpp=actual.timpp+1,q.push(comb);
        h++;
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>k;
        for(j=1;j<=k;j++)
            f>>el,a[i].push_back(el);
    }
    for(int d=1;d<=m;d++)
    {
        f>>x>>y>>t;
        nr=0;
        dijkstra(d);
    }
    for(i=1;i<=n;i++)
        g<<timp[i]<<" ";

    return 0;
}
