#include <bits/stdc++.h>

using namespace std;
ifstream ki("date.in");
ofstream g("date.out");
long long a,b,f,k,c,d,dist,stops,fuel,actual,ok2=1;
int ok=0;
int main()
{
    ki>>a>>b>>f>>k;
    c=(a-f)*2;
    d=f*2;
    if(c>d&&c>b) ok=-1;
    else if(c<d&&d>b) ok=-1;
    else ok=1;
    if(ok==1)
    {
        if(k==1&&a-f>b-f) stops++;
        else{
        dist=f;
        fuel=b-f;
        actual=2;
        while(dist<a*k)
        {
            if(ok2==1)
            {
                if(((a*actual-f)-dist)>fuel&&a*actual-f<=a*k) stops++;
                fuel=b-((a*actual-f)-dist);
                dist=a*actual-f;
                ok2=0;
            }
            else if(ok2==0)
            {
                if(((a*actual+f)-dist)>fuel&&a*actual+f<=a*k) stops++;
                else if(a*k-dist>fuel) stops++;
                fuel=b-((a*actual+f)-dist);
                dist=a*actual+f;
                ok2=1;
                actual+=2;
            }
        }}
        g<<stops;
    }
    else g<<ok;

    return 0;
}
