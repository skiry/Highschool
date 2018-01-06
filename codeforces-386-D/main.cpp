#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,k,a,b,i;
int main()
{
    f>>n>>k>>a>>b;
    if(a==0&&b>k) g<<"NO";
    if(b==0&&a>k) g<<"NO";
    while(a>0&&b>0)
    {
        if(a/k!=b/k)
    {
        if(a<b)
        {
            for(i=1;i<=k;i++)
                g<<"B";
            b-=k;
                g<<"G";
        }
        if(b<a)
        {
            for(i=1;i<=k;i++)
                g<<"G";
            a-=k;
                g<<"B";
        }
    }
    }
    return 0;
}
