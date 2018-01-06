#include <iostream>

using namespace std;
long long n,m,nr,i,contor;
int main()
{
    cin>>n>>m;
    nr=m;
    i=n;
    contor=m+1;
    while(i>0)
    {
       i=i-contor;
       nr++;
       if(i>0) i+=m;
       contor++;
    }
    cout<<nr;
    return 0;
}
