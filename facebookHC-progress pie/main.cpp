#include <fstream>
#include <math.h>
#define R 50
#define PI 3.141592
using namespace std;

ifstream f("date.in");
ofstream g("date.out");
int t,i,x,y;
float p,unghi;
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>p>>x>>y;
        p=p/100*360;
        if((x-R)*(x-R)+(y-R)*(y-R)>=2500) g<<"Case #"<<i<<": white"<<endl;
        else
        {
            if(x>=50&&y>=50)
            {
                if(x==50) unghi=0;
                else if(y==50) unghi=90;
                else unghi=atan2(x-R,y-R)*180/PI;
                if(unghi<=p) g<<"Case #"<<i<<": black"<<endl;
                else g<<"Case #"<<i<<": white"<<endl;
            }
            if(x>=50&&y<=50)
            {
                if(x==50) unghi=180;
                else if(y==50) unghi=90;
                else unghi=atan2(x-R,y-R)*180/PI;
                if(unghi<=p) g<<"Case #"<<i<<": black"<<endl;
                else g<<"Case #"<<i<<": white"<<endl;
            }
            if(x<=50&&y<=50)
            {
                if(x==50) unghi=180;
                else if(y==50) unghi=270;
                else unghi=(atan2(y-R,x-R)*(-1))*180/PI+90;
                if(unghi<=p) g<<"Case #"<<i<<": black"<<endl;
                else g<<"Case #"<<i<<": white"<<endl;
            }
            if(x<=50&&y>=50)
            {
                if(x==50) unghi=360;
                else if(y==50) unghi=270;
                else unghi=360+(x-R,y-R)*180/PI;
                if(unghi<=p) g<<"Case #"<<i<<": black"<<endl;
                else g<<"Case #"<<i<<": white"<<endl;
            }
        }
    }
    return 0;
}
