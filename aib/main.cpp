#include <fstream>
#define v(x) ( (-x)&x )
using namespace std;
ifstream f("aib.in");
ofstream g("aib.out");
int n,a[100001],i,m,op,b,c;
void update(int valoare,int poz)
{
    for(int i=poz;i<=n;i+=v(i)) a[i]+=valoare;
}
int query(int poz)
{
    int suma=0;
    for(int i=poz;i>0;i-=v(i)) suma+=a[i];
    return suma;
}
int verifica(int valoare)
{
    int suma=0;
    for(i=0;suma!=valoare;i++) suma+=a[i];
    return suma;
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
        update(a[i],i);
    }
    for(i=1;i<=m;i++)
    {
        f>>op;
        if(op==2)
        {
            f>>b;
            //g<<verifica(b)<<'\n';
        }
        else if(op==1)
        {
            f>>c>>b;
            g<<query(b)-query(c-1);
        }
        else
        {
            f>>c>>b;
            update(b,c);
        }
        g<<'\n';
    }
    return 0;
}
