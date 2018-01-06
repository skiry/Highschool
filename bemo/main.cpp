#include <fstream>
#include <deque>
using namespace std;
ifstream f("bemo.in");
ofstream g("bemo.out");
int n,m,a[1501][1501],viz[1200000];
struct element
{
    int l,c;
};
element st,dr,el;
void dei(element s,element d)
{
    viz[a[s.l][s.c]]=viz[a[d.l][d.c]]=1;
    int minim=9999999;
    for(int i=s.l;i<=d.l;i++)
        for(int j=s.c;j<=d.c;j++)
        if((i!=s.l||j!=s.c)&&(i!=d.l||j!=d.c))
            if(minim>a[i][j]) minim=a[i][j],el.l=i,el.c=j;
    if(minim!=9999999)
    {dei(s,el);
    dei(el,d);}
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        f>>a[i][j];
    st.l=1;
    st.c=1;
    dr.l=n;
    dr.c=m;
    dei(st,dr);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(viz[a[i][j]]) g<<a[i][j]<<" ";
    }
    return 0;
}
