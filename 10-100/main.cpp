#include <iostream>

using namespace std;
int a[100],n,i;
int main()
{cin>>n;
for(i=1;i<=n;i++) cin>>a[i];



for(i=1;i<=n-1;i++)
if(a[i])   {if(a[i]<a[i+1]) {swap(a[i],a[i+1]); ok=0;}}
    }


for(i=1;i<=n;i++) cout<<a[i];





    return 0;
}
