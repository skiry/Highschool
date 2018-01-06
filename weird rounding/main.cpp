#include <iostream>
#include <math.h>
using namespace std;
long long a,b;
int k,nr,i;
int main()
{
    cin>>a>>k;
    b=pow(10,k);
    if(!a) cout<<"0";
    else{
    if(a<b)
    {
        while(a) a/=10,nr++;
        nr--;
    }
    else{
    for(i=1;i<=k;i++)
    {
        if(a%10) nr++,i--;
        a/=10;
    }
    }
    cout<<nr;}
    return 0;
}
