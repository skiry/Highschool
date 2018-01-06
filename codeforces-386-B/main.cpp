#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i;
char a[2001],b[2001];
int main()
{
    f>>n;
    f.get();
    f.getline(a,n+1);
    for(i=strlen(a)-2;i>=0;i--)
        {
            g<<a[i];
            if(i>1) i--;
            else break;
        }

    if(i<=0)
        for(i=1;i<strlen(a);i+=2)
            g<<a[i];
    else
        for(i=0;i<strlen(a);i+=2)
        g<<a[i];
    return 0;
}
