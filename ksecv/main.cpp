#include <fstream>

using namespace std;
ifstream f("ksecv.in");
ofstream g("ksecv.out");
int n,m,k,i,a[101],b[101],s[101],rez[101][51];
int main()
{
    f>>n>>k>>m;
    for(i=0;i<m;i++) f>>a[i];
    for(i=0;i<m;i++) f>>b[i];
    for(i=0;i<n;i++) s[i]=(a[i%m]^b[i/m]);
    for(i=0;i<n;i++) g<<s[i]<<" ";
    return 0;
}
