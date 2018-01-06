#include <fstream>

using namespace std;
ifstream f("scara.in");
ofstream g("scara.out");
int n,x,y;
int main()
{
    f>>n;
    y=(n-1)/4;
    if(y%2==0) x=(n-1)%4+y;
        else x=3-(n-1)%4+y;
    g<<x<<" "<<y;
    return 0;
}
