#include <fstream>

using namespace std;
ifstream f("carte1.in");
ofstream g("carte1.out");
int n,a[10006],p,i,j=1,ok,nr=1,cmax,z,nr1;
int main()
{f>>n;
for(i=1;i<=n;i++) f>>a[i];
    for(p=1;j<=n;p++)
    {nr1=0;
    for(i=1;i<=n;i++)
    if(a[i]==j) {j++;nr1++;}
     if(nr1>cmax) {cmax=nr1;z=nr;}
     nr++;

    }
g<<nr-1<<" "<<z<<" "<<cmax;
    return 0;
}
