#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a,b,c;
int minim(int a,int b,int c)
{
    if(a<=b&&a<=c) return a;
    if(b<=a&&b<=c) return b;
    if(c<=a&&c<=b) return c;
}
int main()
{
    f>>a>>b>>c;
    b=b/2;
    c=c/4;
    g<<minim(a,b,c)*7;
    return 0;
}
