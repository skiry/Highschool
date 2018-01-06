#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,i,n;
char a[27];
int main()
{
    f>>t;
    for(int u=1;u<=t;u++)
    {
        g<<"Case #"<<u<<": ";
        f>>n;
        f>>a;
        if(strlen(a)==1) g<<"IMPOSSIBLE";
        else
        {
            if(a[1] != a[0]) g<<a[1]<<a[0];
            else g<<a[0];
                for(char b='A';b<='Z';b++)
                    if(b!=a[1] && b !=a[0]) g<<b;
        }
        g<<endl;
    }
    return 0;
}
