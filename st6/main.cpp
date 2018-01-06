#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;
ifstream f("6st.in");
ofstream g("6st.out");
int n,m,i,j,k,crs[301],minim[301],actual,prezent,el,minact,gint[301],gext[301],viz[301],initial,nr,total[301],vizcalc[301],suma;
vector <int> a[301];
deque <int> q;
vector <int> ordine;
vector <int> rez;
queue <int> calc;
vector <int>::iterator it;
inline bool cmp(const int &bb,const int &cc)
{
    if(minim[bb]==minim[cc]) return crs[bb]<crs[cc];
    return minim[bb]>minim[cc];
}
void calculeaza(int valoare)
{
    if(!viz[valoare]) nr++;
    viz[valoare]++;
    for(int j=0;j<a[valoare].size();j++)
    if(crs[a[valoare][j]]-total[a[valoare][j]]>0&&viz[a[valoare][j]]<m)
    {
        prezent=a[valoare][j];
        if(!total[prezent])
        {
            if(total[valoare]>=crs[prezent]) total[prezent]=crs[prezent];
            else total[prezent]=total[valoare];
            if(a[valoare].size()>1) total[valoare]-=total[prezent];
            else total[valoare]=0;
        }
        else
        {
            if(total[valoare]>=crs[prezent]-total[prezent]) total[prezent]=crs[prezent];
            else total[prezent]+=total[valoare];
            total[valoare]=0;
        }
        calculeaza(prezent);
    }
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++) f>>crs[i];
    f>>m;
    for(i=1;i<=n;i++) minim[i]=999;
    for(i=1;i<=m;i++)
    {
        f>>k;
        for(j=1;j<=k;j++)
            f>>el,q.push_back(el);
        actual=q.back();
        calc.push(actual);
        q.pop_back();
        minact=crs[actual];
        minim[actual]=min(minim[actual],minact);
        while(q.size())
        {
            prezent=q.back();
            q.pop_back();
            gint[actual]++;
            gext[prezent]++;
            minact=min(minact,crs[prezent]);
            minim[prezent]=min(minim[prezent],minact);
            a[prezent].push_back(actual);
            actual=prezent;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(a[i].size()>1) sort(a[i].begin(),a[i].end(),cmp);
        it=unique(a[i].begin(),a[i].end());
        a[i].resize(distance(a[i].begin(),it));
        if(gext[i]&&!gint[i]) ordine.push_back(i);
        else if(gext[i]&gint[i]) rez.push_back(i);
    }
    sort(ordine.begin(),ordine.end(),cmp);
    for(i=0;i<ordine.size();i++)
    {
        actual=ordine[i];
        if(!viz[actual]) total[actual]=crs[actual],calculeaza(actual);
    }
    if(nr!=n)
    {
        sort(rez.begin(),rez.end(),cmp);
        for(i=0;i<rez.size();i++)
        {
            actual=rez[i];
            if(!viz[actual]) total[actual]=crs[actual],calculeaza(actual);
        }
    }
    while(calc.size())
    {
        actual=calc.front();
        calc.pop();
        if(!vizcalc[actual]) suma+=total[actual],vizcalc[actual]++;
    }
    g<<suma;
    return 0;
}
