#include <iostream>

using namespace std;
int x,a,b;
int main()
{
   cin>>a>>b;
   for(x=a;x>=b;x--) if(x%2) cout<<x<<" ";
    return 0;
}
