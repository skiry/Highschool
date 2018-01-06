#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,suma,i,el,bit,a[50001];
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
        suma^=a[i];
    }
    for(i<<=31;i;i>>=1)
        if(i&suma) bit=i,i=0;
    if(bit)
    {
        g<<"DA"<<'\n';
        for(i=1;i<=n;i++)
            if(a[i]&bit)
        {
            g<<i<<" "<<2*a[i]-suma;
            break;
        }
    }
    else g<<"NU";
    return 0;
}
