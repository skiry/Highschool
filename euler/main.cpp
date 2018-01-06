#include <fstream>

using namespace std;
ifstream f("euler.in");
ofstream g("euler.out");
int t[270000],viz[270000],ant,a,n,i,ap[270000],s,dif,nr=1,ok;
int main()
{
    f>>n;
    f>>a;
    t[a]=0;
    viz[a]=1;
    ant=a;
    while(f>>a)
    {
        nr++;
        if(!viz[a]) t[a]=ant,viz[a]=1,ap[ant]++;
        if(a==ant) ok=1;
        ant=a;
    }
    for(i=1;i<=n;i++) if(ap[i]) s+=ap[i]+1;
                else dif++;
    s+=dif;
    if(s==nr&&!ok)
    {
        g<<"DA"<<'\n';
        for(i=1;i<=n;i++) g<<t[i]<<" ";
    }
    else g<<"NU";
    return 0;
}
