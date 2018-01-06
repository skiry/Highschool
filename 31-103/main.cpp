#include <iostream>

using namespace std;
int a[100],n,i,j,ok,k;
int main()
{cin>>n;
for(i=1;i<=n;i++) cin>>a[i];
for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
if(a[i]>a[j]||a[i]==a[j]) {for(k=i;k<n;k++) a[k]=a[k+1];n--;}

for(i=1;i<=n;i++) cout<<a[i]<<" ";


    return 0;
}
