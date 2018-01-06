#include <fstream>
#include <math.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
unsigned long long x,y,z,ok,n;
int main()
{
    f>>n;
    for(z=2;z<=50;z++)
        for(x=2;x<=20;x++)
            for(y=2;y<=20;y++)

    {
        g<<pow(x,n)<<" + "<<pow(y,n)<<" = "<<pow(z,n);
        if(pow(x,n)+pow(y,n)==pow(z,n)) g<<" DA";
        g<<endl;
        if(pow(x,n)+pow(y,n)>pow(z,n)) x=y=2,z++;
    }
    return 0;
}
