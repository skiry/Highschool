#include <fstream>

using namespace std;
ifstream f("bitsort.in");
ofstream g("bitsort.out");
char a[10001];
int n,nr;
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        f>>nr,a[nr>>3]|=(1<<(nr&7));
    for(int i=0;i<10001;i++)
        if(a[i>>3]&(1<<(i&7))) g<<i<<" ";
    return 0;
}
