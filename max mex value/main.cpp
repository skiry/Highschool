#include <iostream>

using namespace std;
int t,n,k,x,a[20001],i;
int main()
{
    cin>>t;
    for(int u=1;u<=t;u++)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            a[x]=u;
        }
        i=0;
        while(a[i]==u) i++;
        while(k)
            {
                if(a[i]!=u) k--;
                i++;
                if(!k) while(a[i]==u) i++;
            }
        cout<<i<<endl;
    }
    return 0;
}
