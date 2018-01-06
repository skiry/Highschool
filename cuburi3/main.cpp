#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("cuburi3.in");
ofstream g("cuburi3.out");
int n,i,j,maxim,poz,nr;
struct element
{
    int l,g,v,ant,in;
};
element p;
vector <element> a;
inline bool cmp(const element &b,const element &c)
{
    if(b.l==c.l) return b.g>c.g;
    return b.l>c.l;
}
void afis(int i)
{
    if(i) if(a[i].ant||(!a[i].ant&&a[0].l>=a[i].l&&a[0].g>=a[i].g)) nr++,afis(a[i].ant);
    if(nr) {g<<nr+1<<" "<<maxim<<'\n';nr=0;}
    g<<a[i].in<<'\n';
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>p.l>>p.g,p.v=p.l,p.in=i,a.push_back(p);
    sort(a.begin(),a.end(),cmp);
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
            if(a[j].g>=a[i].g&&a[j].v+a[i].l>a[i].v) a[i].v=a[j].v+a[i].l,a[i].ant=j;
        if(a[i].v>maxim) maxim=a[i].v,poz=i;
    }
    afis(poz);
    return 0;
}
