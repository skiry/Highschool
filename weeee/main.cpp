#include <fstream>

using namespace std;
ifstream f("weeee.in");
ofstream g("weeee.out");
char c[200001];
int n,i,ok,lmax,maxim,nr;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>c[i];
        if(c[i]=='E') lmax++;
        else if(c[i]=='W') nr+=lmax,lmax=0;
        maxim=max(maxim,lmax);
    }
    if(c[n]=='E') nr+=lmax;
    nr-=maxim;
    if(c[1]=='E') nr++;
    g<<nr;
    return 0;
}
