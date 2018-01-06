#include <iostream>

using namespace std;
int a[100],b[100],n,i,k,nr,j;
int main()
{cin>>n;
for(i=1;i<=n;i++) cin>>a[i];
k=a[1];
nr=n-1;
for(i=1;i<=n;i++)
{

    if(a[i]!=k) {j++;
        b[j]=a[i];
       nr--;}

}

for(j=1;j<=nr;j++) cout<<b[j]<<" ";

    return 0;
}
