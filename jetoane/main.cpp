#include <fstream>

using namespace std;
ifstream f("jetoane.in");
ofstream g("jetoane.out");
int a=1,s,i,s1,c,b,n,nr;
int main()
{f>>s>>b;
for(i=1;i<=b;i++)
    a*=10;
for(i=1;i<=a;i++)
{s1=0;n=i;
while(n)
{c=n%10;
n=n/10;
s1+=c;}
if (s==s1) nr++;

}
g<<nr;

    return 0;
}
