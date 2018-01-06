#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("sume4.in");
ofstream g("sume4.out");
int n,a,m,i,nr,s1,s2;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>nr;
        m=nr%100;
        a=nr/1000;
        s1+=a;
        s2+=m;
        if(a<m) s1+=(nr/100)%10;
        else if(a>m) s2+=(nr/100)%10;
    }
    g<<s1<<" "<<s2;

    return 0;
}
