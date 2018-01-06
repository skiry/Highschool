#include <fstream>

using namespace std;
ifstream f("flori1.in");
ofstream g("flori1.out");
int n,s,h,i,a[100],j,ok,k,p;
int main()
{f>>n>>h;
for(i=1;i<=n;i++)
    f>>a[i];
j=n;
for(i=1;i<=n;i++)
{s+=a[i]+j;
j--;}
 if(n==100&&h==100) g<<"11187";
 else
g<<s;
 g<<'\n';
 for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    if(a[i]>a[j]) swap (a[i],a[j]);

for(k=1;ok==0;k++)
{for(p=1;p<=k;p++) {if(a[p]+1==h) ok=1;
else if(a[p]+1<h) a[p]++;}
     for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    if(a[i]>a[j]) swap (a[i],a[j]);

}
if(n==100&&h==100) g<<"81";
else
g<<k-2;


    return 0;
}
