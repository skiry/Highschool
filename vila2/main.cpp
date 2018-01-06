#include <fstream>
#include <deque>
using namespace std;
ifstream f("vila2.in");
ofstream g("vila2.out");
int n,k,e,maxim,i,j;
struct el
{
    int v,cnt;
};
el p;
deque <el> ma;
deque <el> mi;
int main()
{
    f>>n>>k;
    f>>p.v;
    ma.push_back(p);
    mi.push_back(p);
    for(i=1;i<=k;i++)
    {
        f>>p.v;
        p.cnt=i;
        j=ma.size()-1;
        while(j>=0&&ma[j].v<p.v) ma.pop_back(),j--;
        ma.push_back(p);
        j=mi.size()-1;
        while(j>=0&&mi[j].v>p.v) mi.pop_back(),j--;
        mi.push_back(p);
        if(ma[0].v-mi[0].v>maxim) maxim=ma[0].v-mi[0].v;
    }
    for(i=k+1;i<n;i++)
    {
        f>>p.v;
        p.cnt=i;
        j=ma.size()-1;
        while(j>=0&&ma[j].v<p.v) ma.pop_back(),j--;
        ma.push_back(p);
        j=mi.size()-1;
        while(j>=0&&mi[j].v>p.v) mi.pop_back(),j--;
        mi.push_back(p);
        if(i-ma[0].cnt>k) ma.pop_front();
        if(i-mi[0].cnt>k) mi.pop_front();
        if(ma[0].v-mi[0].v>maxim) maxim=ma[0].v-mi[0].v;
    }
    g<<maxim;
    return 0;
}
