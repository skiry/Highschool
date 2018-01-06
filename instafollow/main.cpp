#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
char c,d;
int i;
int main()
{
    while(f>>c)
    {
        if(c=='>')
        {
            f>>d;
            if(d>='a'&&d<='z')
            {
                while(d!='<')
                {
                    g<<d;
                    f>>d;
                }
                g<<endl;i++;
            }
        }
    }
    g<<i;
    return 0;
}
