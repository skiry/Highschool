#include <iostream>
using namespace std;
//ifstream cin("date.in");
//ofstream cout("date.out");
int n,i,a[100001][3],nr,el,maxim;
int main()
{
    cin>>n;
    for(i=1;i<=2*n;i++)
    {
        cin>>el;
        if(!a[el][1]) nr++,a[el][1]=1;
        else nr--;
        if(nr>maxim) maxim=nr;
    }
    cout<<maxim;
    return 0;
}
