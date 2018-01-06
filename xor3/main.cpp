#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;
ifstream f("xor3.in");
ofstream g("xor3.out");
int k,x,y,a,b,m,i,linie,coloana,matr[2][30001],necesar;
struct dublu
{
    int l,c,in,rez;
};
dublu el;
deque <dublu> q;
inline bool cmp(const dublu &p,const dublu &d)
{
    if(p.l==d.l) return p.c<d.c;
    return p.l<d.l;
}
inline bool cmp1(const dublu &p,const dublu &d)
{
    return p.in<d.in;
}
int main()
{
    f>>k>>x>>y>>a>>b>>m;
    for(i=1;i<=k;i++)
    {
        linie=max(linie,x);
        coloana=max(coloana,y);
        el.l=x;
        el.c=y;
        el.in=i;
        el.rez=0;
        q.push_back(el);
        x=(a*x+b)%m;
        y=(a*y+b)%m;
    }
    sort(q.begin(),q.end(),cmp);
    for(i=0;i<=coloana;i++)
    {
        matr[0][i]=i;
        while(i==q[necesar].c&&q[necesar].l==0) q[necesar].rez=matr[0][i],necesar++;
    }
    for(int linact=1;linact<=linie;linact++)
    {
        int linprezent=linact%2;
        int sumaopus=0;
        for(i=0;i<=coloana;i++)
        {
            sumaopus^=matr[(linprezent+1)%2][i];
            matr[linprezent][i]=sumaopus;
            while(linact==q[necesar].l&&i==q[necesar].c) q[necesar].rez=matr[linprezent][i],necesar++;
        }
    }
    sort(q.begin(),q.end(),cmp1);
    for(i=0;i<k;i++) g<<q[i].rez<<'\n';
    return 0;
}
