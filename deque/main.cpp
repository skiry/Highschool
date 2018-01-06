#include <fstream>
#include <deque>
using namespace std;
ifstream f("deque.in");
ofstream g("deque.out");
int n,k,i,j;
long long minim;
struct el
{
    long long v;
    int cnt;
};
el p;
deque <el> q;
int main()
{
    f>>n>>k;
    f>>p.v;
    q.push_back(p);
    for(i=1;i<k;i++)
    {
        f>>p.v;
        p.cnt=i;
        j=q.size()-1;
        while(j>=0&&q[j].v>p.v) q.pop_back(),j--;
        q.push_back(p);
    }
    minim+=q[0].v;
    for(i=k;i<n;i++)
    {
        f>>p.v;
        p.cnt=i;
        j=q.size()-1;
        while(j>=0&&q[j].v>p.v) q.pop_back(),j--;
        q.push_back(p);
        if(i-q[0].cnt>k-1) q.pop_front();
        minim+=q[0].v;
    }
    g<<minim;
    return 0;
}
