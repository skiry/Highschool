#include <iostream>

using namespace std;
int n,a[25][25],i,j,s;
int main()
{
    cin>>n;
    s=n;
    for(i=1;i<=n;i++,s--)
        for(j=1;j<=n;j++)
            if(i+j!=n+1) a[i][j]=s;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
