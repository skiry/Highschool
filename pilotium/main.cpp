#include <fstream>
#include <queue>
using namespace std;
ifstream f("piloti.in");
ofstream g("piloti.out");
int n,i,cap,as,s;
struct cmp
{
    bool operator() (int const &a, int const &b)
    {
        return a<b;
    }
};
priority_queue < int, vector < int >, cmp> q;
int main()
{
    f>>n;
    f>>cap>>as;
    s+=as;
    for(i=1;i<n;i++)
    {
        f>>cap>>as;
        s+=cap;
        q.push(cap-as);
        if(i%2==0)
        {
            s-=q.top();
            q.pop();
        }
    }
    g<<s;
    return 0;
}
