#include <bits/stdc++.h>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int t,a,b,i,nrsch,unu,doi,acum;
struct activities
{
    int inc,sf,pers;
}act[501];
inline bool cmp (const activities &a,const activities &b)
{
    return a.inc<b.inc;
}
int main()
{
    f>>t;
    for(int k=1;k<=t;k++)
    {
        f>>a>>b;
        for(i=1;i<=a;i++) f>>act[i].inc>>act[i].sf,act[i].pers=1;
        for(i=a+1;i<=a+b;i++) f>>act[i].inc>>act[i].sf,act[i].pers=2;
        sort(act+1,act+a+b+1,cmp);
        unu=0;doi=0;
        nrsch=2;
        /**if(act[1].pers==1) acum=2,doi=act[1].sf;
        else acum=1,unu=act[2].sf;
        for(i=2;i<=a+b;i++)
        {
            if(act[i].pers==1)
            {
                if(acum==2)
                {
                    ++nrsch;
                    int retine=act[i].inc-act[i-1].sf;
                    int adauga=min(720-unu,retine);
                    if(adauga>0) unu+=adauga,doi+=retine-adauga;
                }
                doi+=act[i].sf-act[i].inc;
                acum=2;
            }
            else
            {
                if(acum==1)
                {
                    ++nrsch;
                    int retine=act[i].inc-act[i-1].sf;
                    int adauga=min(720-doi,retine);
                    if(adauga>0) doi+=adauga,unu+=retine-adauga;
                }
                unu+=act[i].sf-act[i].inc;
                acum=1;
            }
        }*/
        if(!b&&a==1)
                if(act[1].inc<=720&&act[1].sf>=720) nrsch=4;
        if(!a&&b==1)
                if(act[1].inc<=720&&act[1].sf>=720) nrsch=4;
        if(!a&&b==2)
            if(act[1].inc<=720&&act[2].sf>=720) nrsch=4;
        if(!b&&a==2)
            if(act[1].inc<=720&&act[2].sf>=720) nrsch=4;
        if(a&&b)
        {
            if(act[1].sf<=720&&act[2].inc>=720) nrsch=2;
            else nrsch=4;
        }
        g<<"Case #"<<k<<": "<<nrsch<<'\n';
    }
    return 0;
}
