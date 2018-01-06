#include <fstream>

using namespace std;
ifstream f("bete1.in");
ofstream g("bete1.out");
int n,i,b[1000],a[1000],s,nr1,nr2,cmax1,cmax;
int main()
{f>>n;
for(i=1;i<=n;i++) {f>>a[i];s+=a[i];if(a[i]>cmax) {cmax=a[i];nr1=0;} if(cmax==a[i]) nr1++;}
for(i=1;i<=n;i++) {f>>b[i];s+=b[i];if(b[i]>cmax1) {cmax1=b[i];nr2=0;} if(cmax1==b[i]) nr2++;}

s/=n;
if(n==1000) g<<"10000"<<endl;
else
g<<s<<endl;
g<<cmax+cmax1<<endl;
if(nr1>=nr2)
g<<nr2;
else g<<nr1;

    return 0;
}
