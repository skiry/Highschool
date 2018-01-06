#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("jocul.in");
ofstream g("jocul.out");
int n,a[1001],s,i,D[50001],j;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i],s+=a[i];

    for(i=1;i<=n;i++)
        {
            for(j=s/2;j>=0;j--)
                {
                if(j>=a[i])
                D[j]=max(D[j],D[j-a[i]]+a[i]);
                }
        }
    g<<D[s/2]<<" "<<s-D[s/2];
    g<<endl;
    for(i=1;i<=s/2;i++)
        g<<D[i]<<" ";
    return 0;
}
