#include <iostream>

using namespace std;
long long a,b,nr=1;
int main()
{
    cin>>a>>b;
    while(b)
    {
        if(b&1) nr*=a;
        a*=a;
        b>>=1;
    }
    cout<<nr;
    return 0;
}
