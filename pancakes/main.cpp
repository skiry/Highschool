#include <fstream>
#include <string.h>
using namespace std;
ifstream f("pancakes.in");
ofstream g("pancakes.out");
int n,i,nr,ok;
char s[101];
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        ok=0;
        nr=0;
        f>>s;
        if(strlen(s)==1)
            {
                if(s[0] == '-')
                    g<<"Case #"<<i<<": 1"<<'\n';
                else if(s[0] == '+')
                    g<<"Case #"<<i<<": 0"<<'\n';
            }
        else if(strlen(s)!=1)
        {
            for(int j=strlen(s)-1;j>=0;j--)
            {
                if(ok == 0)
                {
                    if(s[j] == '-')
                    {
                        nr++;
                        ok=1;
                    }
                }
                else if(ok == 1)
                {
                    if(s[j] == '+')
                    {
                        nr++;
                        ok=0;
                    }
                }
            }
            g<<"Case #"<<i<<": "<<nr<<'\n';
        }
    }
    return 0;
}
