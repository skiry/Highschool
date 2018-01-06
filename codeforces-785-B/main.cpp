#include <iostream>

using namespace std;
unsigned long long n,m,minim=3000000000,maxim,i,x,y;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(y<minim) minim=y;
    }
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(x>maxim) maxim=x;
    }
    if(maxim>minim) cout<<maxim-minim;
    else cout<<"0";
    return 0;
}
