#include <fstream>
#include <deque>
#include <queue>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
long long n,l,r,i,b,nr;
deque <long long> q;
queue <int> c;
int main()
{
    f>>n>>l>>r;
    q.push_front(n);
    int ok=1;
    while(q.back()/2!=1) q.push_back(q.back()/2);
    c.push(q.back()/2);
    c.push(q.back()%2);
    c.push(q.back()/2);
    nr=3;
    while(c.size()<r)
    {
        q.pop_back();
        c.push(q.back()%2);
        nr++;
        b=c.size()-2;
        for(i=b;i>=0;i--)
            c.push(c[i]),nr++;
        if(nr<l)
            while(c.size()) c.pop();
    }
    while(c.size())
    {g<<c.front()<<endl;c.pop();}
    //for(i=l-1;i<r;i++)
        //if(c[i]==1) nr++;
    g<<nr;
    return 0;
}
