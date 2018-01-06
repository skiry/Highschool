#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
unsigned long long nr,a,b;
unsigned long i;
int main()
{
    f>>a>>b;
    for(nr=1,i=(1<<31);i;i>>=1)
        {
            if(i&b) nr*=nr*a;
            else nr*=nr;
        }
    g<<nr;
    return 0;
}
