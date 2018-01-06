#include <iostream>

using namespace std;
int a[100],n,i,j,nr;
int main()
{cin>>n;
for(i=1;i<=n;i++) cin>>a[i];
   for(i=1;i<=n-1;i++)
    for(j=i+1;j<=n;j++)
   if(a[i]>a[j]) {cout<<a[i]<<" "<<a[j]<<endl;nr++;}
   cout<<nr;
   return 0;
}
