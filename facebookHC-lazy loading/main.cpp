#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,n,a[101],i,k,j,nr,nr1;
int main()
{
    f>>t;
    for(k=1;k<=t;k++)
    {
        nr=0;
        f>>n;
        for(i=1;i<=n;i++)
            f>>a[i];
        sort(a,a+n+1);
        for(i=n;i>=1;i--)
        {
            nr1=1;
            if(a[i]>=50) nr++,a[i]=0;
            else if(a[i]<50)
            {
                for(j=1;j<i;j++)
                    if(a[j])
                {
                    nr1++;
                    a[j]=0;
                    if(a[i]*nr1>=50)
                    {
                        nr++;
                        break;
                    }
                }
            }
        }
        g<<"Case #"<<k<<": "<<nr<<endl;
    }
    return 0;
}
