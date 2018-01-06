#include <iostream>

using namespace std;
int n,p,i,j,a[21][21],nr;
int main()
{
    cin>>n>>p;
    for(i=1;i<=n;i++)
        for(j=1;j<=p;j++)
        a[i][j]=(++nr)*(nr++);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=p;j++)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
