#include <iostream>
using namespace std;
int a[11][11],n,m,i,j;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j) a[i][j]=max(i,j);
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
