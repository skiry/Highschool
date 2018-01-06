#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,n,p,a,cw,hard;
int main()
{
    f>>t;
    for(int k=1;k<=t;k++)
    {
        f>>n>>p;
        cw=0;
        hard=0;
        for(int i=1;i<=n;i++)
        {
            f>>a;
            if(a>=p/2) cw++;
            else if(a<=p/10) hard++;
        }
        if(cw==1&&hard==2) g<<"yes";
        else g<<"no";
        g<<endl;
    }
    return 0;
}
