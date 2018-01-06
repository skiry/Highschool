#include <fstream>
#include <vector>
using namespace std;
ifstream f("euro2.in");
ofstream g("euro2.out");
int n,i,j,maxim;
double el;
struct element
{
    int v,cresc,dec;
};
element p;
vector <element> a;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>el;
        el*=10000;
        p.v=el;
        p.cresc=p.dec=0;
        a.push_back(p);
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
            if(a[j].v<a[i].v&&a[i].cresc<a[j].cresc+1)
                a[i].cresc=a[j].cresc+1;
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
            if(a[i].v>a[j].v&&a[i].dec<a[j].dec+1)
                a[i].dec=a[j].dec+1;
        if(a[i].cresc+a[i].dec>maxim-1&&a[i].cresc>0&&a[j].dec>=0) maxim=a[i].cresc+a[i].dec+1;
    }
    g<<maxim;
    return 0;
}
