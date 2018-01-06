#include <bits/stdc++.h>

using namespace std;
int n,ok;
int f(int n)
{
    int a=n,nr=0;
    for(int i=2;i<=n/2;i++)
        while(a%i==0) a/=i,nr++;
    if(nr) return nr;
    return 1;
}
int main()
{
    cin>>n;
    int numar=n;
    do
    {
       int t=numar,p=1;
       while(t>9)
       {
           t/=10;
           p*=10;
       }
       numar-=t*p;
       numar*=10;
       numar+=t;
       if(f(numar)!=1) ok=1;
    }while(numar!=n);
    if(!ok) cout<<"Da";
    else cout<<"NU";
    return 0;
}
