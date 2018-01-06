#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n;
unsigned long gr[50001],s=0,bit;
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
        f>>gr[i],s^=gr[i];
    for(bit=1<<31;bit;bit>>=1)
        if(bit&s) break;
    if(!bit) g<<"NU";
    else
    {
        g<<"DA"<<endl;
        for(int i=1;i<=n;i++)
            if(bit&gr[i])
            {
                g<<i<<" "<<gr[i]-(s^gr[i]);
                break;
            }
    }

    return 0;
}
