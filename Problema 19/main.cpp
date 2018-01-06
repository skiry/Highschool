#include <iostream>

using namespace std;
int a[25][25],n,i,j;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(i!=j) a[i][j]=n-j+1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
