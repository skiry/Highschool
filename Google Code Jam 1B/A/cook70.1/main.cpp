#include <iostream>

using namespace std;
int n,a,i,nr;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a,nr+=a;
    cout<<(nr+1)/2;
    return 0;
}
