#include <fstream>

using namespace std;
ifstream f("peisaj.in");
ofstream g("peisaj.out");
unsigned long long n,k,s,catalan,rk,nr=1,suma,i,j;
unsigned long long nifact;
int main()
{
    f>>n>>k;
    n/=2;
    for(i=1;i<=n;i++)
    {
        suma=1;nifact=1;
        for(j=1;j<=n-i;j++)
        {
            suma*=(i+j)*(i+j);
            nifact*=j*j;
        }
        nifact*=(n-i+1);
        suma*=i;
        suma/=(n*nifact);
        if(i==k) rk=suma;
        if(i>=k) s+=suma;
        catalan+=suma;
    }
    g<<catalan<<" "<<s<<" "<<rk;
    return 0;
}
