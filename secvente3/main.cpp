#include <fstream>

using namespace std;
ifstream f("secvente3.in");
ofstream g("secvente3.out");
int a,b,p,m,x,y,i,j,ok;
long long s,nr,c;
int main()
{
    f>>a>>b>>p>>m;
    for(i=1;i<=m;i++)
    {
        c=b;
        ok=1;
        nr=1;
        f>>x>>y;
        for(j=x-1;j;j>>=1)
        {
            if(j%2) nr*=c,nr%=p;
            c*=c,c%=p;
            //g<<"nr: "<<nr<<" c: "<<c<<endl;
        }
        nr*=a;
        nr%=p;
        s=nr;
        if(s==y) g<<x<<" ",ok=0;
        if(ok)
        {
            while(s<=y)
            {
                nr*=b;
                nr%=p;
                s+=nr;
                x++;
            }
            g<<x-1<<" ";
        }
    }
    return 0;
}
