#include <iostream>

using namespace std;
//ifstream cin("date.in");
//ofstream cout("date.out");
int a,b,c,d,ok;
short int viz[90000000];
int main()
{
    cin>>a>>b>>c>>d;
    if((((b%2&&a%2==0)&&(d%2==0&&c%2==0)))||(d%2&&c%2==0)&&(a%2==0&&b%2==0)) cout<<"-1";
    else
    {
        while(!ok)
        {
            viz[b]++;
            viz[d]++;
            if(viz[b]>1) {cout<<b;ok=1;}
            if(viz[d]>1&&!ok) {cout<<d;ok=1;}
            b+=a;
            d+=c;
        }
    }
    return 0;
}
