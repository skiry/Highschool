#include <iostream>

using namespace std;
int a[100],n,i,b[10],nr,j;
int main()
{cin>>n;
for(i=1;i<=n;i++) cin>>a[i];
i=2;
while(i<=n)
{ if(a[i]%2==0) b[i-i/2]=a[i];
i=i+2;
nr++;
}
for(i=1;i<nr;i++)
    for(j=i+1;j<=nr;j++)
    if(b[i]>b[j]) swap(b[i],b[j]);

for(i=2;i<=n;i++)
    if(i%2==0) a[i]=b[i/2];
for(i=1;i<=n;i++) cout<<a[i]<<" ";




    return 0;
}
