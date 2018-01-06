#include <fstream>

using namespace std;
ifstream f("inversmodular.in");
ofstream g("inversmodular.out");
long long a,b,x,y,z,r,c,initial;
int main()
{
    f>>a>>b;
    initial=b;
    z=1;
    while(a)
    {
        r=b%a;///rest
        c=b/a;///cat
        b=a;
        a=r;
        x=y-c*z;
        y=z;
        z=x;
    }
    while(y<0) y+=initial;
    g<<y;
    return 0;
}
