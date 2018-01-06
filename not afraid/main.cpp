#include <iostream>

using namespace std;
int n,m,k,el,viz[300000],local,global;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m&&!global;i++)
    {
        cin>>k;
        local=1;
        for(int j=1;j<=k&&local;j++)
        {
            cin>>el;
            viz[el]=i;
            if(viz[el*(-1)]==i) local=0;
        }
        if(local) global=1;
    }
    if(global) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    return 0;
}
