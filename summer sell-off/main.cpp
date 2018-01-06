#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("date.in");
ofstream cout("date.out");
int n,f,i;
struct produse
{
    int s,d;
};
produse el;
struct cmp
{
    bool operator() (const produse &b, const produse &c)
    {
        return b.d-b.s<c.d-c.s;
    }
};
vector <produse> a[100001];
priority_queue < produse , vector < produse > , cmp > q;
int main()
{
    cin>>n>>f;
    for(i=1;i<=n;i++) cin>>el.s>>el.d,q.push(el);
    while(q.size()) cout<<q.top().s<<" "<<q.top().d<<endl,q.pop();
    return 0;
}
