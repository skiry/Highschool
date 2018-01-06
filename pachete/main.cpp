#include <fstream>

using namespace std;
ifstream f("pachete.in");
ofstream g("pachete.out");
int s,n,d[100],in[100],i;
int main()
{
    f>>n;
    for(i=1;i<=n;i++) f>>d[i]>>in[i];

    s=d[n];
    for(i=n-1;i>=1;i--)
        if(in[i]<d[i+1])
            s+=d[i]-in[i];
        else
            s=d[i];
    g<<s;
    return 0;
}
