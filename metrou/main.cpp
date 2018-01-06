#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("metrou.in");
ofstream g("metrou.out");
int n,m,sol[100001],i,j,x,y;
struct profit
{
    int v,in; ///v-valoare, in-initial
};
profit e;
inline bool cmp(const profit &a, const profit &b)
{
    return a.v>b.v;
}
vector <int> a[100001];
vector <profit> p;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>e.v,e.in=i,p.push_back(e);
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    sort(p.begin(),p.end(),cmp); ///daca nu merge asa; daca p[i]==p[j] sorteaza crescator dupa p[i]-E.p(vecini);
    for(i=0;i<n;i++) g<<p[i].v<<" "<<p[i].in<<endl;
    ///deque cu valorile maxime din fiecare 'culoare', si la fiecare nu caut tot vectorul sol,doar selectez din deque val maxima
    ///a unei culori ce nu o am in vecini;
    return 0;
}
