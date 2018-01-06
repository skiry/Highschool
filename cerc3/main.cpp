#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <math.h>
using namespace std;
ifstream f("cerc3.in");
ofstream g("cerc3.out");
#define PI 3.141592653589793238462643383279
int n,x,y,r,i,j,ok,contor,maxx,nrc;
float b,c,valoarex,valoarey;
struct cerc
{
    int nr,maxim;
    float e,unghi;
};
cerc p;
vector <cerc> a;
struct cercuri
{
    float cx,cy,dx,dy;
};
cercuri k;
vector <cercuri> M[2000];
float unghi;
bool cmp(const cercuri &a,const cercuri &b)
{
    if(a.dx>b.dx) return a.dx<b.dx;
    if(a.dx==b.dx) return a.dy<b.dy;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y>>r;
        p.unghi=atan2(y,x)*180/PI; ///unghiul pe care il formeaza cu axa OX, atan2=arctg

        b=2*r*sin(p.unghi*PI/180);///cu teorema sinusului calculez deplasarea pe dreapta ///b e pe OX, c pe OY
        c=2*r*sin((90-p.unghi)*PI/180);
        if(x>y)
        {
            if(r>x)
            {
                k.cx=0;
                k.cy=0;
            }
            else
            {
                k.cx=x-(c/2);
                k.cy=y-(b/2);
            }
            k.dx=x+(c/2);
            k.dy=y+(b/2);
        }
        else
        {
            if(r>x)
            {
                k.cx=0;
                k.cy=0;
            }
            else
            {
                k.cx=x-(b/2);
                k.cy=y-(c/2);
            }
            k.dx=x+(b/2);
            k.dy=y+(c/2);
        }
        p.e=float(x)/(float)y; ///am pus (float) ca sa am p.e float, altfel era tot int
        ok=1;
        for(int j=0;j<a.size();j++)
            if(a[j].e==p.e)
        {
            a[j].nr++;
            ok=0;
            M[j].push_back(k);
            break;
        }
        if(ok)
        {
            p.nr=1;
            a.push_back(p);
            M[a.size()-1].push_back(k);
        }
    }
    int valafis=a.size();
    g<<valafis<<" "; ///numarul de muchii
    for(i=0;i<a.size();i++) ///parcurg fiecare dreapta
    {
        sort(M[i].begin(),M[i].end(),cmp); ///sortez dupa extremitatea din dreapta,dupa cum se termina cercul
        a[i].maxim=1;
        j=0;
            while(j<M[i].size())
            {
                valoarex=M[i][j].dx;
                valoarey=M[i][j].dy;
                while((M[i][j+1].cx<valoarex||M[i][j+1].cy<valoarey)&&j<M[i].size()) j++;
                j++;//,valoarex=M[i][j].dx,valoarey=M[i][j].dy;
                if(j<M[i].size())
                a[i].maxim++;
            }
        //g<<a[i].maxim<<endl;
        //g<<i<<" "<<a[i].maxim<<endl;
        if(a[i].maxim==maxx) nrc++;//,g<<i<<" "<<maxx<<endl;//,g<<i<<endl;
        if(a[i].maxim>maxx) maxx=a[i].maxim,nrc=1;//,g<<i<<" m "<<maxx<<endl;
        //for(j=0;j<M[i].size();j++) {if(M[i].size()>44) g<<M[i][j].cx<<" "<<M[i][j].cy<<" "<<M[i][j].dx<<" "<<M[i][j].dy<<endl;g<<endl<<endl<<"--------";}
    }
    g<<maxx<<" "<<nrc<<endl;
    return 0;
}
