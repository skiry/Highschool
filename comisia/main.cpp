#include <fstream>

using namespace std;
ifstream f("comisia.in");
ofstream g("comisia.out");
int n,i,j,a[200000];
unsigned long long b[200000],minim=999999999999;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
    {
        int j1=0,j2=0;

        if(i-a[i]+1>=1) j1=i-a[i]+1;
        else j1=1;
        if(i+a[i]-1<=n) j2=i+a[i]-1;
        else j2=n;

        for(j1;j1<=j2-a[i]+1;j1++)
        {g<<"x ";
            unsigned long long s=0;
            for(int j=j1;j<=j1+a[i];j++)
            {
                s+=b[j];
            }
            if(s<minim) minim=s;
        }
    }
    g<<minim;
    return 0;
}
