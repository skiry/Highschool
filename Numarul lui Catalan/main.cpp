#include <fstream>
#define MOD 666013
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a,i,nr=1,n,k,catalan;
int inversmodular(int a)
{
    int b=MOD,r,c,x=0,y=0,z=1;
    while(a)
    {
        r=b%a;
        c=b/a;
        b=a;
        a=r;
        x=y-c*z;
        y=z;
        z=c;
    }
    while(y<0) y+=MOD;
    return y;
}
int main()
{
    f>>a;
    for(i=1;i<=a;i++) nr*=i;
    n=nr;
    nr=1;
    for(i=a+1;i<=2*a;i++) nr*=i;
    k=nr;
    catalan=k*inversmodular(n)*inversmodular(a+1);
    g<<catalan;
    ///g<<endl<<k/(n*(a+1));
    return 0;
}
