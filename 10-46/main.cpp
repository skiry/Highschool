#include <iostream>

using namespace std;
int n,i,c,r,rf=0;
int main()
{cout<<"De cate ori faceti n(2n+1) ?";
cin>>n;
for (i=1;i<=n;i++)
{
    c=i;
    r=c*(2*c+1);
    rf=rf+r;
}
    cout << "Suma este egala cu " <<rf<< endl;
    return 0;
}
