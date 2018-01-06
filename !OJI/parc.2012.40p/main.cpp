#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
ifstream f("parc.in");
ofstream g("parc.out");
int n,m,xp,yp,xs,ys,x,y,i,j,a,b,difx,dify,dif1,dif2,plecare,sosire;
float rez;
int main()
{
    f>>n>>m;
    f>>xp>>yp>>xs>>ys;
    f>>x;
    difx=abs(xp-xs);
    dif1=difx;
    dify=abs(yp-ys);
    dif2=dify;
    plecare=min(xp,xs);
    sosire=max(xp,xs);
    for(i=1;i<=x;i++)
    {
        f>>a>>b;
        int c=b;
        b=max(a,b);
        a=min(a,c);
        if(a<plecare)
            {
                if(b>=plecare&&b<=sosire)
                    difx-=b-plecare;
                else if(b>sosire)
                    difx=0;
            }
        else if(a>=plecare&&a<=sosire)
            {
                if(b<=sosire)
                    difx-=b-a;
                else if(b>sosire)
                    difx-=sosire-a;
            }
    }
    f>>y;
    plecare=min(yp,ys);
    sosire=max(yp,ys);
    for(i=1;i<=y;i++)
    {
        f>>a>>b;
        int c=b;
        b=max(a,b);
        a=min(a,c);
        if(a<plecare)
            {
                if(b>=plecare&&b<=sosire)
                    dify-=b-plecare;
                else if(b>sosire)
                    dify=0;
            }
        else if(a>=plecare&&a<=sosire)
            {
                if(b<=sosire)
                    dify-=b-a;
                else if(b>sosire)
                    dify-=sosire-a;
            }
    }
    rez=dif1-difx+dif2-dify+sqrt((difx*difx)+(dify*dify));
    g<<fixed<<setprecision(6)<<rez;
    return 0;
}
