#include <iostream>
using namespace std;
///element deasupra diagonalei pp : j>i
///element dedesubtul diagonalei pp : j<i
///element deasupra diagonalei sec : i+j<n+1
///element dedesubtul diagonalei sec : i+j>n+1
int a[17][17],n,m,i,j;
int main()
{
    cin>>n;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if(j>i&&i+j<n+1) a[i][j]=1;
            else if(j<i&&i+j>n+1) a[i][j]=2;
            else if(i!=j&&i+j!=n+1) a[i][j]=3;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
