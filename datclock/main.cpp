#include <fstream>
#include <string.h>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,i,n,k,d,y1,y2,x;
char a[100];
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>d>>k>>n;
        ///if(n>d) n%=d;
        /**if(k%2==0)
        {
            if(n%2==0)
            {
                l=((k+2+n*2)%(d/2))+1;
                r=((k+4+n*2)%(d/2))+1;
                g<<"Case #"<<i<<": "<<l<<" "<<r<<endl;
            }
            else if(n%2)
            {
                l=((k+2+n*2)%d)+1;
                r=((k+4+n*2)%d)+1;
                g<<"Case #"<<i<<": "<<l<<" "<<r<<endl;
            }
        }
        else if(k%2)
        {

                l=((k+n*2)%d)+1;
                r=((k-2+n*2)%d)+1;
                g<<"Case #"<<i<<": "<<l<<" "<<r<<endl;
        }*/
        if(k%2 == 1)
        {
            y1 = (k-1+n)%d + 2;
            if(y1 > d) y1 = 1;

            y2 = (k-1+n)%d;
            if(y2 < 1) y2 = d;

            y1 = 1 + (y1-1+n)%d;
            y2 = 1 + (y2-1+n)%d;
        }
        else
        {
            x = 1 + (d + (k-1-n)%d)%d;
            y1 = x + 1;
            if(y1 > d) y1 = 1;
            y2 = x - 1;
            if(y2 < 1) y2 = d;

            y1 = 1 + (d + (y1-1-n)%d)%d;
            y2 = 1 + (d + (y2-1-n)%d)%d;

        }
        g<<"Case #"<<i<<": "<<y1<<" "<<y2<<endl;
    }
    f.get(a,100);
    g<<a;
    return 0;
}
