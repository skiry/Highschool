#include <iostream>

using namespace std;
int n,i;
float a[100];
int main()
{cin>>n;
for(i=1;i<=n;i++) cin>>a[i];

for(i=1;i<=n;i++) if (a[i]>0) cout<<" "<<a[i]<<" ";
else cout<<"0.00"<<" "<<a[i]<<" ";


    return 0;
}
