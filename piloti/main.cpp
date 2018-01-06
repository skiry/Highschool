#include <fstream>
#include <queue>
using namespace std;
ifstream f("piloti.in");
ofstream g("piloti.out");
int n,i,c,as,total;
struct cmp
{
    bool operator() (const int &a, const int &b)
    {
        return a<b;
    }
};
priority_queue <int, vector<int>, cmp> q;
int main()
{
    f>>n;
    f>>c>>as;
    total+=as;
    for(i=1;i<n;i++)
    {
        f>>c>>as;
        total+=c;
        q.push(c-as);
        if(i%2==0)
        {
            total-=q.top();
            q.pop();
        }
    }
    g<<total;
    return 0;
}
