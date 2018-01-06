#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");
int n,m,b,c,i,d[50001];
vector <int> a[50001];
queue <int> q;
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>b>>c;
        a[b].push_back(c);
        d[c]++;
    }
    for(i=1;i<=n;i++)
        if(!d[i]) q.push(i);
    while(q.size())
    {
        int actual=q.front();
        g<<actual<<" ";
        q.pop();
        for(i=0;i<a[actual].size();i++)
            if(!--d[a[actual][i]]) q.push(a[actual][i]);
    }
    return 0;
}
