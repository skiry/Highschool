#include <fstream>

using namespace std;
ifstream f("barfa.in");
ofstream g("barfa.out");
long long n,a,b,i;
int binar(int i)
{
    int a=0,k=1;
    while(i)
    {
        a+=(i%2)*k;
        k*=10;
        i/=2;
    }
    return a;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        if(i!=1)
            a=(a*i)%1000003,b=(b*i)%1000003;

    }
    for(i=1;i<=31;i++)
        g<<i<<" : "<<binar(i)<<endl;
    return 0;
}
