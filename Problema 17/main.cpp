#include <fstream>
#include <iostream>
using namespace std;
ofstream g("NR.TXT");
int n;
int main()
{
    cin>>n;
    while(n)
    {
        g<<n<<" ";
        n/=10;
    }
    return 0;
}
