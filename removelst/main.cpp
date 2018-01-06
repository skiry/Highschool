#include <iostream>

using namespace std;
long long n,initial;
long long a,b,nr;
int main()
{
    cin>>a>>b>>n;long long initial=1;
    cout<<a+b<<" ";
    do
    {
        initial<<=1;
    }while(initial<n);
    long long rez=((initial>>1)+1)*a+b;
    cout<<rez;
    return 0;
}
