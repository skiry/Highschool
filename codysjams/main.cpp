#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int a[201],n,t,i,c,l;
unsigned long long x;
int main()
{
    f>>t;
    for(int u=1;u<=t;u++)
    {
        g<<"Case #"<<u<<": ";
        f>>n;
        f>>x;
        c=l=1;
        a[c]=(x/3)*4;
        c++;
        for(i=2;i<=2*n;i++)
        {
            f>>x;
            if(x==a[l]) g<<x-x/4<<" ",l++;
            else
            {
                a[c]=(x/3)*4;
                c++;
            }

        }
        g<<endl;
    }
    return 0;
}
