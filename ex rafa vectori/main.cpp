#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[100],b[100],c[100],nr,q=1,cmax=999,ok,h,n,i,j;
int main()
{f>>n;
    for(i=1;i<=n;i++) {f>>a[i];c[i]=a[i];}
  //punctul c
    for(i=1;i<=n;i++)
    {nr=0;
        while(c[i])
    {h=c[i]%10;
    c[i]=c[i]/10;
    nr=nr*10+h;
    }if(a[i]==nr) {b[q]=a[i];q++;}
 }
 for(i=1;i<q;i++) g<<b[i]<<" ";
 g<<endl;
 //punctul d
 for(i=1;i<=n;i++) if(a[i]%2&&a[i]<=cmax) cmax=a[i];
 g<<cmax;
 //punctul e
 g<<endl;
 for(i=1;i<=n&&ok==0;i++)
 if(a[i]%2==0) {for(j=i;j<n;j++) swap(a[j],a[j+1]); ok=1;n--;}
 for(i=1;i<=n;i++) g<<a[i]<<" ";
    return 0;
}
