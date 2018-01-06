#include <bits/stdc++.h>

using namespace std;
long long n,el,rez,i,j,a[1000001];
char c;
int main()
{
    cin>>c;
    cout<<((int)c);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        for(j=1;j<=i;j++) rez^=(a[j]+a[i]);
    }
    cout<<rez;
    return 0;
}
