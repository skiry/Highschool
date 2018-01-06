#include <fstream>
#include <cmath>
using namespace std;
ifstream f("distanta.in");
ofstream g("distanta.out");
int n,i,j,maxx;
struct punct
{
    int x,y,z;
}p[100001];
int dif(int i,int j)
{
    return abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)+abs(p[i].z-p[j].z);
}
int main()
{
    ios_base::sync_with_stdio(false);
    f>>n;
    for(i=1;i<=n;i++)
        f>>p[i].x>>p[i].y>>p[i].z;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
        maxx=max(maxx,dif(i,j));
    g<<maxx;
    return 0;
}
