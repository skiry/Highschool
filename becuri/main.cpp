#include <fstream>

using namespace std;
ifstream f("becuri2.in");
ofstream g("becuri2.out");
int n,i,p=1,nrr1,c,nrr2,a[100],b[100]
long long a,b,e,d,nr1,nr2;
int main()
{f>>n>>a>>b;
e=a;d=b;
while(e)
{c=e%2;
e/=2;
nr1+=p*c;
p*=10;
nrr1++;
}
p=1;
while(d)
{c=d%2;
d/=2;
nr2+=p*c;
p*=10;
nrr2++;
}
g<<nr1<<" "<<nr2;

    return 0;
}
