#include <iostream>

using namespace std;
int a[100],n,i,j,aux,ok,k,nr;
int main()
{cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n&&ok==0;i++)
        {nr=0;
            if(a[i]==0) swap(a[i+1],a[i]);
        for(j=1;j<n;j++)
            for(k=j+1;k<=n;k++)
            if(a[j]<a[k]) nr++;
        if(nr==0) ok=1;}
        for(i=1;i<=n;i++) cout<<a[i]<<" ";



    return 0;
}
