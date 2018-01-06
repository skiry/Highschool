#include <iostream>

using namespace std;
int main()
{
    double t1,k1,t2,k2;
    double rez,rez1,rez2;
    cin>>t1>>k1>>t2>>k2;
    rez1=t1/k1;
    rez2=t2/k2;
    rez=rez1*rez2;
    rez/=rez1+rez2;
    cout<<rez;
    return 0;
}
