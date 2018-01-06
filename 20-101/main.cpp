#include <iostream>

using namespace std;
int a[100],n,i,c,j;
int main()
{cin>>n;
while(n)
{a[n%10]++;
n=n/10;
}
    for(i=0;i<=8;i++)
    for(j=i+1;j<=9;j++)
     if(a[i]>a[j]) swap(a[i],a[j]);
    for(i=0;i<=9;i++)
 cout<<a[i]<<" "<<i<<endl;
    return 0;
}
