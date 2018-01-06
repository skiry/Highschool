#include <fstream>

using namespace std;
ifstream f("hanoi.in");
ofstream g("hanoi.out");
int n,m,nr;
void hanoi(int n,int a,int b,int c)
{
    if(n)
    {
        hanoi(n-1,a,c,b);
        g<<a<<" "<<b<<endl;nr++;
        hanoi(n-1,c,b,a);
    }
}
int main()
{
    f>>n>>m;
    hanoi(n,1,2,3);
    g<<nr;
    return 0;
}
