#include <fstream>

using namespace std;
ifstream f("doitrei.in");
ofstream g("doitrei.out");
long long s=2,r;
int a,i;
int main()
{f>>a;
   for(i=1;i<=a-1;i++) s=(s*10)+3;
   r=s*s;
   g<<r;
    return 0;
}
