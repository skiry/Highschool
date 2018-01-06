#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;
ifstream f("barci.in");
ofstream g("barci.out");
int n,maxim,dif,i,rez,el,viz[100001],ok,j;
deque <int> q;
inline bool cmp(const int &a, const int &b)
{
    return a>b;
}
int main()
{
    f>>n>>maxim>>dif;
    for(i=1;i<=n;i++) f>>el,q.push_back(el);
    sort(q.begin(),q.end(),cmp);
    for(i=0;i<q.size()-1;i++)
    if(!viz[i])
    {
        ok=0;
        for(j=i+1;j<q.size()&&!ok;j++)
            if(!viz[j]&&q[j]+q[i]<=maxim&&max(q[j],q[i])-min(q[j],q[i])<=dif) ok=1,viz[i]++,viz[j]++;
        rez++;
    }
    if(!viz[q.size()-1]) rez++;
    g<<rez;
    return 0;
}
