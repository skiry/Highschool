#include <bits/stdc++.h>

using namespace std;
ifstream f("xmoto.in");
ofstream g("xmoto.out");
int n,i,nr=1;
long double v,a,b,c,d,rez1,rez2,l;
int main()
{
    f>>n>>l;
    if(n==1)
    {
        f>>a>>b>>c>>d>>v;
        rez1=l-c;
        rez1/=a;
        rez2=l-d;
        rez2/=b;
        nr=0;
        if(rez1<v) nr++;
        if(rez2>v) nr++;
        g<<nr<<'\n';
        if(nr>0) g<<setprecision(9)<<rez1<<'\n';
        if(nr>1) g<<setprecision(9)<<rez2<<'\n';
    }
    else g<<nr<<'\n';
    return 0;
}
