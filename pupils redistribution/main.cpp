#include <iostream>

using namespace std;
struct numar
{
    int v,nr;
};
numar a[101],b[101];
int n,i,j,s,ok;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i].v,a[a[i].v].nr++;
    for(i=1;i<=n;i++) cin>>b[i].v,b[b[i].v].nr++;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(a[a[i].v].nr>b[a[i].v].nr&&b[b[j].v].nr>a[b[j].v].nr) {
                a[a[i].v].nr--;
                a[b[j].v].nr++;
                b[b[j].v].nr--;
                b[a[i].v].nr++;
        swap(a[i].v,b[j].v),s++;
        }
    for(i=1;i<=5;i++) if(a[i].nr!=b[i].nr) ok=1;
    if(!ok) cout<<s;
    else cout<<"-1";
    return 0;
}
