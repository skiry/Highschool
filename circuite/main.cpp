#include <fstream>

using namespace std;
ifstream f("circuite.in");
ofstream g("circuite.out");
int n,i,j;
unsigned long a[32];
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        int c;
        f>>c;
        if(c) a[i]|=(1<<(j&31));
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[j]&(1<<(i&31))) a[j]|=a[i];
    int ok=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i]&(1<<(j&31))==0) ok=1;
    if(!ok) g<<"DA"<<endl;
    else g<<"NU"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
                if(a[i]&1<<(j&31)) g<<"1 ";
        else g<<"0 ";
        g<<endl;}

    return 0;
}
