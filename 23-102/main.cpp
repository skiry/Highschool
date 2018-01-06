#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,cmin=999,cmax,i,a[1000],j,cmax1,cmin1,ok;
int main()
{f>>n;
for(i=1;i<=n;i++) {f>>a[i];if(a[i]>cmax1){cmax1=a[i];cmax=i;}if(a[i]<cmin1){cmin1=a[i];cmin=i;}}
if(cmax-cmin==1||cmin-cmax==1) {g<<"Nu se efectueaza sortarea";ok=1;}
else
if(cmax>cmin){
for(i=cmin+1;i<cmax;i++)
for(j=i+1;j<cmax;j++) if(a[i]>a[j]) swap(a[i],a[j]);    }
else if(cmax<cmin)
{for(i=cmax+1;i<cmin;i++)
for(j=i+1;j<cmin;j++) if(a[i]>a[j]) swap(a[i],a[j]);

}if(!ok) for(i=1;i<=n;i++) g<<a[i]<<" ";

    return 0;
}
