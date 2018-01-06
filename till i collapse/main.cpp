#include <iostream>
#include <string.h>
using namespace std;
int n,nr,viz[100001],el,val1,dif,a[100001],nrcul[100001];
int main()
{
    cin>>n;
    val1=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1]) val1--;
        if(!viz[a[i]]++) dif++;
    }
    cout<<val1<<" ";
    for(int i=2;i<dif;i++)
    {
        int local=0,global=1;
        for(int j=1;j<=n;j++)
            if(nrcul[a[j]]!=global) {if(local==i) local=0,global++; nrcul[a[j]]=global,local++;}
        if(!local) global--;
        cout<<global<<" ";
        memset(nrcul,-1,100001);
    }
    for(int i=dif;i<=n;i++) cout<<"1 ";
    return 0;
}
