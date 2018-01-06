#include <fstream>
#include <stdio.h>
using namespace std;
ifstream f("avarcolaci.in");
ofstream g("avarcolaci.out");
unsigned int n,x,t,i,j,v[500001],val[500001],p,ok;
char s;
int cauta(int nr)
{
    for(int k=1;k<=p;k++)
        if(v[k]==nr) return k;
    return 0;
}
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>n;
        p=0;ok=0;
        for(j=1;j<=2*n;j++)
        {
            f>>x;
            if(!ok)
            {int valoare=cauta(x);
            if(!valoare)
            {
                v[++p]=x;
                val[p]=1;
            }
            else val[valoare]++;
            if(val[valoare]>n) {g<<v[valoare]<<'\n';ok=1;}}
        if(j==2*n&&!ok) g<<"Mozart"<<'\n';
        }
    }
    return 0;
}
