#include <fstream>

using namespace std;
ifstream f("conturi.in");
ofstream g("conturi.out");
int n,i,x,cmax,nr,a[103];
int main()
{f>>n>>x;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=n;i++)
if((a[i]/10000)%10==1&&(a[i]/100000)%10==x) {
    nr=0;
    nr=(((a[i]/1000)%10)*1000)+(((a[i]/100)%10)*100)+(((a[i]/10)%10)*10)+a[i]%10;
    if(nr>cmax) cmax=nr;
}
    g<<cmax;

    return 0;
}
