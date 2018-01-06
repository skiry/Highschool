#include <fstream>
#include <vector>
using namespace std;
ifstream f("costuri.in");
ofstream g("costuri.out");
int n,q,i,j,a,b;
vector <int> v[60000];
int cost(int a)
{
    int nr=a,p=1;
    if(a==0) return 0;
    while(nr)
    {
        p*=nr%10;
        nr/=10;
    }
    return p;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a;
        v[cost(a)].push_back(a);
    }
    f>>q;
    for(i=1;i<=q;i++)
    {
        f>>a>>b;
        if(v[b].size()<a) g<<"-1"<<endl;
        else g<<v[b][a-1]<<endl;
    }
    return 0;
}
