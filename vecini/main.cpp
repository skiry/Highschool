#include <fstream>

using namespace std;
ifstream f("vecini.in");
ofstream g("vecini.out");
int n,a[100001],i,deplasare=1,r[100001];
int main()
{
    f>>n;
    n--;
    a[1]=1;
    for(i=1;i<=n;i<<=1)
        if(i&n)
        {
            for(int j=1;j<=deplasare;j++) a[j+deplasare]=a[j]+i;
            deplasare<<=1;
        }
    for(i=1;i<=deplasare;i++)
        g<<a[i]<<" ",r[a[i]]=1;g<<endl;
    for(i=1;i<=n+1;i++) g<<r[i]<<" ";
    return 0;
}
