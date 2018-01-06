#include <fstream>
#include <math.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i;
int prime(int a)
{
    for(int d=2;d<=sqrt(a);d++)
        if(a%d==0) return 1;
    return 0;
}
int main()
{
    f>>n;
    for(i=1;i<=1000;i++)
    {
        if(prime(n*i+1)){
            g<<i;
            break;
        }
    }
    return 0;
}
