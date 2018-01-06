#include <fstream>

using namespace std;
ifstream f("crescator1.in");
ofstream g("crescator1.out");
int n,nr;
long a,b;
int suma(long b)
{
    int s=0;
    long numar=b;
    while(numar)
        s+=numar%10,numar/=10;
    return s;
}
int main()
{
    f>>n;
    f>>b;
    nr=1;
    for(int i=2;i<=n;i++)
    {
        f>>a;
        int ok=0;
        if(a==b)
        {
            ok=1;
            nr++;
        }
        if(!ok)
        {
            if(a>b) b+=suma(b);
            if(a==b) nr++;
        }
    }
    g<<nr;
    return 0;
}
