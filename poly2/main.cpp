#include <fstream>
#define M 30103
using namespace std;
ifstream f("poly2.in");
ofstream g("poly2.out");
int n,nr=1,k,nk;
int i(int a)
{
    int b=M,x=0,y=0,z=1,r,c;
    while(a)
    {
        r=b%a;
        c=b/a;
        b=a;
        a=r;
        x=y-c*z;
        y=z;
        z=x;
    }
    while(y<0) y+=M;
    return y;
}
int main()
{
    f>>n;
    for(int k=2;k<=n;k++) nr*=k,nr%=M;
    nk=nr;
    nr=1;
    for(k=n+1;k<=2*n;k++) nr*=k,nr%=M;
    k=nr;
    g<<(k*i(nk))%M*i(n+1)%M;
    return 0;
}
